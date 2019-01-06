$NetBSD: patch-lib_fpurge.c,v 1.1 2019/01/06 05:45:30 gutteridge Exp $

Work around glibc changes that broke dependent gnulib functionality.
Patch from: http://git.savannah.gnu.org/gitweb/?p=gnulib.git;a=commitdiff;h=74d9d6a293d7462dea8f83e7fc5ac792e956a0ad

--- lib/fpurge.c.orig	2016-12-31 13:54:41.000000000 +0000
+++ lib/fpurge.c
@@ -62,7 +62,8 @@ fpurge (FILE *fp)
   /* Most systems provide FILE as a struct and the necessary bitmask in
      <stdio.h>, because they need it for implementing getc() and putc() as
      fast macros.  */
-# if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1 /* GNU libc, BeOS, Haiku, Linux libc5 */
+#if defined _IO_EOF_SEEN || defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
+  /* GNU libc, BeOS, Haiku, Linux libc5 */
   fp->_IO_read_end = fp->_IO_read_ptr;
   fp->_IO_write_ptr = fp->_IO_write_base;
   /* Avoid memory leak when there is an active ungetc buffer.  */
