$NetBSD: patch-cpucycles_fakenanoseconds.h,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Part of Debian 0008-add-cpucycles-fakenanoseconds.patch:
Provide a fakenanoseconds implementation for portability.

--- cpucycles/fakenanoseconds.h.orig	2022-01-05 13:32:14.000000000 +0000
+++ cpucycles/fakenanoseconds.h
@@ -0,0 +1,21 @@
+#ifndef CPUCYCLES_fakenanoseconds_h
+#define CPUCYCLES_fakenanoseconds_h
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+extern long long cpucycles_fakenanoseconds(void);
+extern long long cpucycles_fakenanoseconds_persecond(void);
+
+#ifdef __cplusplus
+}
+#endif
+
+#ifndef cpucycles_implementation
+#define cpucycles_implementation "fakenanoseconds"
+#define cpucycles cpucycles_fakenanoseconds
+#define cpucycles_persecond cpucycles_fakenanoseconds_persecond
+#endif
+
+#endif
