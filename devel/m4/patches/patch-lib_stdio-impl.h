$NetBSD: patch-lib_stdio-impl.h,v 1.1 2018/10/28 20:53:44 sevan Exp $

Treat Minix 3 same as NetBSD

--- lib/stdio-impl.h.orig	2018-10-28 20:27:54.933015000 +0000
+++ lib/stdio-impl.h
@@ -58,7 +58,7 @@
 #  define fp_ fp
 # endif
 
-# if (defined __NetBSD__ && __NetBSD_Version__ >= 105270000) || defined __OpenBSD__ || defined __ANDROID__ /* NetBSD >= 1.5ZA, OpenBSD, Android */
+# if (defined __NetBSD__ && __NetBSD_Version__ >= 105270000) || defined __OpenBSD__ || defined __ANDROID__ || defined __Minix__ /* NetBSD >= 1.5ZA, OpenBSD, Android, Minix3 */
   /* See <http://cvsweb.netbsd.org/bsdweb.cgi/src/lib/libc/stdio/fileext.h?rev=HEAD&content-type=text/x-cvsweb-markup>
      and <http://www.openbsd.org/cgi-bin/cvsweb/src/lib/libc/stdio/fileext.h?rev=HEAD&content-type=text/x-cvsweb-markup> */
   struct __sfileext
