$NetBSD: patch-main_streams_cast.c,v 1.1.10.1 2013/08/06 14:55:05 tron Exp $

* For NetBSD 6.0+, __NetBSD_Version__ should includes 600000000.

--- main/streams/cast.c.orig	2013-07-03 06:10:53.000000000 +0000
+++ main/streams/cast.c
@@ -33,7 +33,7 @@
 #if defined(HAVE_FUNOPEN) && !defined(HAVE_FOPENCOOKIE)
 
 /* NetBSD 6.0+ uses off_t instead of fpos_t in funopen */
-# if defined(__NetBSD__) && (__NetBSD_Version__ > 600000000)
+# if defined(__NetBSD__) && (__NetBSD_Version__ >= 600000000)
 #  define PHP_FPOS_T off_t
 # else
 #  define PHP_FPOS_T fpos_t
