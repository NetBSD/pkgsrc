$NetBSD: patch-unix_scotty.c,v 1.1 2014/03/05 13:52:29 he Exp $

Avoid use of interp->result.
Constify.

--- unix/scotty.c~	1996-09-19 19:17:19.000000000 +0200
+++ unix/scotty.c	2014-03-04 23:24:02.000000000 +0100
@@ -94,7 +94,8 @@
     }
 
     if (Tcl_PkgRequire(interp, "Tnm", TNM_VERSION, 1) == NULL) {
-	if (Tcl_StringMatch(interp->result, "*can't find package*")) {
+        if (Tcl_StringMatch(Tcl_GetStringResult(interp),
+			    "*can't find package*")) {
 	    Tcl_AppendResult(interp, "\n",
    "This usually means that you have to define the TCLLIBPATH environment\n",
    "variable to point to the tnm library directory or you have to include\n",
@@ -127,9 +128,10 @@
 int
 main(argc, argv)
     int argc;
-    char **argv;
+    const char **argv;
 {
-    char buffer[512], *args, *fileName = NULL;
+    char buffer[512], *args;
+    const char *fileName = NULL;
     Tcl_Channel inChannel, errChannel;
     Tcl_DString temp;
     int code, exitCode = 0;
@@ -180,7 +182,7 @@
 	errChannel = Tcl_GetChannel(interp, "stderr", NULL);
 	if (errChannel) {
 	    Tcl_Write(errChannel, "initialization failed: ", -1);
-	    Tcl_Write(errChannel, interp->result, -1);
+	    Tcl_Write(errChannel, Tcl_GetStringResult(interp), -1);
 	    Tcl_Write(errChannel, "\n", 1);
 	}
 	exitCode = 1;
@@ -217,7 +219,7 @@
         if (fullName == NULL) {
             errChannel = Tcl_GetStdChannel(TCL_STDERR);
             if (errChannel) {
-                Tcl_Write(errChannel, interp->result, -1);
+	        Tcl_Write(errChannel, Tcl_GetStringResult(interp), -1);
                 Tcl_Write(errChannel, "\n", 1);
             }
         } else {
@@ -232,7 +234,8 @@
                 if (Tcl_EvalFile(interp, fullName) != TCL_OK) {
                     errChannel = Tcl_GetStdChannel(TCL_STDERR);
                     if (errChannel) {
-                        Tcl_Write(errChannel, interp->result, -1);
+                        Tcl_Write(errChannel,
+				  Tcl_GetStringResult(interp), -1);
                         Tcl_Write(errChannel, "\n", 1);
                     }
                 }
@@ -365,7 +368,7 @@
     Tcl_CreateChannelHandler(chan, TCL_READABLE, StdinProc,
 	    (ClientData) chan);
     Tcl_DStringFree(&command);
-    if (*interp->result != 0) {
+    if (*Tcl_GetStringResult(interp) != 0) {
 	if ((code != TCL_OK) || (tty)) {
 	    /*
 	     * The statement below used to call "printf", but that resulted
@@ -374,7 +377,7 @@
              * NOTE: This probably will not work under Windows either.
 	     */
 
-	    puts(interp->result);
+	    puts(Tcl_GetStringResult(interp));
 	}
     }
 
@@ -414,7 +417,7 @@
 					 * exists a partial command, so use
 					 * the secondary prompt. */
 {
-    char *promptCmd;
+    const char *promptCmd;
     int code;
     Tcl_Channel outChannel, errChannel;
 
@@ -449,7 +452,7 @@
              */
 	    
             if (errChannel != (Tcl_Channel) NULL) {
-	        Tcl_Write(errChannel, interp->result, -1);
+	        Tcl_Write(errChannel, Tcl_GetStringResult(interp), -1);
 	        Tcl_Write(errChannel, "\n", 1);
 	    }
 	    goto defaultPrompt;
