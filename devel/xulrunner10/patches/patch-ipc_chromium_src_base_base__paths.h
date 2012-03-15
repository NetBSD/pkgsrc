$NetBSD: patch-ipc_chromium_src_base_base__paths.h,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- ipc/chromium/src/base/base_paths.h.orig	2012-03-09 22:20:16.000000000 +0000
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
