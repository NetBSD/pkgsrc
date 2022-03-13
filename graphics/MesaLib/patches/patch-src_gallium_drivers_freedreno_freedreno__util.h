$NetBSD: patch-src_gallium_drivers_freedreno_freedreno__util.h,v 1.1 2022/03/13 15:52:50 tnn Exp $

gettid() is linux-specific

--- src/gallium/drivers/freedreno/freedreno_util.h.orig	2022-01-12 21:32:28.000000000 +0000
+++ src/gallium/drivers/freedreno/freedreno_util.h
@@ -108,6 +108,7 @@ extern bool fd_binning_enabled;
 #include <sys/types.h>
 #include <sys/syscall.h>
 
+#if defined(__linux__)
 #define DBG(fmt, ...)                                                          \
    do {                                                                        \
       if (FD_DBG(MSGS))                                                        \
@@ -115,6 +116,16 @@ extern bool fd_binning_enabled;
                                         __FUNCTION__, __LINE__,                \
                                         ##__VA_ARGS__);                        \
    } while (0)
+#else
+#define DBG(fmt, ...)                                                          \
+   do {                                                                        \
+      if (FD_DBG(MSGS))                                                        \
+         mesa_logi("%s:%d: " fmt,                                              \
+                                        __FUNCTION__, __LINE__,                \
+                                        ##__VA_ARGS__);                        \
+   } while (0)
+#endif
+
 
 #define perf_debug_message(debug, type, ...)                                   \
    do {                                                                        \
