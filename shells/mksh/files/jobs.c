/*	$OpenBSD: jobs.c,v 1.43 2015/09/10 22:48:58 nicm Exp $	*/

/*-
 * Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2011,
 *		 2012, 2013, 2014, 2015, 2016, 2018, 2019
 *	mirabilos <m@mirbsd.org>
 *
 * Provided that these terms and disclaimer and all copyright notices
 * are retained or reproduced in an accompanying document, permission
 * is granted to deal in this work without restriction, including un-
 * limited rights to use, publicly perform, distribute, sell, modify,
 * merge, give away, or sublicence.
 *
 * This work is provided "AS IS" and WITHOUT WARRANTY of any kind, to
 * the utmost extent permitted by applicable law, neither express nor
 * implied; without malicious intent or gross negligence. In no event
 * may a licensor, author or contributor be held liable for indirect,
 * direct, other damage, loss, or other issues arising in any way out
 * of dealing in the work, even if advised of the possibility of such
 * damage or existence of a defect, except proven that it results out
 * of said person's immediate fault when using the work as intended.
 */

#include "sh.h"

__RCSID("$MirOS: src/bin/mksh/jobs.c,v 1.128 2019/12/11 19:46:20 tg Exp $");

#if HAVE_KILLPG
#define mksh_killpg		killpg
#else
/* cross fingers and hope kill is killpg-endowed */
#define mksh_killpg(p,s)	kill(-(p), (s))
#endif

/* Order important! */
#define PRUNNING	0
#define PEXITED		1
#define PSIGNALLED	2
#define PSTOPPED	3

typedef struct proc Proc;
/* to take alignment into consideration */
struct proc_dummy {
	Proc *next;
	pid_t pid;
	int state;
	int status;
	char command[128];
};
/* real structure */
struct proc {
	/* next process in pipeline (if any) */
	Proc *next;
	/* process id of this Unix process in the job */
	pid_t pid;
	/* one of the four P… above */
	int state;
	/* wait status */
	int status;
	/* process command string from vistree */
	char command[256 - (ALLOC_OVERHEAD +
	    offsetof(struct proc_dummy, command[0]))];
};

/* Notify/print flag - j_print() argument */
#define JP_SHORT	1	/* print signals processes were killed by */
#define JP_MEDIUM	2	/* print [job-num] -/+ command */
#define JP_LONG		3	/* print [job-num] -/+ pid command */
#define JP_PGRP		4	/* print pgrp */

/* put_job() flags */
#define PJ_ON_FRONT	0	/* at very front */
#define PJ_PAST_STOPPED	1	/* just past any stopped jobs */

/* Job.flags values */
#define JF_STARTED	0x001	/* set when all processes in job are started */
#define JF_WAITING	0x002	/* set if j_waitj() is waiting on job */
#define JF_W_ASYNCNOTIFY 0x004	/* set if waiting and async notification ok */
#define JF_XXCOM	0x008	/* set for $(command) jobs */
#define JF_FG		0x010	/* running in foreground (also has tty pgrp) */
#define JF_SAVEDTTY	0x020	/* j->ttystat is valid */
#define JF_CHANGED	0x040	/* process has changed state */
#define JF_KNOWN	0x080	/* $! referenced */
#define JF_ZOMBIE	0x100	/* known, unwaited process */
#define JF_REMOVE	0x200	/* flagged for removal (j_jobs()/j_noityf()) */
#define JF_USETTYMODE	0x400	/* tty mode saved if process exits normally */
#define JF_SAVEDTTYPGRP	0x800	/* j->saved_ttypgrp is valid */

typedef struct job Job;
struct job {
	ALLOC_ITEM alloc_INT;	/* internal, do not touch */
	Job *next;		/* next job in list */
	Proc *proc_list;	/* process list */
	Proc *last_proc;	/* last process in list */
	struct timeval systime;	/* system time used by job */
	struct timeval usrtime;	/* user time used by job */
	pid_t pgrp;		/* process group of job */
	pid_t ppid;		/* pid of process that forked job */
	int job;		/* job number: %n */
	int flags;		/* see JF_* */
	volatile int state;	/* job state */
	int status;		/* exit status of last process */
	int age;		/* number of jobs started */
	Coproc_id coproc_id;	/* 0 or id of coprocess output pipe */
#ifndef MKSH_UNEMPLOYED
	mksh_ttyst ttystat;	/* saved tty state for stopped jobs */
	pid_t saved_ttypgrp;	/* saved tty process group for stopped jobs */
#endif
};

/* Flags for j_waitj() */
#define JW_NONE		0x00
#define JW_INTERRUPT	0x01	/* ^C will stop the wait */
#define JW_ASYNCNOTIFY	0x02	/* asynchronous notification during wait ok */
#define JW_STOPPEDWAIT	0x04	/* wait even if job stopped */
#define JW_PIPEST	0x08	/* want PIPESTATUS */

/* Error codes for j_lookup() */
#define JL_NOSUCH	0	/* no such job */
#define JL_AMBIG	1	/* %foo or %?foo is ambiguous */
#define JL_INVALID	2	/* non-pid, non-% job id */

static const char * const lookup_msgs[] = {
	"no such job",
	"ambiguous",
	"argument must be %job or process id"
};

static Job *job_list;		/* job list */
static Job *last_job;
static Job *async_job;
static pid_t async_pid;

static int nzombie;		/* # of zombies owned by this process */
static int njobs;		/* # of jobs started */

#ifndef CHILD_MAX
#define CHILD_MAX	25
#endif

#ifndef MKSH_NOPROSPECTOFWORK
/* held_sigchld is set if sigchld occurs before a job is completely started */
static volatile sig_atomic_t held_sigchld;
#endif

#ifndef MKSH_UNEMPLOYED
static struct shf	*shl_j;
static bool		ttypgrp_ok;	/* set if can use tty pgrps */
static pid_t		restore_ttypgrp = -1;
static int const	tt_sigs[] = { SIGTSTP, SIGTTIN, SIGTTOU };
#endif

static void		j_set_async(Job *);
static void		j_startjob(Job *);
static int		j_waitj(Job *, int, const char *);
static void		j_sigchld(int);
static void		j_print(Job *, int, struct shf *);
static Job		*j_lookup(const char *, int *);
static Job		*new_job(void);
static Proc		*new_proc(void);
static void		check_job(Job *);
static void		put_job(Job *, int);
static void		remove_job(Job *, const char *);
static int		kill_job(Job *, int);

static void tty_init_talking(void);
static void tty_init_state(void);

/* initialise job control */
void
j_init(void)
{
#ifndef MKSH_NOPROSPECTOFWORK
	(void)sigemptyset(&sm_default);
	sigprocmask(SIG_SETMASK, &sm_default, NULL);

	(void)sigemptyset(&sm_sigchld);
	(void)sigaddset(&sm_sigchld, SIGCHLD);

	setsig(&sigtraps[SIGCHLD], j_sigchld,
	    SS_RESTORE_ORIG|SS_FORCE|SS_SHTRAP);
#else
	/* Make sure SIGCHLD isn't ignored - can do odd things under SYSV */
	setsig(&sigtraps[SIGCHLD], SIG_DFL, SS_RESTORE_ORIG|SS_FORCE);
#endif

#ifndef MKSH_UNEMPLOYED
	if (Flag(FMONITOR) == 127)
		Flag(FMONITOR) = Flag(FTALKING);

	/*
	 * shl_j is used to do asynchronous notification (used in
	 * an interrupt handler, so need a distinct shf)
	 */
	shl_j = shf_fdopen(2, SHF_WR, NULL);

	if (Flag(FMONITOR) || Flag(FTALKING)) {
		int i;

		/*
		 * the TF_SHELL_USES test is a kludge that lets us know if
		 * if the signals have been changed by the shell.
		 */
		for (i = NELEM(tt_sigs); --i >= 0; ) {
			sigtraps[tt_sigs[i]].flags |= TF_SHELL_USES;
			/* j_change() sets this to SS_RESTORE_DFL if FMONITOR */
			setsig(&sigtraps[tt_sigs[i]], SIG_IGN,
			    SS_RESTORE_IGN|SS_FORCE);
		}
	}

	/* j_change() calls tty_init_talking() and tty_init_state() */
	if (Flag(FMONITOR))
		j_change();
	else
#endif
	  if (Flag(FTALKING)) {
		tty_init_talking();
		tty_init_state();
	}
}

static int
proc_errorlevel(Proc *p)
{
	switch (p->state) {
	case PEXITED:
		return ((WEXITSTATUS(p->status)) & 255);
	case PSIGNALLED:
		return (ksh_sigmask(WTERMSIG(p->status)));
	default:
		return (0);
	}
}

#if !defined(MKSH_UNEMPLOYED) && HAVE_GETSID
/* suspend the shell */
void
j_suspend(void)
{
	struct sigaction sa, osa;

	/* Restore tty and pgrp. */
	if (ttypgrp_ok) {
		if (tty_hasstate)
			mksh_tcset(tty_fd, &tty_state);
		if (restore_ttypgrp >= 0) {
			if (tcsetpgrp(tty_fd, restore_ttypgrp) < 0) {
				warningf(false, Tf_ssfaileds,
				    Tj_suspend, "tcsetpgrp", cstrerror(errno));
			} else if (setpgid(0, restore_ttypgrp) < 0) {
				warningf(false, Tf_ssfaileds,
				    Tj_suspend, "setpgid", cstrerror(errno));
			}
		}
	}

	/* Suspend the shell. */
	memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_DFL;
	sigaction(SIGTSTP, &sa, &osa);
	kill(0, SIGTSTP);

	/* Back from suspend, reset signals, pgrp and tty. */
	sigaction(SIGTSTP, &osa, NULL);
	if (ttypgrp_ok) {
		if (restore_ttypgrp >= 0) {
			if (setpgid(0, kshpid) < 0) {
				warningf(false, Tf_ssfaileds,
				    Tj_suspend, "setpgid", cstrerror(errno));
				ttypgrp_ok = false;
			} else if (tcsetpgrp(tty_fd, kshpid) < 0) {
				warningf(false, Tf_ssfaileds,
				    Tj_suspend, "tcsetpgrp", cstrerror(errno));
				ttypgrp_ok = false;
			}
		}
		tty_init_state();
	}
}
#endif

/* job cleanup before shell exit */
void
j_exit(void)
{
	/* kill stopped, and possibly running, jobs */
	Job *j;
	bool killed = false;

	for (j = job_list; j != NULL; j = j->next) {
		if (j->ppid == procpid &&
		    (j->state == PSTOPPED ||
		    (j->state == PRUNNING &&
		    ((j->flags & JF_FG) ||
		    (Flag(FLOGIN) && !Flag(FNOHUP) && procpid == kshpid))))) {
			killed = true;
			if (j->pgrp == 0)
				kill_job(j, SIGHUP);
			else
				mksh_killpg(j->pgrp, SIGHUP);
#ifndef MKSH_UNEMPLOYED
			if (j->state == PSTOPPED) {
				if (j->pgrp == 0)
					kill_job(j, SIGCONT);
				else
					mksh_killpg(j->pgrp, SIGCONT);
			}
#endif
		}
	}
	if (killed)
		sleep(1);
	j_notify();

#ifndef MKSH_UNEMPLOYED
	if (kshpid == procpid && restore_ttypgrp >= 0) {
		/*
		 * Need to restore the tty pgrp to what it was when the
		 * shell started up, so that the process that started us
		 * will be able to access the tty when we are done.
		 * Also need to restore our process group in case we are
		 * about to do an exec so that both our parent and the
		 * process we are to become will be able to access the tty.
		 */
		tcsetpgrp(tty_fd, restore_ttypgrp);
		setpgid(0, restore_ttypgrp);
	}
	if (Flag(FMONITOR)) {
		Flag(FMONITOR) = 0;
		j_change();
	}
#endif
}

#ifndef MKSH_UNEMPLOYED
/* turn job control on or off according to Flag(FMONITOR) */
void
j_change(void)
{
	int i;

	if (Flag(FMONITOR)) {
		bool use_tty = Flag(FTALKING);

		/* don't call mksh_tcget until we own the tty process group */
		if (use_tty)
			tty_init_talking();

		/* no controlling tty, no SIGT* */
		if ((ttypgrp_ok = (use_tty && tty_fd >= 0 && tty_devtty))) {
			setsig(&sigtraps[SIGTTIN], SIG_DFL,
			    SS_RESTORE_ORIG|SS_FORCE);
			/* wait to be given tty (POSIX.1, B.2, job control) */
			while (/* CONSTCOND */ 1) {
				pid_t ttypgrp;

				if ((ttypgrp = tcgetpgrp(tty_fd)) < 0) {
					warningf(false, Tf_ssfaileds,
					    "j_init", "tcgetpgrp",
					    cstrerror(errno));
					ttypgrp_ok = false;
					break;
				}
				if (ttypgrp == kshpgrp)
					break;
				kill(0, SIGTTIN);
			}
		}
		for (i = NELEM(tt_sigs); --i >= 0; )
			setsig(&sigtraps[tt_sigs[i]], SIG_IGN,
			    SS_RESTORE_DFL|SS_FORCE);
		if (ttypgrp_ok && kshpgrp != kshpid) {
			if (setpgid(0, kshpid) < 0) {
				warningf(false, Tf_ssfaileds,
				    "j_init", "setpgid", cstrerror(errno));
				ttypgrp_ok = false;
			} else {
				if (tcsetpgrp(tty_fd, kshpid) < 0) {
					warningf(false, Tf_ssfaileds,
					    "j_init", "tcsetpgrp",
					    cstrerror(errno));
					ttypgrp_ok = false;
				} else
					restore_ttypgrp = kshpgrp;
				kshpgrp = kshpid;
			}
		}
#ifndef MKSH_DISABLE_TTY_WARNING
		if (use_tty && !ttypgrp_ok)
			warningf(false, Tf_sD_s, "warning",
			    "won't have full job control");
#endif
	} else {
		ttypgrp_ok = false;
		if (Flag(FTALKING))
			for (i = NELEM(tt_sigs); --i >= 0; )
				setsig(&sigtraps[tt_sigs[i]], SIG_IGN,
				    SS_RESTORE_IGN|SS_FORCE);
		else
			for (i = NELEM(tt_sigs); --i >= 0; ) {
				if (sigtraps[tt_sigs[i]].flags &
				    (TF_ORIG_IGN | TF_ORIG_DFL))
					setsig(&sigtraps[tt_sigs[i]],
					    (sigtraps[tt_sigs[i]].flags & TF_ORIG_IGN) ?
					    SIG_IGN : SIG_DFL,
					    SS_RESTORE_ORIG|SS_FORCE);
			}
	}
	tty_init_state();
}
#endif

#if HAVE_NICE
/* run nice(3) and ignore the result */
static void
ksh_nice(int ness)
{
#if defined(__USE_FORTIFY_LEVEL) && (__USE_FORTIFY_LEVEL > 0)
	int eno;

	errno = 0;
	/* this is gonna annoy users; complain to your distro, people! */
	if (nice(ness) == -1 && (eno = errno) != 0)
		warningf(false, Tf_sD_s, "bgnice", cstrerror(eno));
#else
	(void)nice(ness);
#endif
}
#endif

/* execute tree in child subprocess */
int
exchild(struct op *t, int flags,
    volatile int *xerrok,
    /* used if XPCLOSE or XCCLOSE */
    int close_fd)
{
	/* for pipelines */
	static Proc *last_proc;

	int rv = 0, forksleep, jwflags = JW_NONE;
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;
#endif
	Proc *p;
	Job *j;
	pid_t cldpid;

	if (flags & XPIPEST) {
		flags &= ~XPIPEST;
		jwflags |= JW_PIPEST;
	}

	if (flags & XEXEC)
		/*
		 * Clear XFORK|XPCLOSE|XCCLOSE|XCOPROC|XPIPEO|XPIPEI|XXCOM|XBGND
		 * (also done in another execute() below)
		 */
		return (execute(t, flags & (XEXEC | XERROK), xerrok));

#ifndef MKSH_NOPROSPECTOFWORK
	/* no SIGCHLDs while messing with job and process lists */
	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

	p = new_proc();
	p->next = NULL;
	p->state = PRUNNING;
	p->status = 0;
	p->pid = 0;

	/* link process into jobs list */
	if (flags & XPIPEI) {
		/* continuing with a pipe */
		if (!last_job)
			internal_errorf("exchild: XPIPEI and no last_job - pid %d",
			    (int)procpid);
		j = last_job;
		if (last_proc)
			last_proc->next = p;
		last_proc = p;
	} else {
		/* fills in j->job */
		j = new_job();
		/*
		 * we don't consider XXCOMs foreground since they don't get
		 * tty process group and we don't save or restore tty modes.
		 */
		j->flags = (flags & XXCOM) ? JF_XXCOM :
		    ((flags & XBGND) ? 0 : (JF_FG|JF_USETTYMODE));
		timerclear(&j->usrtime);
		timerclear(&j->systime);
		j->state = PRUNNING;
		j->pgrp = 0;
		j->ppid = procpid;
		j->age = ++njobs;
		j->proc_list = p;
		j->coproc_id = 0;
		last_job = j;
		last_proc = p;
		put_job(j, PJ_PAST_STOPPED);
	}

	vistree(p->command, sizeof(p->command), t);

	/* create child process */
	forksleep = 1;
	while ((cldpid = fork()) < 0 && errno == EAGAIN && forksleep < 32) {
		if (intrsig)
			/* allow user to ^C out... */
			break;
		sleep(forksleep);
		forksleep <<= 1;
	}
	/* ensure $RANDOM changes between parent and child */
	rndset((unsigned long)cldpid);
	/* fork failed? */
	if (cldpid < 0) {
		kill_job(j, SIGKILL);
		remove_job(j, "fork failed");
#ifndef MKSH_NOPROSPECTOFWORK
		sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
		errorf("can't fork - try again");
	}
	p->pid = cldpid ? cldpid : (procpid = getpid());

#ifndef MKSH_UNEMPLOYED
	/* job control set up */
	if (Flag(FMONITOR) && !(flags&XXCOM)) {
		bool dotty = false;

		if (j->pgrp == 0) {
			/* First process */
			j->pgrp = p->pid;
			dotty = true;
		}

		/*
		 * set pgrp in both parent and child to deal with race
		 * condition
		 */
		setpgid(p->pid, j->pgrp);
		if (ttypgrp_ok && dotty && !(flags & XBGND))
			tcsetpgrp(tty_fd, j->pgrp);
	}
#endif

	/* used to close pipe input fd */
	if (close_fd >= 0 && (((flags & XPCLOSE) && cldpid) ||
	    ((flags & XCCLOSE) && !cldpid)))
		close(close_fd);
	if (!cldpid) {
		/* child */

		/* Do this before restoring signal */
		if (flags & XCOPROC)
			coproc_cleanup(false);
		cleanup_parents_env();
#ifndef MKSH_UNEMPLOYED
		/*
		 * If FMONITOR or FTALKING is set, these signals are ignored,
		 * if neither FMONITOR nor FTALKING are set, the signals have
		 * their inherited values.
		 */
		if (Flag(FMONITOR) && !(flags & XXCOM)) {
			for (forksleep = NELEM(tt_sigs); --forksleep >= 0; )
				setsig(&sigtraps[tt_sigs[forksleep]], SIG_DFL,
				    SS_RESTORE_DFL|SS_FORCE);
		}
#endif
#if HAVE_NICE
		if (Flag(FBGNICE) && (flags & XBGND))
			ksh_nice(4);
#endif
		if ((flags & XBGND)
#ifndef MKSH_UNEMPLOYED
		    && !Flag(FMONITOR)
#endif
		    ) {
			setsig(&sigtraps[SIGINT], SIG_IGN,
			    SS_RESTORE_IGN|SS_FORCE);
			setsig(&sigtraps[SIGQUIT], SIG_IGN,
			    SS_RESTORE_IGN|SS_FORCE);
			if ((!(flags & (XPIPEI | XCOPROC))) &&
			    ((forksleep = open("/dev/null", 0)) > 0)) {
				(void)ksh_dup2(forksleep, 0, true);
				close(forksleep);
			}
		}
		/* in case of $(jobs) command */
		remove_job(j, "child");
#ifndef MKSH_NOPROSPECTOFWORK
		/* remove_job needs SIGCHLD blocked still */
		sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
		nzombie = 0;
#ifndef MKSH_UNEMPLOYED
		ttypgrp_ok = false;
		Flag(FMONITOR) = 0;
#endif
		Flag(FTALKING) = 0;
		cleartraps();
		/* no return */
		execute(t, (flags & XERROK) | XEXEC, NULL);
#ifndef MKSH_SMALL
		if (t->type == TPIPE)
			unwind(LLEAVE);
		internal_warningf("%s: execute() returned", "exchild");
		fptreef(shl_out, 8, "%s: tried to execute {\n\t%T\n}\n",
		    "exchild", t);
		shf_flush(shl_out);
#endif
		unwind(LLEAVE);
		/* NOTREACHED */
	}

	/* shell (parent) stuff */
	if (!(flags & XPIPEO)) {
		/* last process in a job */
		j_startjob(j);
		if (flags & XCOPROC) {
			j->coproc_id = coproc.id;
			/* n jobs using co-process output */
			coproc.njobs++;
			/* j using co-process input */
			coproc.job = (void *)j;
		}
		if (flags & XBGND) {
			j_set_async(j);
			if (Flag(FTALKING)) {
				shf_fprintf(shl_out, "[%d]", j->job);
				for (p = j->proc_list; p; p = p->next)
					shf_fprintf(shl_out, Tf__d,
					    (int)p->pid);
				shf_putchar('\n', shl_out);
				shf_flush(shl_out);
			}
		} else
			rv = j_waitj(j, jwflags, "jw:last proc");
	}

#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif

	return (rv);
}

/* start the last job: only used for $(command) jobs */
void
startlast(void)
{
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

	/* no need to report error - waitlast() will do it */
	if (last_job) {
		/* ensure it isn't removed by check_job() */
		last_job->flags |= JF_WAITING;
		j_startjob(last_job);
	}
#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
}

/* wait for last job: only used for $(command) jobs */
int
waitlast(void)
{
	int rv;
	Job *j;
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

	j = last_job;
	if (!j || !(j->flags & JF_STARTED)) {
		if (!j)
			warningf(true, Tf_sD_s, "waitlast", "no last job");
		else
			internal_warningf(Tf_sD_s, "waitlast", Tnot_started);
#ifndef MKSH_NOPROSPECTOFWORK
		sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
		/* not so arbitrary, non-zero value */
		return (125);
	}

	rv = j_waitj(j, JW_NONE, "waitlast");

#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif

	return (rv);
}

/* wait for child, interruptable. */
int
waitfor(const char *cp, int *sigp)
{
	int rv, ecode, flags = JW_INTERRUPT|JW_ASYNCNOTIFY;
	Job *j;
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

	*sigp = 0;

	if (cp == NULL) {
		/*
		 * wait for an unspecified job - always returns 0, so
		 * don't have to worry about exited/signaled jobs
		 */
		for (j = job_list; j; j = j->next)
			/* AT&T ksh will wait for stopped jobs - we don't */
			if (j->ppid == procpid && j->state == PRUNNING)
				break;
		if (!j) {
#ifndef MKSH_NOPROSPECTOFWORK
			sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
			return (-1);
		}
	} else if ((j = j_lookup(cp, &ecode))) {
		/* don't report normal job completion */
		flags &= ~JW_ASYNCNOTIFY;
		if (j->ppid != procpid) {
#ifndef MKSH_NOPROSPECTOFWORK
			sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
			return (-1);
		}
	} else {
#ifndef MKSH_NOPROSPECTOFWORK
		sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
		if (ecode != JL_NOSUCH)
			bi_errorf(Tf_sD_s, cp, lookup_msgs[ecode]);
		return (-1);
	}

	/* AT&T ksh will wait for stopped jobs - we don't */
	rv = j_waitj(j, flags, "jw:waitfor");

#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif

	if (rv < 0)
		/* we were interrupted */
		*sigp = ksh_sigmask(-rv);

	return (rv);
}

/* kill (built-in) a job */
int
j_kill(const char *cp, int sig)
{
	Job *j;
	int rv = 0, ecode;
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

	if ((j = j_lookup(cp, &ecode)) == NULL) {
#ifndef MKSH_NOPROSPECTOFWORK
		sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
		bi_errorf(Tf_sD_s, cp, lookup_msgs[ecode]);
		return (1);
	}

	if (j->pgrp == 0) {
		/* started when !Flag(FMONITOR) */
		if (kill_job(j, sig) < 0) {
			bi_errorf(Tf_sD_s, cp, cstrerror(errno));
			rv = 1;
		}
	} else {
#ifndef MKSH_UNEMPLOYED
		if (j->state == PSTOPPED && (sig == SIGTERM || sig == SIGHUP))
			mksh_killpg(j->pgrp, SIGCONT);
#endif
		if (mksh_killpg(j->pgrp, sig) < 0) {
			bi_errorf(Tf_sD_s, cp, cstrerror(errno));
			rv = 1;
		}
	}

#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif

	return (rv);
}

#ifndef MKSH_UNEMPLOYED
/* fg and bg built-ins: called only if Flag(FMONITOR) set */
int
j_resume(const char *cp, int bg)
{
	Job *j;
	Proc *p;
	int ecode, rv = 0;
	bool running;
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);

	if ((j = j_lookup(cp, &ecode)) == NULL) {
		sigprocmask(SIG_SETMASK, &omask, NULL);
		bi_errorf(Tf_sD_s, cp, lookup_msgs[ecode]);
		return (1);
	}

	if (j->pgrp == 0) {
		sigprocmask(SIG_SETMASK, &omask, NULL);
		bi_errorf("job not job-controlled");
		return (1);
	}

	if (bg)
		shprintf("[%d] ", j->job);

	running = false;
	for (p = j->proc_list; p != NULL; p = p->next) {
		if (p->state == PSTOPPED) {
			p->state = PRUNNING;
			p->status = 0;
			running = true;
		}
		shf_puts(p->command, shl_stdout);
		if (p->next)
			shf_puts("| ", shl_stdout);
	}
	shf_putc('\n', shl_stdout);
	shf_flush(shl_stdout);
	if (running)
		j->state = PRUNNING;

	put_job(j, PJ_PAST_STOPPED);
	if (bg)
		j_set_async(j);
	else {
		/* attach tty to job */
		if (j->state == PRUNNING) {
			if (ttypgrp_ok && (j->flags & JF_SAVEDTTY))
				mksh_tcset(tty_fd, &j->ttystat);
			/* See comment in j_waitj regarding saved_ttypgrp. */
			if (ttypgrp_ok &&
			    tcsetpgrp(tty_fd, (j->flags & JF_SAVEDTTYPGRP) ?
			    j->saved_ttypgrp : j->pgrp) < 0) {
				rv = errno;
				if (j->flags & JF_SAVEDTTY)
					mksh_tcset(tty_fd, &tty_state);
				sigprocmask(SIG_SETMASK, &omask, NULL);
				bi_errorf(Tf_ldfailed,
				    "fg: 1st", "tcsetpgrp", tty_fd,
				    (long)((j->flags & JF_SAVEDTTYPGRP) ?
				    j->saved_ttypgrp : j->pgrp),
				    cstrerror(rv));
				return (1);
			}
		}
		j->flags |= JF_FG;
		j->flags &= ~JF_KNOWN;
		if (j == async_job)
			async_job = NULL;
	}

	if (j->state == PRUNNING && mksh_killpg(j->pgrp, SIGCONT) < 0) {
		int eno = errno;

		if (!bg) {
			j->flags &= ~JF_FG;
			if (ttypgrp_ok && (j->flags & JF_SAVEDTTY))
				mksh_tcset(tty_fd, &tty_state);
			if (ttypgrp_ok && tcsetpgrp(tty_fd, kshpgrp) < 0)
				warningf(true, Tf_ldfailed,
				    "fg: 2nd", "tcsetpgrp", tty_fd,
				    (long)kshpgrp, cstrerror(errno));
		}
		sigprocmask(SIG_SETMASK, &omask, NULL);
		bi_errorf(Tf_s_sD_s, "can't continue job",
		    cp, cstrerror(eno));
		return (1);
	}
	if (!bg) {
		if (ttypgrp_ok) {
			j->flags &= ~(JF_SAVEDTTY | JF_SAVEDTTYPGRP);
		}
		rv = j_waitj(j, JW_NONE, "jw:resume");
	}
	sigprocmask(SIG_SETMASK, &omask, NULL);
	return (rv);
}
#endif

/* are there any running or stopped jobs ? */
int
j_stopped_running(void)
{
	Job *j;
	int which = 0;

	for (j = job_list; j != NULL; j = j->next) {
#ifndef MKSH_UNEMPLOYED
		if (j->ppid == procpid && j->state == PSTOPPED)
			which |= 1;
#endif
		if (Flag(FLOGIN) && !Flag(FNOHUP) && procpid == kshpid &&
		    j->ppid == procpid && j->state == PRUNNING)
			which |= 2;
	}
	if (which) {
		shellf("You have %s%s%s jobs\n",
		    which & 1 ? "stopped" : "",
		    which == 3 ? " and " : "",
		    which & 2 ? "running" : "");
		return (1);
	}

	return (0);
}


/* list jobs for jobs built-in */
int
j_jobs(const char *cp, int slp,
    /* 0: short, 1: long, 2: pgrp */
    int nflag)
{
	Job *j, *tmp;
	int how, zflag = 0;
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

	if (nflag < 0) {
		/* kludge: print zombies */
		nflag = 0;
		zflag = 1;
	}
	if (cp) {
		int ecode;

		if ((j = j_lookup(cp, &ecode)) == NULL) {
#ifndef MKSH_NOPROSPECTOFWORK
			sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
			bi_errorf(Tf_sD_s, cp, lookup_msgs[ecode]);
			return (1);
		}
	} else
		j = job_list;
	how = slp == 0 ? JP_MEDIUM : (slp == 1 ? JP_LONG : JP_PGRP);
	for (; j; j = j->next) {
		if ((!(j->flags & JF_ZOMBIE) || zflag) &&
		    (!nflag || (j->flags & JF_CHANGED))) {
			j_print(j, how, shl_stdout);
			if (j->state == PEXITED || j->state == PSIGNALLED)
				j->flags |= JF_REMOVE;
		}
		if (cp)
			break;
	}
	/* Remove jobs after printing so there won't be multiple + or - jobs */
	for (j = job_list; j; j = tmp) {
		tmp = j->next;
		if (j->flags & JF_REMOVE)
			remove_job(j, Tjobs);
	}
#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
	return (0);
}

/* list jobs for top-level notification */
void
j_notify(void)
{
	Job *j, *tmp;
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif
	for (j = job_list; j; j = j->next) {
#ifndef MKSH_UNEMPLOYED
		if (Flag(FMONITOR) && (j->flags & JF_CHANGED))
			j_print(j, JP_MEDIUM, shl_out);
#endif
		/*
		 * Remove job after doing reports so there aren't
		 * multiple +/- jobs.
		 */
		if (j->state == PEXITED || j->state == PSIGNALLED)
			j->flags |= JF_REMOVE;
	}
	for (j = job_list; j; j = tmp) {
		tmp = j->next;
		if (j->flags & JF_REMOVE) {
			if (j == async_job || (j->flags & JF_KNOWN)) {
				j->flags = (j->flags & ~JF_REMOVE) | JF_ZOMBIE;
				j->job = -1;
				nzombie++;
			} else
				remove_job(j, "notify");
		}
	}
	shf_flush(shl_out);
#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
}

/* Return pid of last process in last asynchronous job */
pid_t
j_async(void)
{
#ifndef MKSH_NOPROSPECTOFWORK
	sigset_t omask;

	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

	if (async_job)
		async_job->flags |= JF_KNOWN;

#ifndef MKSH_NOPROSPECTOFWORK
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif

	return (async_pid);
}

/*
 * Make j the last async process
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static void
j_set_async(Job *j)
{
	Job *jl, *oldest;

	if (async_job && (async_job->flags & (JF_KNOWN|JF_ZOMBIE)) == JF_ZOMBIE)
		remove_job(async_job, "async");
	if (!(j->flags & JF_STARTED)) {
		internal_warningf(Tf_sD_s, "j_async", Tjob_not_started);
		return;
	}
	async_job = j;
	async_pid = j->last_proc->pid;
	while (nzombie > CHILD_MAX) {
		oldest = NULL;
		for (jl = job_list; jl; jl = jl->next)
			if (jl != async_job && (jl->flags & JF_ZOMBIE) &&
			    (!oldest || jl->age < oldest->age))
				oldest = jl;
		if (!oldest) {
			/* XXX debugging */
			if (!(async_job->flags & JF_ZOMBIE) || nzombie != 1) {
				internal_warningf("%s: bad nzombie (%d)",
				    "j_async", nzombie);
				nzombie = 0;
			}
			break;
		}
		remove_job(oldest, "zombie");
	}
}

/*
 * Start a job: set STARTED, check for held signals and set j->last_proc
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static void
j_startjob(Job *j)
{
	Proc *p;

	j->flags |= JF_STARTED;
	for (p = j->proc_list; p->next; p = p->next)
		;
	j->last_proc = p;

#ifndef MKSH_NOPROSPECTOFWORK
	if (held_sigchld) {
		held_sigchld = 0;
		/* Don't call j_sigchld() as it may remove job... */
		kill(procpid, SIGCHLD);
	}
#endif
}

/*
 * wait for job to complete or change state
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static int
j_waitj(Job *j,
    /* see JW_* */
    int flags,
    const char *where)
{
	Proc *p;
	int rv;
#ifdef MKSH_NO_SIGSUSPEND
	sigset_t omask;
#endif

	/*
	 * No auto-notify on the job we are waiting on.
	 */
	j->flags |= JF_WAITING;
	if (flags & JW_ASYNCNOTIFY)
		j->flags |= JF_W_ASYNCNOTIFY;

#ifndef MKSH_UNEMPLOYED
	if (!Flag(FMONITOR))
#endif
		flags |= JW_STOPPEDWAIT;

	while (j->state == PRUNNING ||
	    ((flags & JW_STOPPEDWAIT) && j->state == PSTOPPED)) {
#ifndef MKSH_NOPROSPECTOFWORK
#ifdef MKSH_NO_SIGSUSPEND
		sigprocmask(SIG_SETMASK, &sm_default, &omask);
		pause();
		/* note that handlers may run here so they need to know */
		sigprocmask(SIG_SETMASK, &omask, NULL);
#else
		sigsuspend(&sm_default);
#endif
#else
		j_sigchld(SIGCHLD);
#endif
		if (fatal_trap) {
			int oldf = j->flags & (JF_WAITING|JF_W_ASYNCNOTIFY);
			j->flags &= ~(JF_WAITING|JF_W_ASYNCNOTIFY);
			runtraps(TF_FATAL);
			/* not reached... */
			j->flags |= oldf;
		}
		if ((flags & JW_INTERRUPT) && (rv = trap_pending())) {
			j->flags &= ~(JF_WAITING|JF_W_ASYNCNOTIFY);
			return (-rv);
		}
	}
	j->flags &= ~(JF_WAITING|JF_W_ASYNCNOTIFY);

	if (j->flags & JF_FG) {
		j->flags &= ~JF_FG;
#ifndef MKSH_UNEMPLOYED
		if (Flag(FMONITOR) && ttypgrp_ok && j->pgrp) {
			/*
			 * Save the tty's current pgrp so it can be restored
			 * when the job is foregrounded. This is to
			 * deal with things like the GNU su which does
			 * a fork/exec instead of an exec (the fork means
			 * the execed shell gets a different pid from its
			 * pgrp, so naturally it sets its pgrp and gets hosed
			 * when it gets foregrounded by the parent shell which
			 * has restored the tty's pgrp to that of the su
			 * process).
			 */
			if (j->state == PSTOPPED &&
			    (j->saved_ttypgrp = tcgetpgrp(tty_fd)) >= 0)
				j->flags |= JF_SAVEDTTYPGRP;
			if (tcsetpgrp(tty_fd, kshpgrp) < 0)
				warningf(true, Tf_ldfailed,
				    "j_waitj:", "tcsetpgrp", tty_fd,
				    (long)kshpgrp, cstrerror(errno));
			if (j->state == PSTOPPED) {
				j->flags |= JF_SAVEDTTY;
				mksh_tcget(tty_fd, &j->ttystat);
			}
		}
#endif
		if (tty_hasstate) {
			/*
			 * Only restore tty settings if job was originally
			 * started in the foreground. Problems can be
			 * caused by things like 'more foobar &' which will
			 * typically get and save the shell's vi/emacs tty
			 * settings before setting up the tty for itself;
			 * when more exits, it restores the 'original'
			 * settings, and things go down hill from there...
			 */
			if (j->state == PEXITED && j->status == 0 &&
			    (j->flags & JF_USETTYMODE)) {
				mksh_tcget(tty_fd, &tty_state);
			} else {
				mksh_tcset(tty_fd, &tty_state);
				/*-
				 * Don't use tty mode if job is stopped and
				 * later restarted and exits. Consider
				 * the sequence:
				 *	vi foo (stopped)
				 *	...
				 *	stty something
				 *	...
				 *	fg (vi; ZZ)
				 * mode should be that of the stty, not what
				 * was before the vi started.
				 */
				if (j->state == PSTOPPED)
					j->flags &= ~JF_USETTYMODE;
			}
		}
#ifndef MKSH_UNEMPLOYED
		/*
		 * If it looks like user hit ^C to kill a job, pretend we got
		 * one too to break out of for loops, etc. (AT&T ksh does this
		 * even when not monitoring, but this doesn't make sense since
		 * a tty generated ^C goes to the whole process group)
		 */
		if (Flag(FMONITOR) && j->state == PSIGNALLED &&
		    WIFSIGNALED(j->last_proc->status)) {
			int termsig;

			if ((termsig = WTERMSIG(j->last_proc->status)) > 0 &&
			    termsig < ksh_NSIG &&
			    (sigtraps[termsig].flags & TF_TTY_INTR))
				trapsig(termsig);
		}
#endif
	}

	j_usrtime = j->usrtime;
	j_systime = j->systime;
	rv = j->status;

	if (!(p = j->proc_list)) {
		;	/* nothing */
	} else if (flags & JW_PIPEST) {
		uint32_t num = 0;
		struct tbl *vp;

		unset(vp_pipest, 1);
		vp = vp_pipest;
		vp->flag = DEFINED | ISSET | INTEGER | RDONLY | ARRAY | INT_U;
		goto got_array;

		while (p != NULL) {
			{
				struct tbl *vq;

				/* strlen(vp_pipest->name) == 10 */
				vq = alloc(offsetof(struct tbl, name[0]) + 11,
				    vp_pipest->areap);
				memset(vq, 0, offsetof(struct tbl, name[0]));
				memcpy(vq->name, vp_pipest->name, 11);
				vp->u.array = vq;
				vp = vq;
			}
			vp->areap = vp_pipest->areap;
			vp->ua.index = ++num;
			vp->flag = DEFINED | ISSET | INTEGER | RDONLY |
			    ARRAY | INT_U | AINDEX;
 got_array:
			vp->val.i = proc_errorlevel(p);
			if (Flag(FPIPEFAIL) && vp->val.i)
				rv = vp->val.i;
			p = p->next;
		}
	} else if (Flag(FPIPEFAIL)) {
		do {
			const int i = proc_errorlevel(p);

			if (i)
				rv = i;
		} while ((p = p->next));
	}

	if (!(flags & JW_ASYNCNOTIFY)
#ifndef MKSH_UNEMPLOYED
	    && (!Flag(FMONITOR) || j->state != PSTOPPED)
#endif
	    ) {
		j_print(j, JP_SHORT, shl_out);
		shf_flush(shl_out);
	}
	if (j->state != PSTOPPED
#ifndef MKSH_UNEMPLOYED
	    && (!Flag(FMONITOR) || !(flags & JW_ASYNCNOTIFY))
#endif
	    )
		remove_job(j, where);

	return (rv);
}

/*
 * SIGCHLD handler to reap children and update job states
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
/* ARGSUSED */
static void
j_sigchld(int sig MKSH_A_UNUSED)
{
	int saved_errno = errno;
	Job *j;
	Proc *p = NULL;
	pid_t pid;
	int status;
	struct rusage ru0, ru1;
#ifdef MKSH_NO_SIGSUSPEND
	sigset_t omask;

	/* this handler can run while SIGCHLD is not blocked, so block it now */
	sigprocmask(SIG_BLOCK, &sm_sigchld, &omask);
#endif

#ifndef MKSH_NOPROSPECTOFWORK
	/*
	 * Don't wait for any processes if a job is partially started.
	 * This is so we don't do away with the process group leader
	 * before all the processes in a pipe line are started (so the
	 * setpgid() won't fail)
	 */
	for (j = job_list; j; j = j->next)
		if (j->ppid == procpid && !(j->flags & JF_STARTED)) {
			held_sigchld = 1;
			goto j_sigchld_out;
		}
#endif

	getrusage(RUSAGE_CHILDREN, &ru0);
	do {
#ifndef MKSH_NOPROSPECTOFWORK
		pid = waitpid(-1, &status, (WNOHANG |
#if defined(WCONTINUED) && defined(WIFCONTINUED)
		    WCONTINUED |
#endif
		    WUNTRACED));
#else
		pid = wait(&status);
#endif

		/*
		 * return if this would block (0) or no children
		 * or interrupted (-1)
		 */
		if (pid <= 0)
			goto j_sigchld_out;

		getrusage(RUSAGE_CHILDREN, &ru1);

		/* find job and process structures for this pid */
		for (j = job_list; j != NULL; j = j->next)
			for (p = j->proc_list; p != NULL; p = p->next)
				if (p->pid == pid)
					goto found;
 found:
		if (j == NULL) {
			/* Can occur if process has kids, then execs shell
			warningf(true, "bad process waited for (pid = %d)",
				pid);
			 */
			ru0 = ru1;
			continue;
		}

		timeradd(&j->usrtime, &ru1.ru_utime, &j->usrtime);
		timersub(&j->usrtime, &ru0.ru_utime, &j->usrtime);
		timeradd(&j->systime, &ru1.ru_stime, &j->systime);
		timersub(&j->systime, &ru0.ru_stime, &j->systime);
		ru0 = ru1;
		p->status = status;
#ifndef MKSH_UNEMPLOYED
		if (WIFSTOPPED(status))
			p->state = PSTOPPED;
		else
#if defined(WCONTINUED) && defined(WIFCONTINUED)
		  if (WIFCONTINUED(status)) {
			p->state = j->state = PRUNNING;
			/* skip check_job(), no-op in this case */
			continue;
		} else
#endif
#endif
		  if (WIFSIGNALED(status))
			p->state = PSIGNALLED;
		else
			p->state = PEXITED;

		/* check to see if entire job is done */
		check_job(j);
	}
#ifndef MKSH_NOPROSPECTOFWORK
	    while (/* CONSTCOND */ 1);
#else
	    while (/* CONSTCOND */ 0);
#endif

 j_sigchld_out:
#ifdef MKSH_NO_SIGSUSPEND
	sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
	errno = saved_errno;
}

/*
 * Called only when a process in j has exited/stopped (ie, called only
 * from j_sigchld()). If no processes are running, the job status
 * and state are updated, asynchronous job notification is done and,
 * if unneeded, the job is removed.
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static void
check_job(Job *j)
{
	int jstate;
	Proc *p;

	/* XXX debugging (nasty - interrupt routine using shl_out) */
	if (!(j->flags & JF_STARTED)) {
		internal_warningf("check_job: job started (flags 0x%X)",
		    (unsigned int)j->flags);
		return;
	}

	jstate = PRUNNING;
	for (p=j->proc_list; p != NULL; p = p->next) {
		if (p->state == PRUNNING)
			/* some processes still running */
			return;
		if (p->state > jstate)
			jstate = p->state;
	}
	j->state = jstate;
	j->status = proc_errorlevel(j->last_proc);

	/*
	 * Note when co-process dies: can't be done in j_wait() nor
	 * remove_job() since neither may be called for non-interactive
	 * shells.
	 */
	if (j->state == PEXITED || j->state == PSIGNALLED) {
		/*
		 * No need to keep co-process input any more
		 * (at least, this is what ksh93d thinks)
		 */
		if (coproc.job == j) {
			coproc.job = NULL;
			/*
			 * XXX would be nice to get the closes out of here
			 * so they aren't done in the signal handler.
			 * Would mean a check in coproc_getfd() to
			 * do "if job == 0 && write >= 0, close write".
			 */
			coproc_write_close(coproc.write);
		}
		/* Do we need to keep the output? */
		if (j->coproc_id && j->coproc_id == coproc.id &&
		    --coproc.njobs == 0)
			coproc_readw_close(coproc.read);
	}

	j->flags |= JF_CHANGED;
#ifndef MKSH_UNEMPLOYED
	if (Flag(FMONITOR) && !(j->flags & JF_XXCOM)) {
		/*
		 * Only put stopped jobs at the front to avoid confusing
		 * the user (don't want finished jobs effecting %+ or %-)
		 */
		if (j->state == PSTOPPED)
			put_job(j, PJ_ON_FRONT);
		if (Flag(FNOTIFY) &&
		    (j->flags & (JF_WAITING|JF_W_ASYNCNOTIFY)) != JF_WAITING) {
			/* Look for the real file descriptor 2 */
			{
				struct env *ep;
				int fd = 2;

				for (ep = e; ep; ep = ep->oenv)
					if (ep->savefd && ep->savefd[2])
						fd = ep->savefd[2];
				shf_reopen(fd, SHF_WR, shl_j);
			}
			/*
			 * Can't call j_notify() as it removes jobs. The job
			 * must stay in the job list as j_waitj() may be
			 * running with this job.
			 */
			j_print(j, JP_MEDIUM, shl_j);
			shf_flush(shl_j);
			if (!(j->flags & JF_WAITING) && j->state != PSTOPPED)
				remove_job(j, "notify");
		}
	}
#endif
	if (
#ifndef MKSH_UNEMPLOYED
	    !Flag(FMONITOR) &&
#endif
	    !(j->flags & (JF_WAITING|JF_FG)) &&
	    j->state != PSTOPPED) {
		if (j == async_job || (j->flags & JF_KNOWN)) {
			j->flags |= JF_ZOMBIE;
			j->job = -1;
			nzombie++;
		} else
			remove_job(j, "checkjob");
	}
}

/*
 * Print job status in either short, medium or long format.
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static void
j_print(Job *j, int how, struct shf *shf)
{
	Proc *p;
	int state;
	int status;
#ifdef WCOREDUMP
	bool coredumped;
#endif
	char jobchar = ' ';
	char buf[64];
	const char *filler;
	int output = 0;

	if (how == JP_PGRP) {
		/*
		 * POSIX doesn't say what to do it there is no process
		 * group leader (ie, !FMONITOR). We arbitrarily return
		 * last pid (which is what $! returns).
		 */
		shf_fprintf(shf, Tf_dN, (int)(j->pgrp ? j->pgrp :
		    (j->last_proc ? j->last_proc->pid : 0)));
		return;
	}
	j->flags &= ~JF_CHANGED;
	filler = j->job > 10 ? "\n       " : "\n      ";
	if (j == job_list)
		jobchar = '+';
	else if (j == job_list->next)
		jobchar = '-';

	for (p = j->proc_list; p != NULL;) {
#ifdef WCOREDUMP
		coredumped = false;
#endif
		switch (p->state) {
		case PRUNNING:
			memcpy(buf, "Running", 8);
			break;
		case PSTOPPED: {
			int stopsig = WSTOPSIG(p->status);

			strlcpy(buf, stopsig > 0 && stopsig < ksh_NSIG ?
			    sigtraps[stopsig].mess : "Stopped", sizeof(buf));
			break;
		}
		case PEXITED: {
			int exitstatus = (WEXITSTATUS(p->status)) & 255;

			if (how == JP_SHORT)
				buf[0] = '\0';
			else if (exitstatus == 0)
				memcpy(buf, "Done", 5);
			else
				shf_snprintf(buf, sizeof(buf), "Done (%d)",
				    exitstatus);
			break;
		}
		case PSIGNALLED: {
			int termsig = WTERMSIG(p->status);
#ifdef WCOREDUMP
			if (WCOREDUMP(p->status))
				coredumped = true;
#endif
			/*
			 * kludge for not reporting 'normal termination
			 * signals' (i.e. SIGINT, SIGPIPE)
			 */
			if (how == JP_SHORT &&
#ifdef WCOREDUMP
			    !coredumped &&
#endif
			    (termsig == SIGINT || termsig == SIGPIPE)) {
				buf[0] = '\0';
			} else
				strlcpy(buf, termsig > 0 && termsig < ksh_NSIG ?
				    sigtraps[termsig].mess : "Signalled",
				    sizeof(buf));
			break;
		}
		default:
			buf[0] = '\0';
		}

		if (how != JP_SHORT) {
			if (p == j->proc_list)
				shf_fprintf(shf, "[%d] %c ", j->job, jobchar);
			else
				shf_puts(filler, shf);
		}

		if (how == JP_LONG)
			shf_fprintf(shf, "%5d ", (int)p->pid);

		if (how == JP_SHORT) {
			if (buf[0]) {
				output = 1;
#ifdef WCOREDUMP
				shf_fprintf(shf, "%s%s ",
				    buf, coredumped ? " (core dumped)" : null);
#else
				shf_puts(buf, shf);
				shf_putchar(' ', shf);
#endif
			}
		} else {
			output = 1;
			shf_fprintf(shf, "%-20s %s%s%s", buf, p->command,
			    p->next ? "|" : null,
#ifdef WCOREDUMP
			    coredumped ? " (core dumped)" :
#endif
			     null);
		}

		state = p->state;
		status = p->status;
		p = p->next;
		while (p && p->state == state && p->status == status) {
			if (how == JP_LONG)
				shf_fprintf(shf, "%s%5d %-20s %s%s", filler,
				    (int)p->pid, T1space, p->command,
				    p->next ? "|" : null);
			else if (how == JP_MEDIUM)
				shf_fprintf(shf, Tf__ss, p->command,
				    p->next ? "|" : null);
			p = p->next;
		}
	}
	if (output)
		shf_putc('\n', shf);
}

/*
 * Convert % sequence to job
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static Job *
j_lookup(const char *cp, int *ecodep)
{
	Job *j, *last_match;
	Proc *p;
	size_t len;
	int job = 0;

	if (ctype(*cp, C_DIGIT) && getn(cp, &job)) {
		/* Look for last_proc->pid (what $! returns) first... */
		for (j = job_list; j != NULL; j = j->next)
			if (j->last_proc && j->last_proc->pid == job)
				return (j);
		/*
		 * ...then look for process group (this is non-POSIX,
		 * but should not break anything
		 */
		for (j = job_list; j != NULL; j = j->next)
			if (j->pgrp && j->pgrp == job)
				return (j);
		goto j_lookup_nosuch;
	}
	if (*cp != '%') {
 j_lookup_invalid:
		if (ecodep)
			*ecodep = JL_INVALID;
		return (NULL);
	}
	switch (*++cp) {
	case '\0': /* non-standard */
	case '+':
	case '%':
		if (job_list != NULL)
			return (job_list);
		break;

	case '-':
		if (job_list != NULL && job_list->next)
			return (job_list->next);
		break;

	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		if (!getn(cp, &job))
			goto j_lookup_invalid;
		for (j = job_list; j != NULL; j = j->next)
			if (j->job == job)
				return (j);
		break;

	/* %?string */
	case '?':
		last_match = NULL;
		for (j = job_list; j != NULL; j = j->next)
			for (p = j->proc_list; p != NULL; p = p->next)
				if (strstr(p->command, cp+1) != NULL) {
					if (last_match) {
						if (ecodep)
							*ecodep = JL_AMBIG;
						return (NULL);
					}
					last_match = j;
				}
		if (last_match)
			return (last_match);
		break;

	/* %string */
	default:
		len = strlen(cp);
		last_match = NULL;
		for (j = job_list; j != NULL; j = j->next)
			if (strncmp(cp, j->proc_list->command, len) == 0) {
				if (last_match) {
					if (ecodep)
						*ecodep = JL_AMBIG;
					return (NULL);
				}
				last_match = j;
			}
		if (last_match)
			return (last_match);
		break;
	}
 j_lookup_nosuch:
	if (ecodep)
		*ecodep = JL_NOSUCH;
	return (NULL);
}

static Job	*free_jobs;
static Proc	*free_procs;

/*
 * allocate a new job and fill in the job number.
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static Job *
new_job(void)
{
	int i;
	Job *newj, *j;

	if (free_jobs != NULL) {
		newj = free_jobs;
		free_jobs = free_jobs->next;
	} else {
		char *cp;

		/*
		 * struct job includes ALLOC_ITEM for alignment constraints
		 * so first get the actually used memory, then assign it
		 */
		cp = alloc(sizeof(Job) - sizeof(ALLOC_ITEM), APERM);
		/* undo what alloc() did to the malloc result address */
		newj = (void *)(cp - sizeof(ALLOC_ITEM));
	}

	/* brute force method */
	i = 0;
	do {
		++i;
		j = job_list;
		while (j && j->job != i)
			j = j->next;
	} while (j);
	newj->job = i;

	return (newj);
}

/*
 * Allocate new process struct
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static Proc *
new_proc(void)
{
	Proc *p;

	if (free_procs != NULL) {
		p = free_procs;
		free_procs = free_procs->next;
	} else
		p = alloc(sizeof(Proc), APERM);

	return (p);
}

/*
 * Take job out of job_list and put old structures into free list.
 * Keeps nzombies, last_job and async_job up to date.
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static void
remove_job(Job *j, const char *where)
{
	Proc *p, *tmp;
	Job **prev, *curr;

	prev = &job_list;
	curr = job_list;
	while (curr && curr != j) {
		prev = &curr->next;
		curr = *prev;
	}
	if (curr != j) {
		internal_warningf("remove_job: job %s (%s)", Tnot_found, where);
		return;
	}
	*prev = curr->next;

	/* free up proc structures */
	for (p = j->proc_list; p != NULL; ) {
		tmp = p;
		p = p->next;
		tmp->next = free_procs;
		free_procs = tmp;
	}

	if ((j->flags & JF_ZOMBIE) && j->ppid == procpid)
		--nzombie;
	j->next = free_jobs;
	free_jobs = j;

	if (j == last_job)
		last_job = NULL;
	if (j == async_job)
		async_job = NULL;
}

/*
 * put j in a particular location (taking it out job_list if it is there
 * already)
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static void
put_job(Job *j, int where)
{
	Job **prev, *curr;

	/* Remove job from list (if there) */
	prev = &job_list;
	curr = job_list;
	while (curr && curr != j) {
		prev = &curr->next;
		curr = *prev;
	}
	if (curr == j)
		*prev = curr->next;

	switch (where) {
	case PJ_ON_FRONT:
		j->next = job_list;
		job_list = j;
		break;

	case PJ_PAST_STOPPED:
		prev = &job_list;
		curr = job_list;
		for (; curr && curr->state == PSTOPPED; prev = &curr->next,
		    curr = *prev)
			;
		j->next = curr;
		*prev = j;
		break;
	}
}

/*
 * nuke a job (called when unable to start full job).
 *
 * If jobs are compiled in then this routine expects sigchld to be blocked.
 */
static int
kill_job(Job *j, int sig)
{
	Proc *p;
	int rval = 0;

	for (p = j->proc_list; p != NULL; p = p->next)
		if (p->pid != 0)
			if (kill(p->pid, sig) < 0)
				rval = -1;
	return (rval);
}

static void
tty_init_talking(void)
{
	switch (tty_init_fd()) {
	case 0:
		break;
	case 1:
#ifndef MKSH_DISABLE_TTY_WARNING
		warningf(false, Tf_sD_s_sD_s,
		    "No controlling tty", Topen, T_devtty, cstrerror(errno));
#endif
		break;
	case 2:
#ifndef MKSH_DISABLE_TTY_WARNING
		warningf(false, Tf_s_sD_s, Tcant_find, Ttty_fd,
		    cstrerror(errno));
#endif
		break;
	case 3:
		warningf(false, Tf_ssfaileds, "j_ttyinit",
		    Ttty_fd_dupof, cstrerror(errno));
		break;
	case 4:
		warningf(false, Tf_sD_sD_s, "j_ttyinit",
		    "can't set close-on-exec flag", cstrerror(errno));
		break;
	}
}

static void
tty_init_state(void)
{
	if (tty_fd >= 0) {
		mksh_tcget(tty_fd, &tty_state);
		tty_hasstate = true;
	}
}
