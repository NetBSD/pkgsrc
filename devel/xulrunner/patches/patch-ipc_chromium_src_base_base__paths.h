$NetBSD: patch-ipc_chromium_src_base_base__paths.h,v 1.4 2012/08/28 23:27:10 ryoon Exp $

--- ipc/chromium/src/base/base_paths.h.orig	2012-08-24 22:55:37.000000000 +0000
+++ ipc/chromium/src/base/base_paths.h
@@ -13,7 +13,7 @@
 #include "base/base_paths_win.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/base_paths_linux.h"
 #endif
 #include "base/path_service.h"
