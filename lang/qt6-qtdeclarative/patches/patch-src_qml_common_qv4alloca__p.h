$NetBSD: patch-src_qml_common_qv4alloca__p.h,v 1.1 2022/11/25 11:50:59 nros Exp $

Make sure we pick up gcc's builtin alloca on NetBSD

--- src/qml/common/qv4alloca_p.h.orig	2022-09-23 07:21:41.000000000 +0000
+++ src/qml/common/qv4alloca_p.h
@@ -42,9 +42,13 @@
 #define Q_ALLOCA_DECLARE(type, name) \
     type *name = 0
 
+#if defined(__GNUC__)
 #define Q_ALLOCA_ASSIGN(type, name, size) \
+    name = static_cast<type*>(__builtin_alloca(size))
+#else
+#define Q_ALLOCA_ASSIGN(type, name, size) \
     name = static_cast<type*>(alloca(size))
-
+#endif
 #else
 QT_BEGIN_NAMESPACE
 class Qt_AllocaWrapper
