dnl Copyright (C) 1996, Memorial University of Newfoundland.
dnl This file is covered by the GNU General Public License, version 2, see
dnl the file misc/COPYING for details.
dnl
dnl This file is covered by the GPL 'cause it contains some modified versions
dnl of autoconf's macros, in particular:
dnl	AC_FUNC_MMAP AC_LANG_C AC_LANG_CPLUXPLUS AC_TRY_RUN KSH_HEADER_SYS_WAIT
dnl	AC_HEADER_STAT AC_PROG_CC
dnl
dnl
dnl Like AC_CHECK_TYPE(), only
dnl	- user gets to specify header file(s) in addition to the default
dnl	  headers (<sys/types.h> and <stdlib.h>)
dnl	- user gets to specify the message
dnl	- word boundary checks are put at beginning/end of pattern
dnl	  (ie, \<pattern\>)
dnl	- default argument is optional
dnl uses ac_cv_type_X 'cause this is used in other autoconf macros...
dnl KSH_CHECK_H_TYPE(type, message, header files, default)
AC_DEFUN(KSH_CHECK_H_TYPE,
 [AC_CACHE_CHECK($2, ac_cv_type_$1,
    [AC_EGREP_CPP([(^|[^a-zA-Z0-9_])]$1[([^a-zA-Z0-9_]|\$)],
      [#include <sys/types.h>
#if STDC_HEADERS
#include <stdlib.h>
#endif
$3
      ], ac_cv_type_$1=yes, ac_cv_type_$1=no)])
  ifelse($#, 4, [if test $ac_cv_type_$1 = no; then
      AC_DEFINE($1, $4)
  fi
  ])dnl
 ])dnl
dnl
dnl
dnl
dnl Check for memmove and if not found, check for bcopy.  AC_CHECK_FUNCS()
dnl not used 'cause it confuses some compilers that have memmove/bcopy builtin;
dnl Also want to check if the function deals with overlapping src/dst properly.
AC_DEFUN(KSH_MEMMOVE,
 [AC_CACHE_CHECK(for working memmove, ksh_cv_func_memmove,
    [AC_TRY_RUN([
#ifdef HAVE_STRING_H
# include <string.h>
#else
# include <strings.h>
#endif
#ifdef HAVE_MEMORY_H
# include <memory.h>
#endif
        int
        main()
        {
	  char buf[16];
	  strcpy(buf, "abcdefABCDEF");
	  memmove(buf + 4, buf, 6);
	  if (strcmp(buf, "abcdabcdefEF"))
	    exit(1);
	  memmove(buf, buf + 4, 6);
	  if (strcmp(buf, "abcdefcdefEF"))
	    exit(2);
	  exit(0);
	  return 0;
	}],
       ksh_cv_func_memmove=yes, ksh_cv_func_memmove=no,
       AC_MSG_WARN(assuming memmove broken); ksh_cv_func_memmove=no)])
  if test $ksh_cv_func_memmove = yes; then
    AC_DEFINE(HAVE_MEMMOVE)
  else
    AC_CACHE_CHECK(for working bcopy, ksh_cv_func_bcopy,
      [AC_TRY_RUN([
#ifdef HAVE_STRING_H
# include <string.h>
#else
# include <strings.h>
#endif
#ifdef HAVE_MEMORY_H
# include <memory.h>
#endif
	  int
	  main()
	  {
	    char buf[16];
	    strcpy(buf, "abcdefABCDEF");
	    bcopy(buf, buf + 4, 6);
	    if (strcmp(buf, "abcdabcdefEF"))
	      exit(1);
	    bcopy(buf + 4, buf, 6);
	    if (strcmp(buf, "abcdefcdefEF"))
	      exit(2);
	    exit(0);
	  }],
	 ksh_cv_func_bcopy=yes, ksh_cv_func_bcopy=no,
         AC_MSG_WARN(assuming bcopy broken); ksh_cv_func_bcopy=no)])
    if test $ksh_cv_func_bcopy = yes; then
      AC_DEFINE(HAVE_BCOPY)
    fi
  fi
 ])dnl
dnl
dnl
dnl
dnl Check for sigsetjmp()/siglongjmp() and _setjmp()/_longjmp() pairs.
dnl Can't use simple library check as QNX 422 has _setjmp() but not _longjmp()
dnl (go figure).
AC_DEFUN(KSH_SETJMP,
 [AC_CACHE_CHECK(for sigsetjmp()/siglongjmp(), ksh_cv_func_sigsetjmp,
    [AC_TRY_LINK([], [sigsetjmp(); siglongjmp()],
       ksh_cv_func_sigsetjmp=yes, ksh_cv_func_sigsetjmp=no)])
  if test $ksh_cv_func_sigsetjmp = yes; then
    AC_DEFINE(HAVE_SIGSETJMP)
  else
    AC_CACHE_CHECK(for _setjmp()/_longjmp(), ksh_cv_func__setjmp,
      [AC_TRY_LINK([], [_setjmp(); _longjmp();],
	 ksh_cv_func__setjmp=yes, ksh_cv_func__setjmp=no)])
    if test $ksh_cv_func__setjmp = yes; then
      AC_DEFINE(HAVE__SETJMP)
    fi
  fi
 ])dnl
dnl
dnl
dnl
dnl Check for memset function.   AC_CHECK_FUNCS() not used 'cause it confuses
dnl some compilers that have memset builtin.
AC_DEFUN(KSH_MEMSET,
 [AC_CACHE_CHECK(for memset, ksh_cv_func_memset,
    [AC_TRY_LINK([
#ifdef HAVE_STRING_H
# include <string.h>
#else
# include <strings.h>
#endif
#ifdef HAVE_MEMORY_H
# include <memory.h>
#endif
       ], [
       char buf[16]; memset(buf, 'x', 7); printf("%7s", buf);],
       ksh_cv_func_memset=yes, ksh_cv_func_memset=no)])
  if test $ksh_cv_func_memset = yes; then
    AC_DEFINE(HAVE_MEMSET)
  fi
 ])dnl
dnl
dnl
dnl
dnl Check for rlim_t in a few places, and if not found, figure out the
dnl size rlim_t should be by looking at struct rlimit.rlim_cur.
AC_DEFUN(KSH_RLIM_CHECK,
 [KSH_CHECK_H_TYPE(rlim_t, for rlim_t in <sys/types.h> and <sys/resource.h>,
   [#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif])dnl
  if test $ac_cv_type_rlim_t = no; then
    AC_MSG_CHECKING(what to set rlim_t to)
    if test $ac_cv_header_sys_resource_h = yes; then
      AC_CACHE_VAL(ksh_cv_rlim_check,
	[AC_TRY_RUN([
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
	    main()
	    {
	      struct rlimit rl;
	      if (sizeof(rl.rlim_cur) == sizeof(quad_t))
		exit(0);
	      exit(1);
	    }
	  ], ksh_cv_rlim_check=quad_t, ksh_cv_rlim_check=long,
	  AC_MSG_ERROR(cannot determine type for rlimt_t when cross compiling)
	  )])dnl
    else
      ksh_cv_rlim_check=long
    fi
    AC_MSG_RESULT($ksh_cv_rlim_check)
    AC_DEFINE_UNQUOTED(rlim_t, $ksh_cv_rlim_check)
  fi
 ])dnl
dnl
dnl
dnl
AC_DEFUN(KSH_DEV_FD,
 [AC_CACHE_CHECK(if you have /dev/fd/n, ksh_cv_dev_fd,
    [AC_TRY_RUN([
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
	  main()
	  {
	    struct stat s1, s2;
	    FILE *fp1, *fp2;
	    char *file = "conftest.file";
	    char devfd[32];

	    if (!(fp1 = fopen(file, "w")))
	      exit(1);
	    if (fstat(fileno(fp1), &s1) < 0)
	      exit(2);
	    sprintf(devfd, "/dev/fd/%d", fileno(fp1));
	    if (!(fp2 = fopen(devfd, "w")))
	      exit(3);
	    if (fstat(fileno(fp2), &s2) < 0)
	      exit(4);
	    if (s1.st_dev != s2.st_dev || s1.st_ino != s2.st_ino)
	      exit(5);
	    exit(0);
	  }
	], ksh_cv_dev_fd=yes, ksh_cv_dev_fd=no,
	AC_MSG_WARN(cannot determine if you have /dev/fd support, assuming not)
	ksh_cv_dev_fd=no)])
  if test $ksh_cv_dev_fd = yes; then
    AC_DEFINE(HAVE_DEV_FD)
  fi
 ])dnl
dnl
dnl
dnl
dnl  Check for sys_siglist[] declaration and existence.
AC_DEFUN(KSH_SYS_SIGLIST,
 [AC_DECL_SYS_SIGLIST
  if test ac_cv_decl_sys_siglist = yes; then
    AC_DEFINE(HAVE_SYS_SIGLIST)
  else
    AC_CACHE_CHECK(for sys_siglist in library, ksh_cv_var_sys_siglist,
      [AC_TRY_LINK(, [
	  extern char *sys_siglist[];
	  char *p = sys_siglist[2];
	  if (p)
		  return 12;
	  ], ksh_cv_var_sys_siglist=yes, ksh_cv_var_sys_siglist=no)])
    if test $ksh_cv_var_sys_siglist = yes; then
      AC_DEFINE(HAVE_SYS_SIGLIST)
    fi
  fi
 ])dnl
dnl
dnl
dnl
dnl  Check for sys_errlist[] declaration and existence.
AC_DEFUN(KSH_SYS_ERRLIST,
 [AC_CACHE_CHECK(for sys_errlist declaration in errno.h, ksh_cv_decl_sys_errlist,
  [AC_TRY_COMPILE([#include <errno.h>],
    [char *msg = *(sys_errlist + 1); if (msg && *msg) return 12; ],
    ksh_cv_decl_sys_errlist=yes, ksh_cv_decl_sys_errlist=no)])
  if test $ksh_cv_decl_sys_errlist = yes; then
    AC_DEFINE(SYS_ERRLIST_DECLARED)
    AC_DEFINE(HAVE_SYS_ERRLIST)
  else
    AC_CACHE_CHECK(for sys_errlist in library, ksh_cv_var_sys_errlist,
      [AC_TRY_LINK(, [
	    extern char *sys_errlist[];
	    extern int sys_nerr;
	    char *p;
	    p = sys_errlist[sys_nerr - 1];
	    if (p) return 12;
	  ], ksh_cv_var_sys_errlist=yes, ksh_cv_var_sys_errlist=no)])
    if test $ksh_cv_var_sys_errlist = yes; then
      AC_DEFINE(HAVE_SYS_ERRLIST)
    fi
  fi
 ])dnl
dnl
dnl
dnl
dnl  Check if time() declared in time.h
AC_DEFUN(KSH_TIME_DECLARED,
 [AC_CACHE_CHECK(time() declaration in time.h, ksh_cv_time_delcared,
    [AC_TRY_COMPILE([#include <sys/types.h>
#include <time.h>], [time_t (*f)() = time; if (f) return 12;],
      ksh_cv_time_delcared=yes, ksh_cv_time_delcared=no)])
  if test $ksh_cv_time_delcared = yes; then
    AC_DEFINE(TIME_DECLARED)
  fi
 ])dnl
dnl
dnl
dnl
dnl Check for working times (ie, it exists and doesn't always return 0).
dnl Defines TIMES_BROKEN if it doesn't exist or if it always returns 0
dnl (also checks for existance of getrusage if times doesn't work).
dnl  XXX: requires clock_t to be typedefed/defined...
AC_DEFUN(KSH_TIMES_CHECK,
 [AC_CACHE_CHECK(if times() is present/working, ksh_cv_func_times_ok,
    [AC_TRY_RUN([
#include <sys/types.h>
#include <sys/times.h>
/* if missing, clock_t is defined to be INT32 */
#if SIZEOF_INT == 4
# define INT32	int
#else /* SIZEOF_INT */
# if SIZEOF_LONG == 4
#  define INT32	long
# else /* SIZEOF_LONG */
   #error cannot find 32 bit type...
# endif /* SIZEOF_LONG */
#endif /* SIZEOF_INT */
	  main()
	  {
	    extern clock_t times();
	    struct tms tms;
	    times(&tms);
	    sleep(1);
	    if (times(&tms) == 0)
	      exit(1);
	    exit(0);
	  }
	], ksh_cv_func_times_ok=yes, ksh_cv_func_times_ok=no,
	AC_MSG_ERROR(cannot determine if times works when cross compiling)
	)])
  if test $ksh_cv_func_times_ok = no; then
    AC_DEFINE(TIMES_BROKEN)
    AC_CHECK_FUNCS(getrusage)
  fi
 ])dnl
dnl
dnl
dnl
AC_DEFUN(KSH_C_VOID,
 [AC_CACHE_CHECK(if compiler understands void, ksh_cv_c_void,
    [AC_TRY_COMPILE(
      [
	void foo() { }
	/* Some compilers (old pcc ones) like "void *a;", but a can't be used */
	void *bar(a) void *a; { int *b = (int *) a; *b = 1; return a; }
      ], , ksh_cv_c_void=yes, ksh_cv_c_void=no)])
  if test $ksh_cv_c_void = yes; then
    :
  else
    AC_DEFINE(void, char)
  fi
 ])dnl
dnl
dnl
dnl
dnl Early MIPS compilers (used in Ultrix 4.2) don't like
dnl "int x; int *volatile a = &x; *a = 0;"
AC_DEFUN(KSH_C_VOLATILE,
 [AC_CACHE_CHECK(if compiler understands volatile, ksh_cv_c_volatile,
    [AC_TRY_COMPILE([int x, y, z;],
      [volatile int a; int * volatile b = x ? &y : &z;
      /* Older MIPS compilers (eg., in Ultrix 4.2) don't like *b = 0 */
      *b = 0;], ksh_cv_c_volatile=yes, ksh_cv_c_volatile=no)])
  if test $ksh_cv_c_volatile = yes; then
    :
  else
    AC_DEFINE(volatile, )
  fi
 ])dnl
dnl
dnl
dnl
dnl Check if function prototypes work (including stdc vararg prototypes)
AC_DEFUN(KSH_C_PROTOTYPES,
 [AC_CACHE_CHECK(if compiler understands prototypes, ksh_cv_c_prototypes,
    [AC_TRY_COMPILE([
#include <stdarg.h>
void foo(char *fmt, ...);
int bar(int a, char b, char *c);
int bar(a, b, c) int a; char b; char *c;
{ foo("%d%c%s\n", a, b, c); return a + b + *c; }
void foo(char *fmt, ...) { va_list a; va_start(a, fmt); va_end(a); }
      ], , ksh_cv_c_prototypes=yes, ksh_cv_c_prototypes=no)])
  if test $ksh_cv_c_prototypes = yes; then
    AC_DEFINE(HAVE_PROTOTYPES)
  fi
 ])dnl
dnl
dnl
dnl
dnl Check if C compiler understands gcc's __attribute((...)).
dnl checks for noreturn, const, and format(type,fmt,param), also checks
dnl that the compiler doesn't die when it sees an unknown attribute (this
dnl isn't perfect since gcc doesn't parse unknown attributes with parameters)
AC_DEFUN(KSH_C_FUNC_ATTR,
 [AC_CACHE_CHECK(if C compiler groks __attribute__(( .. )), ksh_cv_c_func_attr,
    [AC_TRY_COMPILE([
#include <stdarg.h>
void test_fmt(char *fmt, ...) __attribute__((format(printf, 1, 2)));
void test_fmt(char *fmt, ...) { return; }
int test_cnst(int) __attribute__((const));
int test_cnst(int x) { return x + 1; }
void test_nr() __attribute__((noreturn));
void test_nr() { exit(1); }
void test_uk() __attribute__((blah));
void test_uk() { return; }
      ], [test_nr("%d", 10); test_cnst(2); test_uk(); test_nr(); ],
      ksh_cv_c_func_attr=yes, ksh_cv_c_func_attr=no)])
  if test $ksh_cv_c_func_attr = yes; then
    AC_DEFINE(HAVE_GCC_FUNC_ATTR)
  fi
 ])dnl
dnl
dnl
dnl
dnl Check if dup2() does not clear the close on exec flag
AC_DEFUN(KSH_DUP2_CLEXEC_CHECK,
 [AC_CACHE_CHECK([if dup2() works (ie, resets the close-on-exec flag)], ksh_cv_dup2_clexec_ok,
    [AC_TRY_RUN([
#include <sys/types.h>
#ifdef HAVE_FCNTL_H
# include <fcntl.h>
#endif /* HAVE_FCNTL_H */
#ifndef F_GETFD
# define F_GETFD 1
#endif
#ifndef F_SETFD
# define F_SETFD 2
#endif
#ifndef O_RDONLY
# define O_RDONLY 0
#endif
/* On some systems (Ultrix 2.1..4.2 (and more?)), dup2() does not clear
   the close on exec flag */
main()
{
  int fd1, fd2;
  fd1 = open("/dev/null", O_RDONLY);
  if (fcntl(fd1, F_SETFD, 1) < 0)
    exit(1);
  fd2 = dup2(fd1, fd1 + 1);
  if (fd2 < 0)
    exit(2);
  exit(fcntl(fd2, F_GETFD, 0) == 0 ? 0 : 3);
}
     ], ksh_cv_dup2_clexec_ok=yes, ksh_cv_dup2_clexec_ok=no,
     AC_MSG_WARN(cannot test if dup2 is broken when cross compiling - assuming it is)
     ksh_cv_dup2_clexec_ok=no)])
  if test $ksh_cv_dup2_clexec_ok = no; then
    AC_DEFINE(DUP2_BROKEN)
  fi
 ])dnl
dnl
dnl
dnl
dnl Check type of signal routines (posix, 4.2bsd, 4.1bsd or v7)
AC_DEFUN(KSH_SIGNAL_CHECK,
 [AC_CACHE_CHECK(flavour of signal routines, ksh_cv_signal_check,
    [AC_TRY_LINK([#include <signal.h>], [
	sigset_t ss;
	struct sigaction sa;
	sigemptyset(&ss); sigsuspend(&ss);
	sigaction(SIGINT, &sa, (struct sigaction *) 0);
	sigprocmask(SIG_BLOCK, &ss, (sigset_t *) 0);
      ], ksh_cv_signal_check=posix,
      AC_TRY_LINK([#include <signal.h>], [
	  int mask = sigmask(SIGINT);
	  sigsetmask(mask); sigblock(mask); sigpause(mask);
	], ksh_cv_signal_check=bsd42,
        AC_TRY_LINK([#include <signal.h>
			RETSIGTYPE foo() { }],
	  [
	    int mask = sigmask(SIGINT);
	    sigset(SIGINT, foo); sigrelse(SIGINT);
	    sighold(SIGINT); sigpause(SIGINT);
	  ], ksh_cv_signal_check=bsd41, ksh_cv_signal_check=v7)))])
  if test $ksh_cv_signal_check = posix; then
    AC_DEFINE(POSIX_SIGNALS)
  else
    AC_DEFINE(USE_FAKE_SIGACT)
    if test $ksh_cv_signal_check = bsd42; then
      AC_DEFINE(BSD42_SIGNALS)
    elif test $ksh_cv_signal_check = bsd41; then
      AC_DEFINE(BSD41_SIGNALS)
      AC_CACHE_CHECK(if signals interrupt read(), ksh_cv_signals_interrupt,
	[AC_TRY_RUN([
#include <errno.h>
#include <signal.h>

		extern int errno;
		int flag = 0;

		RETSIGTYPE
		catcher(int sig)
		{
		    flag = 1;
		    return RETSIGVAL;
		}

		int
		main()
		{
		    int pid;
		    int fdc[2];	/* child writes to parent */
		    int fdp[2];	/* parent writes to child */
		    char buf;
		    int nread;

		    if (pipe(fdc) < 0)
			exit(1);
		    if (pipe(fdp) < 0)
			exit(2);
		    if ((pid = fork()) < 0)
			exit(3);
		    if (pid == 0) {
			close(fdc[0]);
			close(fdp[1]);
			if (read(fdp[0], &buf, 1) != 0)
			    exit(10);
			sleep(1); /* let parent into read */
			if (kill(getppid(), SIGALRM) < 0)
			    exit(11);
			sleep(1); /* ensure parent gets to run */
			write(fdc[1], "1", 1);
			close(fdc[1]);
			exit(0);
		    }
		    close(fdc[1]);
		    close(fdp[0]);

		    /* Use native routines for test as this is what the shell
		     * will be using...
		     */
#ifdef POSIX_SIGNALS
		    {
			struct sigaction sa, osa;
			sa.sa_handler = catcher;
			sigemptyset(&sa.sa_mask);
			sa.sa_flags = 0;
			sigaction(SIGALRM, &sa, &osa);
		    }
#else /* POSIX_SIGNALS */
# ifdef BSD42_SIGNALS
		    {
			struct sigvec vec, ovec;
			vec.sv_handler = catcher;
			vec.sv_mask = 0;
			vec.sv_flags = 0;
#  ifdef SV_INTERRUPT
			vec.sv_flags |= SV_INTERRUPT;
#  endif /* SV_INTERRUPT */
			sigvec(SIGALRM, &vec, &ovec);
		    }
# else /* BSD42_SIGNALS */
#  ifdef BSD41_SIGNALS
		    sigset(SIGALRM, catcher);
#  else /* BSD41_SIGNALS */
#   ifdef V7_SIGNALS
		    signal(SIGALRM, catcher);
#   else /* V7_SIGNALS */
		    what kind of signals do you have?
#   endif /* V7_SIGNALS */
#  endif /* BSD41_SIGNALS */
# endif /* BSD42_SIGNALS */
#endif /* POSIX_SIGNALS */
		    close(fdp[1]); /* start child */
		    nread = read(fdc[0], &buf, 1);
		    if (nread == 0)
			exit(4);
		    if (nread > 0)
			exit(5);
		    if (errno != EINTR)
			exit(6);
		    if (!flag)
			exit(7);
		    exit(0);
		    return 0;
		}
	  ], ksh_cv_signals_interrupt=yes, ksh_cv_signals_interrupt=no,
	  AC_MSG_ERROR(cannot determine if signals interrupt read() when cross compiling)
	  )])
      if test $ksh_cv_signals_interrupt = no ; then
	AC_DEFINE(SIGNALS_DONT_INTERRUPT)
      fi
    else
      AC_DEFINE(V7_SIGNALS)
    fi
  fi
 ])dnl
dnl
dnl
dnl
dnl What kind of process groups: POSIX, BSD, SYSV or none
dnl	BSD uses setpgrp(pid, pgrp), getpgrp(pid)
dnl	POSIX uses setpid(pid, pgrp), getpgrp(void)
dnl	SYSV uses setpgrp(void), getpgrp(void)
dnl Checks for BSD first since the posix test may succeed on BSDish systems
dnl (depends on what random value gets passed to getpgrp()).
AC_DEFUN(KSH_PGRP_CHECK,
 [AC_CACHE_CHECK(flavour of pgrp routines, ksh_cv_pgrp_check,
    [AC_TRY_RUN([
/* Check for BSD process groups */
#include <signal.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */
	main()
	{
	  int ecode = 0, child = fork();
	  if (child < 0)
	    exit(1);
	  if (child == 0) {
	    signal(SIGTERM, SIG_DFL); /* just to make sure */
	    sleep(10);
	    exit(9);
	  }
	  if (setpgrp(child, child) < 0)
	    ecode = 2;
	  else if (getpgrp(child) != child)
	    ecode = 3;
	  kill(child, SIGTERM);
	  exit(ecode);
	}
       ], ksh_cv_pgrp_check=bsd,
       [AC_TRY_RUN([
/* Check for POSIX process groups */
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */
	  main()
	  {
	    int child;
	    int n, p1[2], p2[2];
	    char buf[1];
	    if (pipe(p1) < 0 || pipe(p2) < 0)
	      exit(1);
	    if ((child = fork()) < 0)
	      exit(2);
	    if (child == 0) {
	      n = read(p1[0], buf, sizeof(buf)); /* wait for parent to setpgid */
	      buf[0] = (n != 1 ? 10 : (getpgrp() != getpid() ? 11 : 0));
	      if (write(p2[1], buf, sizeof(buf)) != 1)
		exit(12);
	      exit(0);
	    }
	    if (setpgid(child, child) < 0)
	      exit(3);
	    if (write(p1[1], buf, 1) != 1)
	      exit(4);
	    if (read(p2[0], buf, 1) != 1)
	      exit(5);
	    exit((int) buf[0]);
	  }
	 ], ksh_cv_pgrp_check=posix,
	 [AC_TRY_RUN([
/* Check for SYSV process groups */
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */
	    main()
	    {
	      int child;
	      int n, p[2];
	      char buf[1];
	      if (pipe(p) < 0)
		exit(1);
	      if ((child = fork()) < 0)
		exit(2);
	      if (child == 0) {
		buf[0] = (setpgrp() < 0 ? 10 : (getpgrp() != getpid() ? 11 : 0));
		if (write(p[1], buf, sizeof(buf)) != 1)
		  exit(11);
		exit(0);
	      }
	      if (read(p[0], buf, 1) != 1)
		exit(3);
	      exit((int) buf[0]);
	    }
	   ], ksh_cv_pgrp_check=sysv, ksh_cv_pgrp_check=none,
	   AC_MSG_ERROR(cannot taste pgrp routines when cross compiling))],
	   AC_MSG_ERROR(cannot taste pgrp routines when cross compiling))],
	   AC_MSG_ERROR(cannot taste pgrp routines when cross compiling))])
  if test $ksh_cv_pgrp_check = bsd; then
    AC_DEFINE(BSD_PGRP)
  elif test $ksh_cv_pgrp_check = posix; then
    AC_DEFINE(POSIX_PGRP)
  elif test $ksh_cv_pgrp_check = sysv; then
    AC_DEFINE(SYSV_PGRP)
  else
    AC_DEFINE(NO_PGRP)
  fi
 ])dnl
dnl
dnl
dnl
dnl Check if the pgrp of setpgrp() can't be the pid of a zombie process.
dnl On some systems, the kernel doesn't count zombie processes when checking
dnl if a process group is valid, which can cause problems in creating the
dnl pipeline "cmd1 | cmd2": if cmd1 can die (and go into the zombie state)
dnl before cmd2 is started, the kernel doesn't allow the setpgrp() for cmd2
dnl to succeed.  This test defines NEED_PGRP_SYNC if the kernel has this bug.
dnl (pgrp_sync test doesn't mean much if don't have bsd or posix pgrps)
AC_DEFUN(KSH_PGRP_SYNC,
 [AC_REQUIRE([KSH_PGRP_CHECK])dnl
  if test $ksh_cv_pgrp_check = bsd || test $ksh_cv_pgrp_check = posix ; then
   AC_CACHE_CHECK(if process group synchronization is required, ksh_cv_need_pgrp_sync,
      [AC_TRY_RUN([
	  main()
	  {
#ifdef POSIX_PGRP
#  define getpgID()	getpgrp()
#else
#  define getpgID()	getpgrp(0)
#  define setpgid(x,y)	setpgrp(x,y)
#endif
	    int pid1, pid2, fds[2];
	    int status;
	    char ok;
	    switch (pid1 = fork()) {
	      case -1:
		exit(1);
	      case 0:
		setpgid(0, getpid());
		exit(0);
	    }
	    setpgid(pid1, pid1);
	    sleep(2);	/* let first child die */
	    if (pipe(fds) < 0)
	      exit(2);
	    switch (pid2 = fork()) {
	      case -1:
		exit(3);
	      case 0:
		setpgid(0, pid1);
		ok = getpgID() == pid1;
		write(fds[1], &ok, 1);
		exit(0);
	    }
	    setpgid(pid2, pid1);
	    close(fds[1]);
	    if (read(fds[0], &ok, 1) != 1)
	      exit(4);
	    wait(&status);
	    wait(&status);
	    exit(ok ? 0 : 5);
	  }
        ], ksh_cv_need_pgrp_sync=no, ksh_cv_need_pgrp_sync=yes,
	AC_MSG_WARN(cannot test if pgrp synchronization needed when cross compiling - assuming it is)
        ksh_cv_need_pgrp_sync=yes)])
    if test $ksh_cv_need_pgrp_sync = yes; then
      AC_DEFINE(NEED_PGRP_SYNC)
    fi
  fi
 ])dnl
dnl
dnl
dnl
dnl Check to see if opendir will open non-directories (not a nice thing)
AC_DEFUN(KSH_OPENDIR_CHECK,
 [AC_CACHE_CHECK(if opendir() fails to open non-directories, ksh_cv_opendir_ok,
    [AC_TRY_RUN([
#include <stdio.h>
#include <sys/types.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */
#if defined(HAVE_DIRENT_H)
# include <dirent.h>
#else
# define dirent direct
# ifdef SYSNDIR
#  include <sys/ndir.h>
# endif /* SYSNDIR */
# ifdef SYSDIR
#  include <sys/dir.h>
# endif /* SYSDIR */
# ifdef NDIR
#  include <ndir.h>
# endif /* NDIR */
#endif /* DIRENT */
	main()
	{
	  int i, ret = 0;
	  FILE *fp;
	  char *fname = "conftestod", buf[256];
	  for (i = 0; i < sizeof(buf); i++) /* memset(buf, 0, sizeof(buf)) */
	    buf[i] = 0;
	  unlink(fname); /* paranoia */
	  i = ((fp = fopen(fname, "w")) == (FILE *) 0 && (ret = 1))
	       || (fwrite(buf, sizeof(buf), 1, fp) != 1 && (ret = 2))
	       || (fclose(fp) == EOF && (ret = 3))
	       || (opendir(fname) && (ret = 4))
	       || (opendir("/dev/null") && (ret = 5));
	  unlink(fname);
	  exit(ret);
	}
      ], ksh_cv_opendir_ok=yes, ksh_cv_opendir_ok=no,
      AC_MSG_WARN(cannot test if opendir opens non-directories when cross compiling - assuming it does)
      ksh_cv_opendir_ok=no)])
  if test $ksh_cv_opendir_ok = no; then
    AC_DEFINE(OPENDIR_DOES_NONDIR)
  fi
 ])dnl
dnl
dnl
dnl
dnl Like AC_HAVE_HEADER(unistd.h) but only defines HAVE_UNISTD_H if
dnl the header file is sane (MIPS RISC/os 5.0 (and later?) has a unistd.h
dnl in the bsd43 environ that is incorrect - it defines POSIX_VERSION even
dnl though its non-posix).
AC_DEFUN(KSH_UNISTD_H,
 [AC_CACHE_CHECK(for sane unistd.h, ksh_cv_header_unistd,
    [AC_TRY_COMPILE([
#include <unistd.h>
#if defined(_POSIX_VERSION)
# include <sys/types.h>
# include <dirent.h> /* _POSIX_VERSION => HAVE_DIRENT_H test not needed */
#endif
      ], , ksh_cv_header_unistd=yes, ksh_cv_header_unistd=no)])
  if test $ksh_cv_header_unistd = yes; then
    AC_DEFINE(HAVE_UNISTD_H)
  fi
 ])dnl
dnl
dnl
dnl
dnl Several OSes need to be detected and symbols defined so the shell can
dnl deal with them.  This is a bit kludgy, but...
dnl Currently tests for:
dnl	AIX, ISC (Interactive systems corp), MINIX, OS2 using EMX library,
dnl	SCO (santa cruz operation), NEXT
dnl DO NOT USE with AC_AIX, AC_MINIX or AC_ISC_POSIX tests as these are
dnl incorperated in this test.
AC_DEFUN(KSH_OS_TYPE,
 [AC_BEFORE([$0], [AC_TRY_COMPILE])dnl
  AC_BEFORE([$0], [AC_TRY_LINK])dnl
  AC_BEFORE([$0], [AC_TRY_RUN])dnl
  AC_CACHE_CHECK(if this is a problematic os, ksh_cv_os_type,
    [ ksh_cv_os_type=no
      # Some tests below add -C to CPPFLAGS
      saveCPPFLAGS="$CPPFLAGS"
      for i in AIX ISC MINIX SCO OS2_EMX TITANOS NEXT HPUX; do
	case $i in	#((
	  AIX)
	    AC_EGREP_CPP(yes,
	      [
#ifdef _AIX
yes
#endif
	       ], ksh_cv_os_type=$i)
	    ;;	#(
	  ISC)
	    # Both native ISC cpp and gcc understand this (leave comments in)
	    CPPFLAGS="$CPPFLAGS -C"
	    #XXX grep part won't work if cross-compiling...
	    AC_EGREP_CPP(INTERACTIVE Systems Corporation,
	      [#include <unistd.h>],
		[if grep _POSIX_VERSION /usr/include/sys/unistd.h > /dev/null 2>&1; then
		  ksh_cv_os_type="$i-posix"
		else
		  ksh_cv_os_type=$i
		fi])dnl
	    CPPFLAGS="$saveCPPFLAGS"
	    ;;	#(
	  MINIX)
	    AC_CHECK_HEADER(minix/config.h, ksh_cv_os_type=$i)dnl
	    ;;	#(
	  SCO)
	    # Both native SCO cpp and gcc understand this (leave comments in)
	    CPPFLAGS="$CPPFLAGS -C"
	    AC_EGREP_CPP(The Santa Cruz Operation,
	      [#include <unistd.h>], ksh_cv_os_type=$i)dnl
	    CPPFLAGS="$saveCPPFLAGS"
	    ;;	#(
	  OS2_EMX)
	    AC_EGREP_CPP(yes,
	      [
#ifdef __EMX__
yes
#endif
	       ], ksh_cv_os_type=$i)dnl
	    ;;	#(
	  TITANOS)
	    AC_EGREP_CPP(YesTitan,
	      [
#if defined(titan) || defined(_titan) || defined(__titan)
YesTitan
#endif
	       ], ksh_cv_os_type=$i)dnl
	    ;;	#(
	  NEXT)
	    #
	    # NeXT 3.2 (other versions?) - cc -E doesn't work and /lib/cpp
	    # doesn't define things that need defining, so tests that rely
	    # on $CPP will break.
	    #
	    # Hmmm - can't safely use CPP to test for NeXT defines, so have
	    # to use a program that won't compile on a NeXT and one that will
	    # only compile on a NeXT...
	    AC_TRY_COMPILE([], [
	        #if defined(__NeXT) || defined(NeXT)
		  this is a NeXT box and the compile should fail
	        #endif
	      ], , AC_TRY_COMPILE([], [
		  #if !defined(__NeXT) && !defined(NeXT)
		    this is NOT a NeXT box and the compile should fail
		  #endif
		], ksh_cv_os_type=$i))dnl
	    ;;	#(
	  HPUX)
	    AC_EGREP_CPP(yes,
	      [
#ifdef __hpux
yes
#endif
	       ], ksh_cv_os_type=$i)
	    ;;	#(
	esac		#))
	test $ksh_cv_os_type != no && break
      done
    ])
  case $ksh_cv_os_type in	#((
    AIX)
      AC_DEFINE(_ALL_SOURCE)dnl
      ;;			#(
    ISC)
      AC_DEFINE(OS_ISC)dnl
      ;;			#(
    ISC-posix)
      AC_DEFINE(OS_ISC)dnl
      AC_DEFINE(_POSIX_SOURCE)dnl
      if test "$GCC" = yes; then
	CC="$CC -posix"
      else
	CC="$CC -Xp"
      fi
      ;;			#(
    MINIX)
      AC_DEFINE(_POSIX_SOURCE)dnl
      AC_DEFINE(_POSIX_1_SOURCE, 2)dnl
      AC_DEFINE(_MINIX)dnl
      ;;			#(
    SCO)
      AC_DEFINE(OS_SCO)dnl
      ;;			#(
    OS2_EMX)
      # XXX change this to OS_OS2 or OS_OS2_EMX?
      AC_DEFINE(OS2)dnl
      ac_exe_suffix=.exe
      ;;			#(
    TITANOS)
      # Need to use cc -43 to get a shell with job control
      case "$CC" in		#((
        *-43*)  			# Already have -43 option?
	  ;;			#(
	*/cc|*/cc' '|*/cc'	'|cc|cc' '|cc'	') # Using stock compiler?
	  CC="$CC -43"
	  ;;			#(
      esac			#))
      #
      # Force dirent check to find the right thing.  There is a dirent.h
      # (and a sys/dirent.h) file which compiles, but generates garbage...
      # 
      ac_cv_header_dirent_dirent_h=no
      ac_cv_header_dirent_sys_ndir_h=no
      ac_cv_header_dirent_sys_dir_h=yes
      ;;			#(
    NEXT)
      #
      # NeXT 3.2 (other versions?) - cc -E doesn't work and /lib/cpp
      # doesn't define things that need defining, so tests that rely
      # on $CPP will break.
      #
      AC_EGREP_CPP([Bad NeXT], [#include <signal.h>
	#if !defined(SIGINT) || !defined(SIGQUIT)
	    Bad NeXT
	#endif
	], AC_MSG_ERROR([
There is a problem on NeXT boxes resulting in a bad siglist.out file being
generated (which breaks the trap and kill commands) and probably resulting
in many configuration tests not working correctly.

You appear to have this problem - see the comments on NeXT in the pdksh
README file for work arounds.]))dnl
      ;;			#(
    HPUX)
      #
      # In some versions of hpux (eg, 10.2), getwd & getcwd will dump core
      # if directory is not readble.
      #
      # name is used in test program
      AC_CACHE_CHECK(for bug in getwd, ksh_cv_hpux_getwd_bug,
	[ tmpdir=conftest.dir
	  if mkdir $tmpdir ; then
	    AC_TRY_RUN([
		int
		main()
		{
		  char buf[8 * 1024];
		  char *dirname = "conftest.dir";
		  int ok = 0;
		  if (chdir(dirname) < 0)
		    exit(2);
		  if (chmod(".", 0) < 0)
		    exit(3);
		  /* Test won't work if run as root - so don't be root */
		  if (getuid() == 0 || geteuid() == 0)
		    setresuid(1, 1, 1);	/* hpux has this */
#ifdef HAVE_GETWD /* silly since HAVE_* tests haven't been done yet */
		  {
		      extern char *getwd();
		      ok = getwd(buf) == 0;
		  }
#else
		  {
		      extern char *getcwd();
		      ok = getcwd(buf, sizeof(buf)) == 0;
		  }
#endif
		  exit(ok ? 0 : 10);
		  return ok ? 0 : 10;
		}],
	       ksh_cv_hpux_getwd_bug=no, ksh_cv_hpux_getwd_bug=yes,
	       AC_MSG_WARN(assuming getwd broken); ksh_cv_hpux_getwd_bug=yes)
	       test -d $tmpdir && rmdir $tmpdir
	  else
	     AC_MSG_ERROR(could not make temp directory for test); ksh_cv_hpux_getwd_bug=yes
	  fi])
      if test $ksh_cv_hpux_getwd_bug = yes; then
	AC_DEFINE(HPUX_GETWD_BUG)
      fi
      ;;			#(
  esac				#))
 ])dnl
dnl
dnl
dnl
dnl Some systems (eg, SunOS 4.0.3) have <termios.h> and <termio.h> but don't
dnl have the related functions/defines (eg, tcsetattr(), TCSADRAIN, etc.)
dnl or the functions don't work well with tty process groups.  Sun's bad
dnl termios can be detected by the lack of tcsetattr(), but its bad termio
dnl is harder to detect - so check for (sane) termios first, then check for
dnl BSD, then termio.
AC_DEFUN(KSH_TERM_CHECK,
 [AC_CACHE_CHECK(terminal interface, ksh_cv_term_check,
    [AC_TRY_LINK([#include <termios.h>], [
        struct termios t;
#if defined(ultrix) || defined(__ultrix__)
         Termios in ultrix 4.2 botches type-ahead when going from cooked to
         cbreak mode.  The BSD tty interface works fine though, so use it
         (would be good to know if alter versions of ultrix work).
#endif /* ultrix */
         tcgetattr(0, &t); tcsetattr(0, TCSADRAIN, &t);
      ], ksh_cv_term_check=termios,
	[AC_TRY_LINK([#include <sys/ioctl.h>], [
	    struct sgttyb sb; ioctl(0, TIOCGETP, &sb);
#ifdef TIOCGATC
	    { struct ttychars lc; ioctl(0, TIOCGATC, &lc); }
#else /* TIOCGATC */
	    { struct tchars tc; ioctl(0, TIOCGETC, &tc); }
# ifdef TIOCGLTC
	    { struct ltchars ltc; ioctl(0, TIOCGLTC, &ltc); }
# endif /* TIOCGLTC */
#endif /* TIOCGATC */
	  ], ksh_cv_term_check=bsd,
	    [AC_CHECK_HEADER(termio.h, ksh_cv_term_check=termio,
	      ksh_cv_term_check=sgtty)])])])
  if test $ksh_cv_term_check = termios; then
    AC_DEFINE(HAVE_TERMIOS_H)
dnl Don't know of a system on which this fails...
dnl     AC_CACHE_CHECK(sys/ioctl.h can be included with termios.h,
dnl       ksh_cv_sys_ioctl_with_termios,
dnl       [AC_TRY_COMPILE([#include <termios.h>
dnl #include <sys/ioctl.h>], , ksh_cv_sys_ioctl_with_termios=yes,
dnl 	ksh_cv_sys_ioctl_with_termios=no)])
dnl     if test $ksh_cv_sys_ioctl_with_termios = yes; then
dnl       AC_DEFINE(SYS_IOCTL_WITH_TERMIOS)
dnl     fi
  elif test $ksh_cv_term_check = termio; then
    AC_DEFINE(HAVE_TERMIO_H)
dnl Don't know of a system on which this fails...
dnl     AC_CACHE_CHECK(sys/ioctl.h can be included with termio.h,
dnl       ksh_cv_sys_ioctl_with_termio,
dnl       [AC_TRY_COMPILE([#include <termio.h>
dnl #include <sys/ioctl.h>], , ksh_cv_sys_ioctl_with_termio=yes,
dnl 	ksh_cv_sys_ioctl_with_termio=no)])
dnl     if test $ksh_cv_sys_ioctl_with_termio = yes; then
dnl       AC_DEFINE(SYS_IOCTL_WITH_TERMIO)
dnl     fi
  fi
 ])dnl
dnl
dnl
dnl
dnl  Check if lstat() is available - special test needed 'cause lstat only
dnl becomes visable if <sys/stat.h> is included (linux 1.3.x)...
AC_DEFUN(KSH_FUNC_LSTAT,
[AC_CACHE_CHECK(for lstat, ksh_cv_func_lstat,
[AC_TRY_LINK([
#include <sys/types.h>
#include <sys/stat.h>
	], [
	  struct stat statb;
	  lstat("/", &statb);
	],
       ksh_cv_func_lstat=yes, ksh_cv_func_lstat=no)])
if test $ksh_cv_func_lstat = yes; then
  AC_DEFINE(HAVE_LSTAT)
fi
])
dnl
dnl
dnl
dnl Modified test from autoconf's acspecific.m4: MMAP test needs to check
dnl for/use the MAP_FILE flag. (Needed for older NetBSD systems).
undefine([AC_FUNC_MMAP])dnl
AC_DEFUN(AC_FUNC_MMAP,
[AC_CHECK_FUNCS(valloc getpagesize)
AC_CACHE_CHECK(for working mmap, ac_cv_func_mmap,
[AC_TRY_RUN([
/* Thanks to Mike Haertel and Jim Avera for this test. */
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>

#ifndef HAVE_GETPAGESIZE
# include <sys/param.h>
# ifdef EXEC_PAGESIZE
#  define getpagesize() EXEC_PAGESIZE
# else
#  ifdef NBPG
#   define getpagesize() NBPG * CLSIZE
#   ifndef CLSIZE
#    define CLSIZE 1
#   endif
#  else
#   ifdef NBPC
#    define getpagesize() NBPC
#   else
#    define getpagesize() PAGESIZE /* SVR4 */
#   endif
#  endif
# endif
#endif

#ifndef HAVE_VALLOC
# define valloc malloc
#endif

#ifdef __cplusplus
extern "C" { void *valloc(unsigned), *malloc(unsigned); }
#else
char *valloc(), *malloc();
#endif

#ifndef MAP_FILE
# define MAP_FILE 0
#endif /* MAP_FILE */

int
main()
{
  char *buf1, *buf2, *buf3;
  int i = getpagesize(), j;
  int i2 = i * 2;
  int fd;

  buf1 = (char *)valloc(i2);
  buf2 = (char *)valloc(i);
  buf3 = (char *)malloc(i2);
  for (j = 0; j < i2; ++j)
    *(buf1 + j) = rand();
  fd = open("conftestmmap", O_CREAT | O_RDWR, 0666);
  write(fd, buf1, i2);
  mmap(buf2, i, PROT_READ | PROT_WRITE, MAP_FILE | MAP_FIXED | MAP_PRIVATE, fd, 0);
  for (j = 0; j < i; ++j)
    if (*(buf1 + j) != *(buf2 + j))
      exit(1);
  lseek(fd, (long)i, 0);
  read(fd, buf2, i); /* read into mapped memory -- file should not change */
  /* (it does in i386 SVR4.0 - Jim Avera, jima@netcom.com) */
  lseek(fd, (long)0, 0);
  read(fd, buf3, i2);
  for (j = 0; j < i2; ++j)
    if (*(buf1 + j) != *(buf3 + j))
      exit(1);
  exit(0);
}
], ac_cv_func_mmap=yes, ac_cv_func_mmap=no, ac_cv_func_mmap=no)])
if test $ac_cv_func_mmap = yes; then
  AC_DEFINE(HAVE_MMAP)
fi
])
dnl
dnl
dnl
dnl Modified AC_LANG_C, AC_LANG_CPLUSPLUS, AC_TRY_RUN to handle executable
dnl extensions.
undefine([AC_LANG_C])dnl
undefine([AC_LANG_CPLUXPLUS])dnl
undefine([AC_TRY_RUN])dnl
dnl AC_LANG_C()
AC_DEFUN(AC_LANG_C,
[define([AC_LANG], [C])dnl
ac_ext=c
# CFLAGS is not in ac_cpp because -g, -O, etc. are not valid cpp options.
ac_cpp='echo $CPP $CPPFLAGS 1>&AC_FD_CC;
$CPP $CPPFLAGS'
ac_compile='echo ${CC-cc} -c $CFLAGS $CPPFLAGS conftest.$ac_ext 1>&AC_FD_CC;
${CC-cc} -c $CFLAGS $CPPFLAGS conftest.$ac_ext 1>&AC_FD_CC 2>&AC_FD_CC'
ac_link='echo ${CC-cc} -o conftest$ac_exe_suffix $CFLAGS $CPPFLAGS $LDFLAGS conftest.$ac_ext $LIBS 1>&AC_FD_CC;
${CC-cc} -o conftest$ac_exe_suffix $CFLAGS $CPPFLAGS $LDFLAGS conftest.$ac_ext $LIBS 1>&AC_FD_CC 2>&AC_FD_CC'
])

dnl AC_LANG_CPLUSPLUS()
AC_DEFUN(AC_LANG_CPLUSPLUS,
[define([AC_LANG], [CPLUSPLUS])dnl
ac_ext=C
# CXXFLAGS is not in ac_cpp because -g, -O, etc. are not valid cpp options.
ac_cpp='echo $CXXCPP $CPPFLAGS 1>&AC_FD_CC;
$CXXCPP $CPPFLAGS'
ac_compile='echo ${CXX-g++} -c $CXXFLAGS $CPPFLAGS conftest.$ac_ext 1>&AC_FD_CC;
${CXX-g++} -c $CXXFLAGS $CPPFLAGS conftest.$ac_ext 1>&AC_FD_CC 2>&AC_FD_CC'
ac_link='echo ${CXX-g++} -o conftest$ac_exe_suffix $CXXFLAGS $CPPFLAGS $LDFLAGS conftest.$ac_ext $LIBS 1>&AC_FD_CC;
${CXX-g++} -o conftest$ac_exe_suffix $CXXFLAGS $CPPFLAGS $LDFLAGS conftest.$ac_ext $LIBS 1>&AC_FD_CC 2>&AC_FD_CC'
])
dnl AC_TRY_RUN(PROGRAM, [ACTION-IF-TRUE [, ACTION-IF-FALSE
dnl            [, ACTION-IF-CROSS-COMPILING]]])
AC_DEFUN(AC_TRY_RUN,
[AC_REQUIRE([AC_PROG_CC])dnl
if test "$cross_compiling" = yes; then
  ifelse([$4], ,
    [errprint(__file__:__line__: warning: [AC_TRY_RUN] called without default to allow cross compiling
)dnl
  AC_MSG_ERROR(can not run test program while cross compiling)],
  [$4])
else
cat > conftest.$ac_ext <<EOF
[#]line __oline__ "configure"
#include "confdefs.h"
ifelse(AC_LANG, CPLUSPLUS, [#ifdef __cplusplus
extern "C" void exit(int);
#endif
])dnl
[$1]
EOF
eval $ac_link
if test -s conftest$ac_exe_suffix && (./conftest; exit) 2>/dev/null; then
  ifelse([$2], , :, [$2])
ifelse([$3], , , [else
  $3
])dnl
fi
fi
rm -fr conftest*])
dnl
dnl
dnl Like AC_HEADER_SYS_WAIT, only HAVE_SYS_WAIT_H if sys/wait.h exists and
dnl defines POSIX_SYS_WAIT if it is posix compatable.  This way things
dnl like WNOHANG, WUNTRACED can still be used.
AC_DEFUN(KSH_HEADER_SYS_WAIT,
[AC_CACHE_CHECK([for sys/wait.h that is POSIX.1 compatible], ksh_cv_header_sys_wait_h,
[AC_TRY_COMPILE([#include <sys/types.h>
#include <sys/wait.h>
#ifndef WEXITSTATUS
#define WEXITSTATUS(stat_val) ((unsigned)(stat_val) >> 8)
#endif
#ifndef WIFEXITED
#define WIFEXITED(stat_val) (((stat_val) & 255) == 0)
#endif], [int s;
wait (&s);
s = WIFEXITED (s) ? WEXITSTATUS (s) : 1;],
ksh_cv_header_sys_wait_h=yes, ksh_cv_header_sys_wait_h=no)])
if test $ksh_cv_header_sys_wait_h = yes; then
  AC_DEFINE(POSIX_SYS_WAIT)dnl
  AC_DEFINE(HAVE_SYS_WAIT_H)dnl
else
  AC_CHECK_HEADERS(sys/wait.h)dnl
fi
])
dnl
dnl
dnl Modified test from autoconf's acspecific.m4(AC_HEADER_STAT) test: need
dnl to check if S_ISSOCK == S_ISFIFO (FreeBSD).
undefine([AC_HEADER_STAT])dnl
AC_DEFUN(AC_HEADER_STAT,
[AC_CACHE_CHECK(whether stat file-mode macros are broken,
  ac_cv_header_stat_broken,
[AC_EGREP_CPP([You lose], [#include <sys/types.h>
#include <sys/stat.h>

#if defined(S_ISBLK) && defined(S_IFDIR)
# if S_ISBLK (S_IFDIR)
You lose.
# endif
#endif

#if defined(S_ISBLK) && defined(S_IFCHR)
# if S_ISBLK (S_IFCHR)
You lose.
# endif
#endif

#if defined(S_ISLNK) && defined(S_IFREG)
# if S_ISLNK (S_IFREG)
You lose.
# endif
#endif

#if defined(S_ISSOCK) && defined(S_IFREG)
# if S_ISSOCK (S_IFREG)
You lose.
# endif
#endif

#if defined(S_ISSOCK) && defined(S_IFIFO)
# if S_ISSOCK (S_IFIFO)
You lose.
# endif
#endif
], ac_cv_header_stat_broken=yes, ac_cv_header_stat_broken=no)])
if test $ac_cv_header_stat_broken = yes; then
  AC_DEFINE(STAT_MACROS_BROKEN)
fi
])
dnl
dnl
dnl Need to change the "accepts -g" test - some broken systems
dnl allow "cc -c -g ..." but fail on the link (missing -lg).
dnl LaserMoon's linux/FT is such a broken system...
undefine([AC_PROG_CC])dnl
AC_DEFUN(AC_PROG_CC,
[AC_BEFORE([$0], [AC_PROG_CPP])dnl
AC_CHECK_PROG(CC, gcc, gcc, cc)

AC_CACHE_CHECK(whether we are using GNU C, ac_cv_prog_gcc,
[dnl The semicolon is to pacify NeXT's syntax-checking cpp.
cat > conftest.c <<EOF
#ifdef __GNUC__
  yes;
#endif
EOF
if ${CC-cc} -E conftest.c 2>&AC_FD_CC | egrep yes >/dev/null 2>&1; then
  ac_cv_prog_gcc=yes
else
  ac_cv_prog_gcc=no
fi])
if test $ac_cv_prog_gcc = yes; then
  GCC=yes
  if test "${CFLAGS+set}" != set; then
    AC_CACHE_CHECK(whether ${CC-cc} accepts -g, ac_cv_prog_gcc_g,
[echo 'int main(){ return 0; }' > conftest.c
if test -z "`${CC-cc} -g conftest.c 2>&1`"; then
  ac_cv_prog_gcc_g=yes
else
  ac_cv_prog_gcc_g=no
fi
rm -f conftest*
])
    if test $ac_cv_prog_gcc_g = yes; then
      CFLAGS="-g -O"
    else
      CFLAGS="-O"
    fi
  fi
else
  GCC=
  test "${CFLAGS+set}" = set || CFLAGS="-g"
fi
])
dnl
dnl
dnl Need to change to check for ndir
dnl
undefine([AC_HEADER_DIRENT])dnl
AC_DEFUN(AC_HEADER_DIRENT,
[ac_header_dirent=no
AC_CHECK_HEADERS_DIRENT(dirent.h sys/ndir.h sys/dir.h ndir.h,
  [ac_header_dirent=$ac_hdr; break])
# Two versions of opendir et al. are in -ldir and -lx on SCO Xenix.
if test $ac_header_dirent = dirent.h; then
AC_CHECK_LIB(dir, opendir, LIBS="$LIBS -ldir", AC_CHECK_LIB(ndir, opendir, LIBS="$LIBS -lndir"))
else
AC_CHECK_LIB(x, opendir, LIBS="$LIBS -lx")
fi
])      
