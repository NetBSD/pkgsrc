$NetBSD: patch-src_qml_common_qv4alloca__p.h,v 1.3 2024/10/25 10:41:58 adam Exp $

Make sure we pick up gcc's builtin alloca on NetBSD

--- src/qml/common/qv4alloca_p.h.orig	2024-10-02 08:59:48.000000000 +0000
+++ src/qml/common/qv4alloca_p.h
@@ -43,9 +43,13 @@
 #define Q_ALLOCA_DECLARE(type, name) \
     type *name = 0
 
+#if defined(__GNUC__)
+#define Q_ALLOCA_ASSIGN(type, name, size) \
+    name = static_cast<type*>(__builtin_alloca(size))
+#else
 #define Q_ALLOCA_ASSIGN(type, name, size) \
     name = static_cast<type*>(alloca(size))
-
+#endif
 #else
 #  include <memory>
 
