$NetBSD: patch-except.c,v 1.2 2015/12/29 23:34:57 dholland Exp $

Use NORETURN.
Don't declare standard functions.

--- except.c.orig	2012-11-19 01:59:57.000000000 +0000
+++ except.c
@@ -107,7 +107,7 @@ void warning (const char *text, ...)
   putc ('\n', stderr);
 }
 
-void error (const char *text, ...)
+void NORETURN error (const char *text, ...) NRUTERON
 {
   void *eh, *tmp;
   va_list ap;
@@ -118,17 +118,13 @@ void error (const char *text, ...)
   ScmRaiseError (eh, tmp);
 }
 
-void fatal (const char *text)
+void NORETURN fatal (const char *text) NRUTERON
 {
-# ifndef EXIT_VOLATILE
-  extern NORETURN void exit (int) NRUTERON;
-# endif
-
   fprintf (stderr, "fatal: %s\n", text);
   exit (EXIT_FAILURE);
 }
 
-void restriction (const char *text, ...)
+void NORETURN restriction (const char *text, ...) NRUTERON
 {
   void *eh, *tmp;
   va_list ap;
@@ -140,13 +136,13 @@ void restriction (const char *text, ...)
   ScmRaiseError (eh, tmp);
 }
 
-void reset (const char *text)
+void NORETURN reset (const char *text) NRUTERON
 {
   fprintf (stderr, "System reset: %s\n", text);
   ScmRaiseReset ();
 }
 
-void badarg (const char *fname, void *arg)
+void NORETURN badarg (const char *fname, void *arg) NRUTERON
 {
   error ("bad argument to primitive procedure %s: %w", fname, arg);
 }
