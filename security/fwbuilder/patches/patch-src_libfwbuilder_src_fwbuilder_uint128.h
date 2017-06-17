$NetBSD: patch-src_libfwbuilder_src_fwbuilder_uint128.h,v 1.1 2017/06/17 19:52:13 joerg Exp $

Avoid User Defined Literals. Drop effectively redundant casts that
actually introduce warnings.

--- src/libfwbuilder/src/fwbuilder/uint128.h.orig	2017-06-10 17:34:20.490231501 +0000
+++ src/libfwbuilder/src/fwbuilder/uint128.h
@@ -466,9 +466,9 @@ public:
     {
         char buf[33];
         if (hi)
-            sprintf(buf, "%"PRIX64"%08"PRIX64, (unsigned long long)hi,(unsigned long long)lo);
+            sprintf(buf, "%" PRIX64"%08" PRIX64, hi, lo);
         else
-            sprintf(buf,"%"PRIX64,(unsigned long long)lo);
+            sprintf(buf,"%" PRIX64, lo);
         return buf;
     }
 
