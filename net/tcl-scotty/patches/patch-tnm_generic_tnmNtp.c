$NetBSD: patch-tnm_generic_tnmNtp.c,v 1.1 2014/03/05 13:52:29 he Exp $

Avoid use of interp->result.
Constify.

--- tnm/generic/tnmNtp.c~	1996-09-18 23:33:54.000000000 +0200
+++ tnm/generic/tnmNtp.c	2014-03-04 16:04:08.000000000 +0100
@@ -74,7 +74,7 @@
 			     int op, int retries, int timeo,
 			     char *buf, int assoc));
 static int
-NtpSplit	_ANSI_ARGS_((Tcl_Interp *interp, char *varname,
+NtpSplit	_ANSI_ARGS_((Tcl_Interp *interp, const char *varname,
 			     char *pfix, char *buf));
 static int 
 NtpGetPeer	_ANSI_ARGS_((char *data, int *assoc));
@@ -349,11 +349,12 @@
 static int
 NtpSplit(interp, varname, pfix, buf)
     Tcl_Interp *interp;
-    char *varname;
+    const char *varname;
     char *pfix;
     char *buf;
 {
-    char *d, *s, *g, *r;
+    char *d, *s, *g;
+    const char *r;
     char var [256];
 
     for (s = buf, d = buf; *s; s++) {
@@ -440,9 +441,9 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char *argv[];
+    const char *argv[];
 {
-    char *cmd = argv[0];
+    const char *cmd = argv[0];
     struct sockaddr_in daddr;
     int code, assoc;
     char data1 [1024], data2 [1024];
@@ -472,10 +473,13 @@
     argc--; argv++;
 
     while (argc > 0 && (*argv[0] == '-')) {
+        char res[20];
+
 	if (strcmp(argv [0], "-retries") == 0) {
 	    argc--, argv++;
 	    if (argc < 1) {
-	        sprintf(interp->result, "%d", control->retries);
+	        sprintf(res, "%d", control->retries);
+		Tcl_SetResult(interp, res, TCL_VOLATILE);
 		return TCL_OK;
 	    }
 	    if (TnmGetUnsigned(interp, argv[0], &actRetries) != TCL_OK) {
@@ -484,7 +488,8 @@
 	} else if (strcmp(argv [0], "-timeout") == 0) {
 	    argc--, argv++;
 	    if (argc < 1) {
-	        sprintf(interp->result, "%d", control->timeout);
+	        sprintf(res, "%d", control->timeout);
+		Tcl_SetResult(interp, res, TCL_VOLATILE);
 		return TCL_OK;
 	    }
 	    if (TnmGetPositive(interp, argv [0], &actTimeout) != TCL_OK) {
