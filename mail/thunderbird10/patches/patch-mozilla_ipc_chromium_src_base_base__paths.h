$NetBSD: patch-mozilla_ipc_chromium_src_base_base__paths.h,v 1.1.1.1 2012/03/15 09:45:29 ryoon Exp $

--- mozilla/ipc/chromium/src/base/base_paths.h.orig	2012-02-16 10:25:01.000000000 +0000
+++ mozilla/ipc/chromium/src/base/base_paths.h
@@ -13,7 +13,7 @@
 #include "base/base_paths_win.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/base_paths_linux.h"
 #endif
 #include "base/path_service.h"
