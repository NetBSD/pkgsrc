$NetBSD: patch-mozilla_ipc_chromium_src_base_base__paths.h,v 1.4 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/base_paths.h.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/base/base_paths.h
@@ -13,7 +13,7 @@
 #include "base/base_paths_win.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
-#elif defined(OS_LINUX) || defined(OS_BSD)
+#elif defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #include "base/base_paths_linux.h"
 #endif
 #include "base/path_service.h"
