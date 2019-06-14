$NetBSD: patch-libsanitizer_sanitizer__common_sanitizer__platform.h,v 1.1 2019/06/14 09:42:36 adam Exp $

Fix building on Darwin.

--- libsanitizer/sanitizer_common/sanitizer_platform.h.orig	2019-05-22 05:55:43.000000000 +0000
+++ libsanitizer/sanitizer_common/sanitizer_platform.h
@@ -31,6 +31,9 @@
 #if defined(__APPLE__)
 # define SANITIZER_MAC     1
 # include <TargetConditionals.h>
+# if !defined(_Atomic)
+#  define _Atomic volatile
+# endif
 # if TARGET_OS_IPHONE
 #  define SANITIZER_IOS    1
 # else
