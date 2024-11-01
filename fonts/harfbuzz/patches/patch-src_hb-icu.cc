$NetBSD: patch-src_hb-icu.cc,v 1.1 2024/11/01 07:21:17 wiz Exp $

Fix build with icu 76.1.
https://github.com/harfbuzz/harfbuzz/commit/9974a66169c29cc2c5703ac6ad1764da2c763c66

--- src/hb-icu.cc.orig	2024-09-24 16:52:43.000000000 +0000
+++ src/hb-icu.cc
@@ -31,6 +31,11 @@
 
 #ifdef HAVE_ICU
 
+#pragma GCC diagnostic push
+
+// https://github.com/harfbuzz/harfbuzz/issues/4915
+#pragma GCC diagnostic ignored "-Wredundant-decls"
+
 #include "hb-icu.h"
 
 #include "hb-machinery.hh"
@@ -44,7 +49,6 @@
 /* ICU extra semicolon, fixed since 65, https://github.com/unicode-org/icu/commit/480bec3 */
 #if U_ICU_VERSION_MAJOR_NUM < 65 && (defined(__GNUC__) || defined(__clang__))
 #define HB_ICU_EXTRA_SEMI_IGNORED
-#pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wextra-semi-stmt"
 #endif
 
@@ -284,8 +288,6 @@ hb_icu_get_unicode_funcs ()
   return static_icu_funcs.get_unconst ();
 }
 
-#ifdef HB_ICU_EXTRA_SEMI_IGNORED
 #pragma GCC diagnostic pop
-#endif
 
 #endif
