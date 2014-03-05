$NetBSD: patch-tnm_gdmo_tnmGdmoTcl.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/gdmo/tnmGdmoTcl.c.orig	1996-10-01 20:18:38.000000000 +0000
+++ tnm/gdmo/tnmGdmoTcl.c
@@ -88,20 +88,20 @@ oid_result		_ANSI_ARGS_((Tcl_Interp*, gd
 
 static int
 GdmoNotification	_ANSI_ARGS_((Tcl_Interp *interp,
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 GdmoBehaviour		_ANSI_ARGS_((Tcl_Interp *interp,
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 GdmoLoad		_ANSI_ARGS_((Tcl_Interp *interp,
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 GdmoInfo		_ANSI_ARGS_((Tcl_Interp *interp,
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int 
 GdmoCmd			_ANSI_ARGS_((ClientData clientData,
 				     Tcl_Interp *interp,
-				     int argc, char **argv));
+				     int argc, const char **argv));
 
 
 /*===========================================================================*
@@ -1282,7 +1282,7 @@ static int 
 GdmoNotification (interp, argc, argv)
      Tcl_Interp	*interp;
      int argc;
-     char **argv;
+     const char **argv;
 {
     if (argc == 2) {
 	if (!strcmp(argv[1], "info")) {
@@ -1360,7 +1360,7 @@ static int 
 GdmoBehaviour (interp, argc, argv)
      Tcl_Interp	*interp;
      int argc;
-     char **argv;
+     const char **argv;
 {
     if (argc == 2) {
 	if (!strcmp(argv[1], "info")) {
@@ -1424,11 +1424,11 @@ static int 
 GdmoLoad (interp, argc, argv)
      Tcl_Interp	*interp;
      int argc;
-     char **argv;
+     const char **argv;
 {
     Tcl_DString fileBuffer;
-    char *library, *fileName, *file = argv[2];
-    char **fileArgv = NULL, **libArgv = NULL;
+    const char *library, *fileName, *file = argv[2];
+    const char **fileArgv = NULL, **libArgv = NULL;
     int fileArgc, libArgc;
     int code = TCL_OK;
     FILE *fin = NULL;
@@ -1463,8 +1463,8 @@ GdmoLoad (interp, argc, argv)
     if (access(fileName, R_OK) != 0) {
 
 	int tmpArgc;
-	char **tmpArgv = (char **) ckalloc((libArgc + 2) * sizeof(char *));
-
+	const char **tmpArgv = (const char **) ckalloc((libArgc + 2) *
+						       sizeof(char *));
 	if (library) {
 	    for (tmpArgc = 0; tmpArgc < libArgc; tmpArgc++) {
 		tmpArgv[tmpArgc] = libArgv[tmpArgc];
@@ -1551,7 +1551,7 @@ static int
 GdmoInfo(interp, argc, argv)
     Tcl_Interp	*interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     if (argc != 3) {
         Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
@@ -1610,7 +1610,7 @@ GdmoCmd(clientData, interp, argc, argv)
      ClientData	clientData;
      Tcl_Interp	*interp;
      int argc;
-     char **argv;
+     const char **argv;
 {
     if (argc < 2) {
         Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
