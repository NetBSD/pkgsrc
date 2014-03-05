$NetBSD: patch-tnm_generic_tnmJob.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnmJob.c~	1999-12-02 09:52:56.000000000 +0100
+++ tnm/generic/tnmJob.c	2014-03-05 10:06:11.000000000 +0100
@@ -96,20 +96,20 @@
 Schedule	_ANSI_ARGS_((Tcl_Interp *interp, JobControl *control));
 
 static int
-CreateJob	_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+CreateJob	_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 static int
 Attributes	_ANSI_ARGS_((Job *jobPtr, Tcl_Interp *interp, 
-			     int argc, char **argv));
-static char *
+			     int argc, const char **argv));
+static const char *
 GetOption	_ANSI_ARGS_((Tcl_Interp *interp, ClientData object, 
 			     int option));
 static int
 SetOption	_ANSI_ARGS_((Tcl_Interp *interp, ClientData object, 
-			     int option, char *value));
+			     int option, const char *value));
 static int
 JobCmd		_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 
 /*
  * The options used to configure job objects.
@@ -481,7 +481,7 @@
   repeat:
     for (jobPtr = control->jobList; jobPtr != NULL; jobPtr = jobPtr->nextPtr) {
         if (jobPtr->status == TNM_JOB_EXPIRED) {
-	    char *name = Tcl_GetCommandName(interp, jobPtr->token);
+	    const char *name = Tcl_GetCommandName(interp, jobPtr->token);
 #if 0
 	    char cmd[40];
 	    sprintf(cmd, "event raise %s", name);
@@ -523,7 +523,7 @@
 CreateJob(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     static unsigned lastid = 0;
     Job *jobPtr, *p;
@@ -603,7 +603,7 @@
     Job *jobPtr;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_HashTable *tablePtr = &(jobPtr->attributes);
     Tcl_HashEntry *entryPtr;
@@ -655,7 +655,7 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 GetOption(interp, object, option)
     Tcl_Interp *interp;
     ClientData object;
@@ -709,7 +709,7 @@
     Tcl_Interp *interp;
     ClientData object;
     int option;
-    char *value;
+    const char *value;
 {
     Job *jobPtr = (Job *) object;
     int num, status;
@@ -783,7 +783,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int result = TCL_OK;
     Job *job = (Job *) clientData;
@@ -831,7 +831,7 @@
 	if (control) {
 	repeat:
 	    for (job = control->jobList; job; job = job->nextPtr) {
-		char *name = Tcl_GetCommandName(interp, job->token);
+		const char *name = Tcl_GetCommandName(interp, job->token);
 		if (job->status == TNM_JOB_WAITING 
 		    && (strcmp(name, argv[0]) == 0)) {
 		    Tcl_DoOneEvent(0);
@@ -878,7 +878,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Job *job;
     JobControl *control = (JobControl *) 
@@ -914,7 +914,7 @@
 	}
 	if (currentJob && currentJob->interp == interp) {
 	    Tcl_SetResult(interp, 
-			  Tcl_GetCommandName(interp, currentJob->token),
+			  (char*)Tcl_GetCommandName(interp, currentJob->token),
 			  TCL_VOLATILE);
 	}
 	return TCL_OK;
