$NetBSD: patch-src_libutil_fmath__test.cpp,v 1.1 2025/08/13 06:35:14 wiz Exp $

--- src/libutil/fmath_test.cpp.orig	2025-08-13 06:25:41.173006216 +0000
+++ src/libutil/fmath_test.cpp
@@ -534,7 +534,7 @@ test_half_convert_accuracy()
             && Imath::finitef(H[i])) {
             ++nwrong;
             Strutil::print("wrong {} 0b{}  h={}, f={} {}\n", i, bin16(i), H[i],
-                           F[i], isnan(f) ? "(nan)" : "");
+                           F[i], std::isnan(f) ? "(nan)" : "");
         }
     }
 
