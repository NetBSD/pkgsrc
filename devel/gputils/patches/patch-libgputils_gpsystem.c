$NetBSD: patch-libgputils_gpsystem.c,v 1.2 2018/06/25 14:01:45 bouyer Exp $

Avoid possible integer wraparound reporting calloc failure, pursuant
to a build failure in sdcc3 that seems to involve gplib trying to
allocate gigs of memory.

--- ./libgputils/gpsystem.c.orig	2016-08-12 13:51:57.000000000 +0200
+++ ./libgputils/gpsystem.c	2018-06-25 14:25:17.713681934 +0200
@@ -417,8 +417,8 @@
   }
 
   if ((m = calloc(Nmemb, Size)) == NULL) {
-    fprintf(stderr, "%s() -- Could not allocate %"SIZE_FMTu" bytes of memory. {%s.LINE-%"SIZE_FMTu", %s()}\n",
-            __func__, Nmemb * Size, File, Line, Func);
+    fprintf(stderr, "%s() -- Could not allocate %"SIZE_FMTu" objects of %"SIZE_FMTu" bytes each. {%s.LINE-%"SIZE_FMTu", %s()}\n",
+            __func__, Nmemb, Size, File, Line, Func);
     exit(1);
   }
 
