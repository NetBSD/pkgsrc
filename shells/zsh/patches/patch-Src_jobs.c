$NetBSD: patch-Src_jobs.c,v 1.1 2022/11/06 20:58:00 wiz Exp $

Candidate fix for shell function pipeline bg/fg issue, from
https://zsh.org/mla/workers/2022/msg01204.html

--- Src/jobs.c.orig	2022-05-08 06:18:22.000000000 +0000
+++ Src/jobs.c
@@ -544,16 +544,14 @@ update_job(Job jn)
 
     if (isset(MONITOR)) {
 	pid_t pgrp = gettygrp();           /* get process group of tty      */
+	int deadpgrp = (mypgrp != pgrp && inforeground && pgrp > 1 &&
+			kill(-pgrp, 0) == -1 && errno == ESRCH);
 
 	/* is this job in the foreground of an interactive shell? */
 	if (mypgrp != pgrp && inforeground &&
-	    (jn->gleader == pgrp ||
-	     (pgrp > 1 &&
-	      (kill(-pgrp, 0) == -1 && errno == ESRCH)))) {
+	    ((jn->gleader == pgrp && signalled) || deadpgrp)) {
 	    if (list_pipe) {
-		if (somestopped || (pgrp > 1 &&
-				    kill(-pgrp, 0) == -1 &&
-				    errno == ESRCH)) {
+		if (somestopped || deadpgrp) {
 		    attachtty(mypgrp);
 		    /* check window size and adjust if necessary */
 		    adjustwinsize(0);
@@ -566,6 +564,12 @@ update_job(Job jn)
 		     * when the job is finally deleted.
 		     */
 		    jn->stat |= STAT_ATTACH;
+		    /*
+		     * If we're in shell jobs on the right side of a pipeline
+		     * we should treat it like a job in the current shell.
+		     */
+		    if (inforeground == 2)
+			inforeground = 1;
 		}
 		/* If we have `foo|while true; (( x++ )); done', and hit
 		 * ^C, we have to stop the loop, too. */
@@ -1488,10 +1492,7 @@ addproc(pid_t pid, char *text, int aux, 
 	 * set it for that, too.
 	 */
 	if (gleader != -1) {
-	    if (jobtab[thisjob].stat & STAT_CURSH)
-		jobtab[thisjob].gleader = gleader;
-	    else
-		jobtab[thisjob].gleader = pid;
+	    jobtab[thisjob].gleader = gleader;
 	    if (list_pipe_job_used != -1)
 		jobtab[list_pipe_job_used].gleader = gleader;
 	    /*
@@ -1500,7 +1501,7 @@ addproc(pid_t pid, char *text, int aux, 
 	     */
 	    last_attached_pgrp = gleader;
 	} else if (!jobtab[thisjob].gleader)
-		jobtab[thisjob].gleader = pid;
+	    jobtab[thisjob].gleader = pid;
 	/* attach this process to end of process list of current job */
 	pnlist = &jobtab[thisjob].procs;
     }
@@ -2488,6 +2489,7 @@ bin_fg(char *name, char **argv, Options 
 		jobtab[job].stat &= ~STAT_CURSH;
 	    }
 	    if ((stopped = (jobtab[job].stat & STAT_STOPPED))) {
+		/* WIFCONTINUED will makerunning() again at killjb() */
 		makerunning(jobtab + job);
 		if (func == BIN_BG) {
 		    /* Set $! to indicate this was backgrounded */
