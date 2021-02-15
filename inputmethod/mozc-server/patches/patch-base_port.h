$NetBSD: patch-base_port.h,v 1.5 2021/02/15 14:50:23 ryoon Exp $

--- base/port.h.orig	2021-02-15 05:04:33.000000000 +0000
+++ base/port.h
@@ -69,6 +69,10 @@ using std::string;
 #define MOZC_OS_DEFINED
 #endif  // OS_WASM
 
+#ifdef OS_NETBSD
+#define MOZC_OS_DEFINED
+#endif  // OS_NETBSD
+
 #ifndef MOZC_OS_DEFINED
 #error "OS_XXX (e.g., OS_WIN) must be defined."
 #endif  // !MOZC_OS_DEFINED
