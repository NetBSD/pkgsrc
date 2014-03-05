$NetBSD: patch-tnm_generic_tnmIned.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnmIned.c.orig	1998-09-07 17:14:12.000000000 +0000
+++ tnm/generic/tnmIned.c
@@ -20,7 +20,7 @@
  */
 
 typedef struct Message {
-    char *msg;
+    const char *msg;
     struct Message *next;
 } Message;
 
@@ -55,14 +55,14 @@ static void
 InedFlushQueue		_ANSI_ARGS_((Tcl_Interp *));
 
 static void 
-InedAppendQueue		_ANSI_ARGS_((Tcl_Interp *interp, char *msg));
+InedAppendQueue		_ANSI_ARGS_((Tcl_Interp *interp, const char *msg));
 
 static char*
 InedGets		_ANSI_ARGS_((Tcl_Interp *interp));
 
 static int 
-InedCompCmd		_ANSI_ARGS_((char *cmd, Tcl_Interp *interp, 
-				     int argc, char **argv));
+InedCompCmd		_ANSI_ARGS_((const char *cmd, Tcl_Interp *interp, 
+				     int argc, const char **argv));
 static void
 InedReceiveProc		_ANSI_ARGS_((ClientData clientData, int mask));
 
@@ -136,7 +136,8 @@ static void
 InedInitialize(interp)
     Tcl_Interp *interp;
 {
-    char *path, *tmp, *p;
+    const char *path, *p;
+    char *tmp;
     Tcl_Channel channel;
 
     /*
@@ -174,10 +175,12 @@ InedInitialize(interp)
     Tcl_SetVar(interp, "auto_path", "", TCL_GLOBAL_ONLY);
     
     if ((p = getenv("TKINED_PATH"))) {
+        char *tp;
+
 	tmp = ckstrdup(p);
-	for (p = tmp; *p; p++) {
-	    if (*p == ':') {
-		*p = ' ';
+	for (tp = tmp; *tp; tp++) {
+	    if (*tp == ':') {
+		*tp = ' ';
 	    }
 	}
 	Tcl_SetVar(interp, "auto_path", tmp, TCL_GLOBAL_ONLY);
@@ -371,7 +374,7 @@ InedFlushQueue(interp)
 static void
 InedAppendQueue(interp, msg)
     Tcl_Interp *interp;
-    char *msg;
+    const char *msg;
 {
     Message *np;
     Message *p;
@@ -457,10 +460,10 @@ InedGets(interp)
 
 static int
 InedCompCmd(cmd, interp, argc, argv)
-    char *cmd;
+    const char *cmd;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int type = TnmGetTableKey(tkiTypeTable, argv[0]);
     if (type < 0 || (type == TKINED_NONE) || (type == TKINED_ALL)) {
@@ -468,11 +471,11 @@ InedCompCmd(cmd, interp, argc, argv)
     }
 
     if ((strcmp(cmd, "type") == 0) && (argc > 0)) {
-	Tcl_SetResult(interp, argv[0], TCL_VOLATILE);
+        Tcl_SetResult(interp, (char *)argv[0], TCL_VOLATILE);
 	return TCL_OK;
 
     } else if ((strcmp(cmd, "id") == 0) && (argc > 1)) {
-	Tcl_SetResult(interp, argv[1], TCL_VOLATILE);
+        Tcl_SetResult(interp, (char *)argv[1], TCL_VOLATILE);
 	return TCL_OK;
 
     } else if ((strcmp(cmd, "name") == 0) && (argc > 2)) {
@@ -482,7 +485,7 @@ InedCompCmd(cmd, interp, argc, argv)
 	    || (type == TKINED_MENU) || (type == TKINED_LOG) 
 	    || (type == TKINED_GRAPH) || (type == TKINED_HTML)
 	    || (type == TKINED_DATA) || (type == TKINED_EVENT) )
-	    Tcl_SetResult(interp, argv[2], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[2], TCL_VOLATILE);
         return TCL_OK;
 
     } else if ((strcmp(cmd, "address") == 0) && (argc > 3)) {
@@ -490,41 +493,41 @@ InedCompCmd(cmd, interp, argc, argv)
 	    || (type == TKINED_BARCHART) || (type == TKINED_STRIPCHART)
 	    || (type == TKINED_REFERENCE) || (type == TKINED_GRAPH)
 	    || (type == TKINED_DATA))
-	    Tcl_SetResult(interp, argv[3], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[3], TCL_VOLATILE);
         return TCL_OK;
 
     } else if (strcmp(cmd, "oid") == 0) {
         if ((type == TKINED_GROUP) && (argc > 3)) {
-	    Tcl_SetResult(interp, argv[3], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[3], TCL_VOLATILE);
 	}
         if ((type == TKINED_NODE || type == TKINED_NETWORK) && (argc > 4)) {
-	    Tcl_SetResult(interp, argv[4], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[4], TCL_VOLATILE);
 	}
 	return TCL_OK;
 
     } else if ((strcmp(cmd, "links") == 0) && (argc > 5)) {
         if ((type == TKINED_NODE) || (type == TKINED_NETWORK))
-	    Tcl_SetResult(interp, argv[5], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[5], TCL_VOLATILE);
         return TCL_OK;
 
     } else if ((strcmp(cmd, "member") == 0) && (argc > 4)) {
         if (type == TKINED_GROUP)
-	    Tcl_SetResult(interp, argv[4], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[4], TCL_VOLATILE);
         return TCL_OK;
 
     } else if ((strcmp(cmd, "src") == 0) && (argc > 2)) {
         if (type == TKINED_LINK)
-	    Tcl_SetResult(interp, argv[2], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[2], TCL_VOLATILE);
         return TCL_OK;
 
     } else if ((strcmp(cmd, "dst") == 0) && (argc > 3)) {
         if (type == TKINED_LINK)
-	    Tcl_SetResult(interp, argv[3], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[3], TCL_VOLATILE);
         return TCL_OK;
 
     } else if ((strcmp(cmd, "text") == 0) && (argc > 2)) {
         if (type == TKINED_LINK)
-	    Tcl_SetResult(interp, argv[2], TCL_VOLATILE);
+	  Tcl_SetResult(interp, (char *)argv[2], TCL_VOLATILE);
         return TCL_OK;
 
     }
@@ -559,11 +562,11 @@ Tnm_InedCmd(clientData, interp, argc, ar
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_Channel channel;
     int i;
-    char *p;
+    const char *p;
     static int initialized = 0;
 
     if (! initialized) {
@@ -600,7 +603,7 @@ Tnm_InedCmd(clientData, interp, argc, ar
 
     if (argc == 3) {
         int largc;
-	char **largv;
+	const char **largv;
         int rc = Tcl_SplitList(interp, argv[2], &largc, &largv);
 	if (rc == TCL_OK && largc > 0) {
 	    if (InedCompCmd(argv[1], interp, largc, largv) == TCL_OK) {
@@ -651,15 +654,15 @@ Tnm_InedCmd(clientData, interp, argc, ar
     while ((p = InedGets(interp)) != (char *) NULL) {
         if (*p == '\0') continue;
 	if (strncmp(p, "ined ok", 7) == 0) {
-	    char *r = p+7;
+	    const char *r = p+7;
 	    while (*r && isspace(*r)) r++;
-	    Tcl_SetResult(interp, r, TCL_VOLATILE);
+	    Tcl_SetResult(interp, (char*)r, TCL_VOLATILE);
 	    ckfree(p);
 	    return TCL_OK;
 	} else if (strncmp(p, "ined error", 10) == 0) {
-	    char *r = p+10;
+	    const char *r = p+10;
 	    while (*r && isspace(*r)) r++;
-	    Tcl_SetResult(interp, r, TCL_VOLATILE);
+	    Tcl_SetResult(interp, (char*)r, TCL_VOLATILE);
 	    ckfree(p);
 	    return TCL_ERROR;
 	} else {
