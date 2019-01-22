$NetBSD: patch-tclreadline.c,v 1.2 2019/01/22 14:08:48 he Exp $

Some const'ness.
Comment out two FREE() calls which now cause crashes...

--- tclreadline.c.orig	2015-06-08 12:42:30.000000000 +0000
+++ tclreadline.c
@@ -73,16 +73,16 @@ static char* stripright(char* in);
 static char* stripwhite(char* in);
 static int TclReadlineLineComplete(void);
 static void TclReadlineTerminate(int state);
-static char* TclReadlineQuote(char* text, char* quotechars);
+static char* TclReadlineQuote(const char* text, char* quotechars);
 static int TclReadlineCmd(ClientData clientData, Tcl_Interp *interp, int objc,
                    Tcl_Obj *CONST objv[]);
 static void TclReadlineReadHandler(ClientData clientData, int mask);
 static void TclReadlineLineCompleteHandler(char* ptr);
 static int TclReadlineInitialize(Tcl_Interp* interp, char* historyfile);
 static int blank_line(char* str);
-static char** TclReadlineCompletion(char* text, int start, int end);
-static char* TclReadline0generator(char* text, int state);
-static char* TclReadlineKnownCommands(char* text, int state, int mode);
+static char** TclReadlineCompletion(const char* text, int start, int end);
+static char* TclReadline0generator(const char* text, int state);
+static char* TclReadlineKnownCommands(const char* text, int state, int mode);
 static int TclReadlineParse(char** args, int maxargs, char* buf);
 
 
@@ -176,9 +176,9 @@ TclReadlineTerminate(int state)
 }
 
 static char*
-TclReadlineQuote(char* text, char* quotechars)
+TclReadlineQuote(const char* text, char* quotechars)
 {
-    char* ptr;
+    const char* ptr;
     char* result_c;
     int i, len = strlen(quotechars);
     Tcl_DString result;
@@ -544,8 +544,10 @@ TclReadlineLineCompleteHandler(char* ptr
 	 * tell the calling routines to terminate.
 	 */
 	TclReadlineTerminate(LINE_COMPLETE);
-	FREE(ptr);
-	FREE(expansion);
+
+	/* These now cause crashes: */
+	/* FREE(ptr); */
+	/* FREE(expansion); */
     }
 }
 
@@ -635,7 +637,7 @@ TclReadlineInitialize(Tcl_Interp* interp
      * directory. If this failes, this
      * is *not* an error.
      */
-    rl_attempted_completion_function = (CPPFunction *) TclReadlineCompletion;
+    rl_attempted_completion_function = TclReadlineCompletion;
     if (read_history(historyfile)) {
 	if (write_history(historyfile)) {
 	    Tcl_AppendResult (interp, "warning: `",
@@ -657,7 +659,7 @@ blank_line(char* str)
 }
 
 static char**
-TclReadlineCompletion(char* text, int start, int end)
+TclReadlineCompletion(const char* text, int start, int end)
 {
     char** matches = (char**) NULL;
     int status;
@@ -752,13 +754,13 @@ TclReadlineCompletion(char* text, int st
 }
 
 static char*
-TclReadline0generator(char* text, int state)
+TclReadline0generator(const char* text, int state)
 {
     return TclReadlineKnownCommands(text, state, _CMD_GET);
 }
 
 static char*
-TclReadlineKnownCommands(char* text, int state, int mode)
+TclReadlineKnownCommands(const char* text, int state, int mode)
 {
     static int len;
     static cmds_t *cmds = (cmds_t *) NULL, *new;
@@ -881,6 +883,6 @@ TclReadlineParse(char** args, int maxarg
 	    buf++;
     }
 
-    *args = '\0';
+    *args = NULL;
     return nr;
 }
