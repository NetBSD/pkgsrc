$NetBSD: patch-include_ares__version.h,v 1.1 2024/10/14 22:06:30 wiz Exp $

Fix version for CMake.
https://github.com/c-ares/c-ares/issues/902

--- include/ares_version.h.orig	2024-10-14 22:00:00.204787470 +0000
+++ include/ares_version.h
@@ -44,8 +44,6 @@
 #define ARES_STRINGIFY_PRE(s) #s
 #define ARES_STRINGIFY(s)     ARES_STRINGIFY_PRE(s)
 
-#define ARES_VERSION_STR             \
-  ARES_STRINGIFY(ARES_VERSION_MAJOR) \
-  "." ARES_STRINGIFY(ARES_VERSION_MINOR) "." ARES_STRINGIFY(ARES_VERSION_PATCH)
+#define ARES_VERSION_STR             "1.34.1"
 
 #endif
