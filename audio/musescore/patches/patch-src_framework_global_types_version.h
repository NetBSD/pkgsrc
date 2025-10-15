$NetBSD: patch-src_framework_global_types_version.h,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Undef major and minor defines present on NetBSD.

--- src/framework/global/types/version.h.orig	2025-07-21 10:09:45.359486059 +0000
+++ src/framework/global/types/version.h
@@ -26,6 +26,9 @@
 
 #include "types/string.h"
 
+#undef major
+#undef minor
+
 namespace muse {
 class Version
 {
