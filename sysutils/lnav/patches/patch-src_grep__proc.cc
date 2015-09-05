$NetBSD: patch-src_grep__proc.cc,v 1.1 2015/09/05 22:12:04 wiz Exp $

stdout is not an lvalue, and if it was, this looks idempotent.

--- src/grep_proc.cc.orig	2015-04-09 03:40:09.000000000 +0000
+++ src/grep_proc.cc
@@ -159,7 +159,6 @@ void grep_proc::child_loop(void)
     char   outbuf[BUFSIZ * 2];
     string line_value;
 
-    stdout = fdopen(STDOUT_FILENO, "w");
     /* Make sure buffering is on, not sure of the state in the parent. */
     if (setvbuf(stdout, outbuf, _IOFBF, BUFSIZ * 2) < 0) {
         perror("setvbuf");
