$NetBSD: patch-lib_stdio-impl.h,v 1.2 2019/01/06 05:45:30 gutteridge Exp $

Treat Minix 3 same as NetBSD

Work around glibc changes that broke dependent gnulib functionality.
Patch from: http://git.savannah.gnu.org/gitweb/?p=gnulib.git;a=commitdiff;h=4af4a4a71827c0bc5e0ec67af23edef4f15cee8e

--- lib/stdio-impl.h.orig	2016-12-31 13:54:42.000000000 +0000
+++ lib/stdio-impl.h
@@ -18,6 +18,12 @@
    the same implementation of stdio extension API, except that some fields
    have different naming conventions, or their access requires some casts.  */
 
+/* Glibc 2.28 made _IO_IN_BACKUP private.  For now, work around this
+   problem by defining it ourselves.  FIXME: Do not rely on glibc
+   internals.  */
+#if !defined _IO_IN_BACKUP && defined _IO_EOF_SEEN
+# define _IO_IN_BACKUP 0x100
+#endif
 
 /* BSD stdio derived implementations.  */
 
@@ -58,7 +64,7 @@
 #  define fp_ fp
 # endif
 
-# if (defined __NetBSD__ && __NetBSD_Version__ >= 105270000) || defined __OpenBSD__ || defined __ANDROID__ /* NetBSD >= 1.5ZA, OpenBSD, Android */
+# if (defined __NetBSD__ && __NetBSD_Version__ >= 105270000) || defined __OpenBSD__ || defined __ANDROID__ || defined __Minix__ /* NetBSD >= 1.5ZA, OpenBSD, Android, Minix3 */
   /* See <http://cvsweb.netbsd.org/bsdweb.cgi/src/lib/libc/stdio/fileext.h?rev=HEAD&content-type=text/x-cvsweb-markup>
      and <http://www.openbsd.org/cgi-bin/cvsweb/src/lib/libc/stdio/fileext.h?rev=HEAD&content-type=text/x-cvsweb-markup> */
   struct __sfileext
