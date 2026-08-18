$NetBSD: patch-src_qml_common_qv4alloca__p.h,v 1.4 2026/08/18 18:26:03 adam Exp $

Make sure we pick up gcc's builtin alloca on NetBSD

--- src/qml/common/qv4alloca_p.h.orig	2026-08-11 19:34:46.000000000 +0000
+++ src/qml/common/qv4alloca_p.h
@@ -44,7 +44,11 @@
 
 #  define Q_ALLOCA_INIT()
 #  define Q_ALLOCA_DECLARE(type, name) type *name = nullptr
+#if defined(__GNUC__)
+#  define Q_ALLOCA_ASSIGN(type, name, size) name = static_cast<type *>(__builtin_alloca(size))
+#else
 #  define Q_ALLOCA_ASSIGN(type, name, size) name = static_cast<type *>(alloca(size))
+#endif
 
 #else
 #  include <memory>
