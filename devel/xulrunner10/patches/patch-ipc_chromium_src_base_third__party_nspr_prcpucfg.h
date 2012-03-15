$NetBSD: patch-ipc_chromium_src_base_third__party_nspr_prcpucfg.h,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- ipc/chromium/src/base/third_party/nspr/prcpucfg.h.orig	2012-03-09 22:20:17.000000000 +0000
+++ ipc/chromium/src/base/third_party/nspr/prcpucfg.h
@@ -34,7 +34,7 @@
 #include "base/third_party/nspr/prcpucfg_win.h"
 #elif defined(__APPLE__)
 #include "base/third_party/nspr/prcpucfg_mac.h"
-#elif defined(__linux__) || defined(ANDROID)
+#elif defined(__linux__) || defined(ANDROID) || defined(__NetBSD__) || defined(__DragonFly__)
 #include "base/third_party/nspr/prcpucfg_linux.h"
 #elif defined(__OpenBSD__)
 #include "base/third_party/nspr/prcpucfg_openbsd.h"
