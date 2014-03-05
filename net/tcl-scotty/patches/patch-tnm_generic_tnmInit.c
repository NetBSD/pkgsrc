$NetBSD: patch-tnm_generic_tnmInit.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Do not encode OS version in path for library.

--- tnm/generic/tnmInit.c.orig	1999-03-05 22:32:26.000000000 +0000
+++ tnm/generic/tnmInit.c
@@ -52,7 +52,8 @@ static void
 InitVars(interp)
     Tcl_Interp *interp;
 {
-    char *machine, *os, *vers, *user, *tmp, *p, *path, *cacheName;
+    const char *machine, *os;
+    char *vers, *user, *tmp, *p, *path, *cacheName;
     Tcl_DString arch, cache, dst;
     
     path = getenv("TNM_LIBRARY");
@@ -106,15 +107,12 @@ InitVars(interp)
 
     machine = Tcl_GetVar2(interp, "tcl_platform", "machine", TCL_GLOBAL_ONLY);
     os = Tcl_GetVar2(interp, "tcl_platform", "os", TCL_GLOBAL_ONLY);
-    vers = Tcl_GetVar2(interp, "tcl_platform", "osVersion", TCL_GLOBAL_ONLY);
 
     Tcl_DStringInit(&arch);
-    if (machine && os && vers) {
+    if (machine && os) {
 	Tcl_DStringAppend(&arch, machine, -1);
 	Tcl_DStringAppend(&arch, "-", 1);
 	Tcl_DStringAppend(&arch, os, -1);
-	Tcl_DStringAppend(&arch, "-", 1);
-	Tcl_DStringAppend(&arch, vers, -1);
     } else {
 	Tcl_DStringAppend(&arch, "unknown-os", -1);
     }
@@ -192,8 +190,8 @@ static int
 InitRc(interp)
     Tcl_Interp *interp;
 {
-    char *fileName, *library;
-    char **libArgv = NULL;
+    const char *fileName, *library;
+    const char **libArgv = NULL;
     int libArgc;
 
     library = Tcl_GetVar2(interp, "tnm", "library", TCL_GLOBAL_ONLY);
@@ -204,7 +202,8 @@ InitRc(interp)
     if (library) {
 
 	int tmpArgc;
-	char **tmpArgv = (char **) ckalloc((libArgc + 4) * sizeof(char *));
+	const char **tmpArgv = (const char **) ckalloc((libArgc + 4) *
+						       sizeof(char *));
 	Tcl_DString buffer;
 
 	Tcl_DStringInit(&buffer);
@@ -237,7 +236,7 @@ InitRc(interp)
 
 	if (fileName) {
 	    if (Tcl_EvalFile(interp, fileName) != TCL_OK) {
-		TnmWriteMessage(interp, interp->result);
+	        TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 		TnmWriteMessage(interp, "\n");
 	    }
 	}
@@ -272,7 +271,7 @@ InitRc(interp)
 	Tcl_DStringInit(&temp);
         fullName = Tcl_TranslateFileName(interp, fileName, &temp);
 	if (fullName == NULL) {
-	    TnmWriteMessage(interp, interp->result);
+	    TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	    TnmWriteMessage(interp, "\n");
 	} else {
 	    Tcl_Channel channel;
@@ -280,7 +279,7 @@ InitRc(interp)
 	    if (channel) {
 		Tcl_Close((Tcl_Interp *) NULL, channel);
 		if (Tcl_EvalFile(interp, fullName) != TCL_OK) {
-		    TnmWriteMessage(interp, interp->result);
+		    TnmWriteMessage(interp, Tcl_GetStringResult(interp));
                     TnmWriteMessage(interp, "\n");
 		}
 	    }
