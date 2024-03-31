$NetBSD: patch-input.c,v 1.1 2024/03/31 17:14:32 js Exp $

--- input.c.orig	2024-03-31 17:12:33.794573471 +0000
+++ input.c
@@ -805,8 +805,10 @@ rl_getc (FILE *stream)
   int result;
   unsigned char c;
   int fd;
-#if defined (HAVE_PSELECT)
+#if defined (HAVE_PSELECT) || defined (HAVE_SELECT)
+#if defined (HANDLE_SIGNALS)
   sigset_t empty_set;
+#endif
   fd_set readfds;
 #endif
 
