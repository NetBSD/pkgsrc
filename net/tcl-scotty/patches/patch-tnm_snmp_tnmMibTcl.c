$NetBSD: patch-tnm_snmp_tnmMibTcl.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Avoid use of interp->errorLine.

--- tnm/snmp/tnmMibTcl.c.orig	1999-03-08 08:39:23.000000000 +0000
+++ tnm/snmp/tnmMibTcl.c
@@ -18,16 +18,16 @@
 
 static int	
 MibCmd		_ANSI_ARGS_((ClientData	clientData, Tcl_Interp *interp,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 static int
-LoadFileList	_ANSI_ARGS_((Tcl_Interp *interp, char *fileList));
+LoadFileList	_ANSI_ARGS_((Tcl_Interp *interp, const char *fileList));
 
 static int
-LoadFile	_ANSI_ARGS_((Tcl_Interp *interp, char *file));
+LoadFile	_ANSI_ARGS_((Tcl_Interp *interp, const char *file));
 
 static int
-WalkTree	_ANSI_ARGS_((Tcl_Interp *interp, char *name, 
-			     char *label, char *body, int exact,
+WalkTree	_ANSI_ARGS_((Tcl_Interp *interp, const char *name, 
+			     const char *label, const char *body, int exact,
 			     Tnm_MibNode* nodePtr, Tnm_Oid *oid, int len));
 
 /*
@@ -77,11 +77,11 @@ MibCmd(clientData, interp, argc, argv)
     ClientData clientData;
     Tcl_Interp *interp;
     int	argc;
-    char **argv;
+    const char **argv;
 {
     int exact = 0;
-    char *cmd, *name, *arg;
-    char *result = NULL;
+    const char *cmd, *name, *arg;
+    const char *result = NULL;
     static int initialized = 0;
 
     if (argc > 1 && strcmp(argv[1], "-exact") == 0) {
@@ -107,7 +107,7 @@ MibCmd(clientData, interp, argc, argv)
      */
 
     if (! initialized) {
-	char *mibFileList;
+        const char *mibFileList;
 
 	initialized = 1;
 	mibFileList = Tcl_GetVar2(interp, "tnm", "mibs:core", TCL_GLOBAL_ONLY);
@@ -166,7 +166,7 @@ MibCmd(clientData, interp, argc, argv)
 	    return TCL_ERROR;
 	}
 	if (! result) goto notFound;
-        Tcl_SetResult(interp, result, TCL_VOLATILE);
+        Tcl_SetResult(interp, (char*)result, TCL_VOLATILE);
         return TCL_OK;
     }
 
@@ -179,7 +179,7 @@ MibCmd(clientData, interp, argc, argv)
 	    return TCL_ERROR;
 	}
 	if (! result) goto notFound;
-        Tcl_SetResult(interp, result, TCL_VOLATILE);
+        Tcl_SetResult(interp, (char*)result, TCL_VOLATILE);
         return TCL_OK;
     }
 
@@ -240,7 +240,7 @@ MibCmd(clientData, interp, argc, argv)
     
     if (! result) goto notFound;
     
-    Tcl_SetResult(interp, result, TCL_VOLATILE);
+    Tcl_SetResult(interp, (char*)result, TCL_VOLATILE);
     return TCL_OK;
     
 notFound:
@@ -268,10 +268,10 @@ notFound:
 static int
 LoadFileList(interp, fileList)
     Tcl_Interp *interp;
-    char *fileList;
+    const char *fileList;
 {
     int i, code, argc;
-    char **argv;
+    const char **argv;
 
     if (fileList == NULL) {
 	return TCL_OK;
@@ -315,11 +315,11 @@ LoadFileList(interp, fileList)
 static int
 LoadFile(interp, file)
     Tcl_Interp *interp;
-    char *file;
+    const char *file;
 {
     Tcl_DString fileBuffer, frozenFileBuffer;
-    char *library, *cache, *arch, *fileName, *frozenFileName = NULL;
-    char **fileArgv = NULL;
+    const char *library, *cache, *arch, *fileName, *frozenFileName = NULL;
+    const char **fileArgv = NULL;
     int fileArgc;
     int code = TCL_OK;
 
@@ -465,9 +465,9 @@ LoadFile(interp, file)
 static int
 WalkTree(interp, varName, label, body, exact, nodePtr, oid, len)
     Tcl_Interp *interp;
-    char *varName;
-    char *label;
-    char *body;
+    const char *varName;
+    const char *label;
+    const char *body;
     int exact;
     Tnm_MibNode* nodePtr;
     Tnm_Oid *oid;
@@ -487,8 +487,7 @@ WalkTree(interp, varName, label, body, e
     }
 
     while (nodePtr) {
-
-	char *val, *label;
+        const char *val, *label;
 
 	if (doall && oid) {
 	    oid[len-1] = nodePtr->subid;
@@ -522,7 +521,7 @@ WalkTree(interp, varName, label, body, e
 	    } else if (result == TCL_ERROR) {
 		char msg[100];
 		sprintf(msg, "\n    (\"mib walk\" body line %d)",
-			interp->errorLine);
+			Tcl_GetErrorLine(interp));
 		Tcl_AddErrorInfo(interp, msg);
 		goto loopDone;
 	    } else {
