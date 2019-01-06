$NetBSD: patch-lib_fseeko.c,v 1.2 2019/01/06 05:45:30 gutteridge Exp $

Treat Minix 3 same as NetBSD

Work around glibc changes that broke dependent gnulib functionality.
Patch from: http://git.savannah.gnu.org/gitweb/?p=gnulib.git;a=commitdiff;h=74d9d6a293d7462dea8f83e7fc5ac792e956a0ad

--- lib/fseeko.c.orig	2016-12-31 13:54:41.000000000 +0000
+++ lib/fseeko.c
@@ -47,7 +47,8 @@ fseeko (FILE *fp, off_t offset, int when
 #endif
 
   /* These tests are based on fpurge.c.  */
-#if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1 /* GNU libc, BeOS, Haiku, Linux libc5 */
+#if defined _IO_EOF_SEEN || defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
+  /* GNU libc, BeOS, Haiku, Linux libc5 */
   if (fp->_IO_read_end == fp->_IO_read_ptr
       && fp->_IO_write_ptr == fp->_IO_write_base
       && fp->_IO_save_base == NULL)
@@ -123,12 +124,13 @@ fseeko (FILE *fp, off_t offset, int when
           return -1;
         }
 
-#if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1 /* GNU libc, BeOS, Haiku, Linux libc5 */
+#if defined _IO_EOF_SEEN || defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
+  /* GNU libc, BeOS, Haiku, Linux libc5 */
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ || defined __ANDROID__
       /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Android */
-# if defined __CYGWIN__ || (defined __NetBSD__ && __NetBSD_Version__ >= 600000000)
+# if defined __CYGWIN__ || (defined __NetBSD__ && __NetBSD_Version__ >= 600000000) || defined __Minix__
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
