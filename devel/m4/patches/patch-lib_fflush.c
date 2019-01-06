$NetBSD: patch-lib_fflush.c,v 1.1 2019/01/06 05:45:30 gutteridge Exp $

Work around glibc changes that broke dependent gnulib functionality.
Patch from: http://git.savannah.gnu.org/gitweb/?p=gnulib.git;a=commitdiff;h=74d9d6a293d7462dea8f83e7fc5ac792e956a0ad

--- lib/fflush.c.orig	2016-12-31 13:54:41.000000000 +0000
+++ lib/fflush.c
@@ -33,7 +33,8 @@
 #undef fflush
 
 
-#if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1 /* GNU libc, BeOS, Haiku, Linux libc5 */
+#if defined _IO_EOF_SEEN || defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
+  /* GNU libc, BeOS, Haiku, Linux libc5 */
 
 /* Clear the stream's ungetc buffer, preserving the value of ftello (fp).  */
 static void
@@ -72,7 +72,8 @@ clear_ungetc_buffer (FILE *fp)
 
 #endif
 
-#if ! (defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1 /* GNU libc, BeOS, Haiku, Linux libc5 */)
+#if ! (defined _IO_EOF_SEEN || defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1)
+/* GNU libc, BeOS, Haiku, Linux libc5 */
 
 # if (defined __sferror || defined __DragonFly__ || defined __ANDROID__) && defined __SNPT
 /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Android */
@@ -148,7 +148,8 @@ rpl_fflush (FILE *stream)
   if (stream == NULL || ! freading (stream))
     return fflush (stream);
 
-#if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1 /* GNU libc, BeOS, Haiku, Linux libc5 */
+#if defined _IO_EOF_SEEN || defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
+  /* GNU libc, BeOS, Haiku, Linux libc5 */
 
   clear_ungetc_buffer_preserving_position (stream);
 
