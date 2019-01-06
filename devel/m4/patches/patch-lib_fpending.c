$NetBSD: patch-lib_fpending.c,v 1.1 2019/01/06 05:45:30 gutteridge Exp $

Work around glibc changes that broke dependent gnulib functionality.
Patch from: http://git.savannah.gnu.org/gitweb/?p=gnulib.git;a=commitdiff;h=74d9d6a293d7462dea8f83e7fc5ac792e956a0ad

--- lib/fpending.c.orig	2016-12-31 13:54:41.000000000 +0000
+++ lib/fpending.c
@@ -32,7 +32,8 @@ __fpending (FILE *fp)
   /* Most systems provide FILE as a struct and the necessary bitmask in
      <stdio.h>, because they need it for implementing getc() and putc() as
      fast macros.  */
-#if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1 /* GNU libc, BeOS, Haiku, Linux libc5 */
+#if defined _IO_EOF_SEEN || defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
+  /* GNU libc, BeOS, Haiku, Linux libc5 */
   return fp->_IO_write_ptr - fp->_IO_write_base;
 #elif defined __sferror || defined __DragonFly__ || defined __ANDROID__
   /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Android */
