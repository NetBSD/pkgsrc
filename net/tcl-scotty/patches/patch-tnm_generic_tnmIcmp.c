$NetBSD: patch-tnm_generic_tnmIcmp.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnmIcmp.c~	1998-12-17 12:59:55.000000000 +0100
+++ tnm/generic/tnmIcmp.c	2014-03-04 15:27:10.000000000 +0100
@@ -35,7 +35,7 @@
 AssocDeleteProc	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp));
 
 static int
-IcmpRequest	_ANSI_ARGS_((Tcl_Interp *interp, char *hosts, int type, 
+IcmpRequest	_ANSI_ARGS_((Tcl_Interp *interp, const char *hosts, int type, 
 			     int ttl, int timeout, int retries, int delay,
 			     int size));
 
@@ -88,11 +88,11 @@
 static int
 IcmpRequest(interp, hosts, type, ttl, timeout, retries, delay, size)
     Tcl_Interp *interp;
-    char *hosts;
+    const char *hosts;
     int type, ttl, timeout, retries, delay, size;
 {
     int i, code, largc, len;
-    char **largv;
+    const char **largv;
     TnmIcmpRequest *icmpPtr;
     
     code = Tcl_SplitList(interp, hosts, &largc, &largv);
@@ -154,7 +154,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int actTimeout = -1;	/* actually used timeout */
     int actRetries = -1;	/* actually used retries */
@@ -164,7 +164,7 @@
     int type = 0;		/* the request type */
     int ttl = -1;		/* the time to live field */
 
-    char *cmdName = argv[0];
+    char const *cmdName = argv[0];
 
     IcmpControl *control = (IcmpControl *) 
 	Tcl_GetAssocData(interp, tnmIcmpControl, NULL);
@@ -193,11 +193,13 @@
 
     argc--; argv++;
     while (argc > 0 && (*argv[0] == '-')) {
+        char res[20];
 	if (strcmp(argv[0], "-retries") == 0) {
 	    argc--, argv++;
 	    if (argc < 1) {
-		sprintf(interp->result, "%d", control->retries);
-                return TCL_OK;
+	      sprintf(res, "%d", control->retries);
+	      Tcl_SetResult(interp, res, TCL_VOLATILE);
+	      return TCL_OK;
 	    }
 	    if (TnmGetUnsigned(interp, argv[0], &actRetries) != TCL_OK)
 	        return TCL_ERROR;
@@ -205,7 +207,8 @@
 	} else 	if (strcmp(argv[0], "-timeout") == 0) {
 	    argc--, argv++;
 	    if (argc < 1) {
-		sprintf(interp->result, "%d", control->timeout);
+	        sprintf(res, "%d", control->timeout);
+	        Tcl_SetResult(interp, res, TCL_VOLATILE);
                 return TCL_OK;
 	    }
 	    if (TnmGetPositive(interp, argv[0], &actTimeout) != TCL_OK) {
@@ -215,8 +218,9 @@
 	} else 	if (strcmp(argv[0], "-size") == 0) {
 	    argc--, argv++;
 	    if (argc < 1) {
-		sprintf(interp->result, "%d", control->size);
-		return TCL_OK;
+	      sprintf(res, "%d", control->size);
+	      Tcl_SetResult(interp, res, TCL_VOLATILE);
+	      return TCL_OK;
 	    }
 	    if (TnmGetUnsigned(interp, argv[0], &actSize) != TCL_OK) {
                 return TCL_ERROR;
@@ -226,7 +230,8 @@
 	} else  if (strcmp(argv[0], "-delay") == 0) {
 	    argc--, argv++;
 	    if (argc < 1) {
-		sprintf(interp->result, "%d", control->delay);
+	        sprintf(res, "%d", control->delay);
+	        Tcl_SetResult(interp, res, TCL_VOLATILE);
 		return TCL_OK;
 	    }
 	    if (TnmGetUnsigned(interp, argv[0], &actDelay) != TCL_OK)
