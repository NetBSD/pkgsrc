$NetBSD: patch-main_streams_cast.c,v 1.1.14.1 2013/07/15 22:32:24 tron Exp $

* For NetBSD 6.0+, __NetBSD_Version__ should includes 600000000.

--- main/streams/cast.c.orig	2013-07-10 17:43:08.000000000 +0000
+++ main/streams/cast.c
@@ -33,7 +33,7 @@
 #if defined(HAVE_FUNOPEN) && !defined(HAVE_FOPENCOOKIE)
 
 /* NetBSD 6.0+ uses off_t instead of fpos_t in funopen */
-# if defined(__NetBSD__) && (__NetBSD_Version__ > 600000000)
+# if defined(__NetBSD__) && (__NetBSD_Version__ >= 600000000)
 #  define PHP_FPOS_T off_t
 # else
 #  define PHP_FPOS_T fpos_t
