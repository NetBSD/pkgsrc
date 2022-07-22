$NetBSD: patch-lib_jxl_base_os__macros.h,v 1.1 2022/07/22 20:17:14 wiz Exp $

* add NetBSD support

--- lib/jxl/base/os_macros.h.orig	2021-10-04 18:02:44.000000000 +0000
+++ lib/jxl/base/os_macros.h
@@ -47,4 +47,10 @@
 #define JXL_OS_HAIKU 0
 #endif
 
+#ifdef __NetBSD__
+#define JXL_OS_NETBSD 1
+#else
+#define JXL_OS_NETBSD 0
+#endif
+
 #endif  // LIB_JXL_BASE_OS_MACROS_H_
