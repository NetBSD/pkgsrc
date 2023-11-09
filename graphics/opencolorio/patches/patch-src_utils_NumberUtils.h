$NetBSD: patch-src_utils_NumberUtils.h,v 1.1 2023/11/09 14:54:03 nros Exp $

Solaris does not have strtod_l and strtof_l
Portability fix, use "defined" to check for preprocessor defines

--- src/utils/NumberUtils.h.orig	2023-01-06 02:05:59.000000000 +0000
+++ src/utils/NumberUtils.h
@@ -64,6 +64,8 @@ really_inline from_chars_result from_cha
     double
 #ifdef _WIN32
     tempval = _strtod_l(first, &endptr, loc.local);
+#elif defined(__sun__)
+    tempval = ::strtod(first, &endptr);
 #else
     tempval = ::strtod_l(first, &endptr, loc.local);
 #endif
@@ -105,9 +107,11 @@ really_inline from_chars_result from_cha
 #else
     tempval = _strtof_l(first, &endptr, loc.local);
 #endif
-#elif __APPLE__
+#elif defined(__APPLE__)
     // On OSX, strtod_l is for some reason drastically faster than strtof_l.
     tempval = static_cast<float>(::strtod_l(first, &endptr, loc.local));
+#elif defined(__sun__)
+    tempval = ::strtof(first, &endptr);
 #else
     tempval = ::strtof_l(first, &endptr, loc.local);
 #endif
