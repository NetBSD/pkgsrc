$NetBSD: patch-libgputils_gpsystem.c,v 1.1 2016/09/14 14:10:50 dholland Exp $

Avoid possible integer wraparound reporting calloc failure, pursuant
to a build failure in sdcc3 that seems to involve gplib trying to
allocate gigs of memory.

--- libgputils/gpsystem.c~	2015-12-06 12:44:33.000000000 +0000
+++ libgputils/gpsystem.c
@@ -245,8 +245,8 @@ gp_calloc(size_t Nmemb, size_t Size, con
   }
 
   if ((m = calloc(Nmemb, Size)) == NULL) {
-    fprintf(stderr, "%s() -- Could not allocate %zu bytes of memory. {%s.LINE-%zu, %s()}\n",
-            __func__, Nmemb * Size, File, Line, Func);
+    fprintf(stderr, "%s() -- Could not allocate memory for %zu objects of %zu bytes each. {%s.LINE-%zu, %s()}\n",
+            __func__, Nmemb, Size, File, Line, Func);
     exit(1);
   }
 
