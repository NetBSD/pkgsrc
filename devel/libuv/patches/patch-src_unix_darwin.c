$NetBSD: patch-src_unix_darwin.c,v 1.1 2017/12/11 13:32:12 jperkin Exp $

Provide compat strnlen for older Darwin.

--- src/unix/darwin.c.orig	2017-12-01 02:07:38.000000000 +0000
+++ src/unix/darwin.c
@@ -229,3 +229,15 @@ void uv_free_cpu_info(uv_cpu_info_t* cpu
 
   uv__free(cpu_infos);
 }
+
+#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070
+size_t strnlen(const char* s, size_t maxlen) {
+  size_t len;
+
+  for (len = 0; len < maxlen; len++, s++) {
+    if (!*s)
+      break;
+  }
+  return (len);
+}
+#endif
