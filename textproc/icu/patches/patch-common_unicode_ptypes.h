$NetBSD: patch-common_unicode_ptypes.h,v 1.1 2024/05/29 15:38:34 adam Exp $

Fix build: it seems like uchar.h in only available in glibc.

--- common/unicode/ptypes.h.orig	2024-04-16 21:08:53.000000000 +0000
+++ common/unicode/ptypes.h
@@ -56,7 +56,7 @@
 // implementations (looking at you, Apple, spring 2024) actually do this, so
 // ICU4C must detect and deal with that.
 #if !defined(__cplusplus) && !defined(U_IN_DOXYGEN)
-#   if U_HAVE_CHAR16_T
+#   if U_HAVE_CHAR16_T && U_PLATFORM_IS_LINUX_BASED
 #       include <uchar.h>
 #   else
         typedef uint16_t char16_t;
