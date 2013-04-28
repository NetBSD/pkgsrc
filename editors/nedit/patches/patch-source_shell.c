$NetBSD: patch-source_shell.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Avoid nasal demons if fork fails.

--- source/shell.c~	2004-09-02 08:49:56.000000000 +0000
+++ source/shell.c
@@ -505,6 +505,14 @@ static void issueCommand(WindowInfo *win
     /* fork the subprocess and issue the command */
     childPid = forkCommand(window->shell, command, window->path, &stdinFD,
 	    &stdoutFD, (flags & ERROR_DIALOGS) ? &stderrFD : NULL);
+
+    if (childPid == -1) {
+	/*
+	 * XXX: there does not appear to be any way to handle this error;
+	 * but at least let's avoid nasal demons.
+	 */
+	stdinFD = stdoutFD = stderrFD = -1;
+    }
     
     /* set the pipes connected to the process for non-blocking i/o */
     if (fcntl(stdinFD, F_SETFL, O_NONBLOCK) < 0)
