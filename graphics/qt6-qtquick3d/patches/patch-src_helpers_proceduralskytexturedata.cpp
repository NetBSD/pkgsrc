$NetBSD: patch-src_helpers_proceduralskytexturedata.cpp,v 1.2 2025/09/22 05:43:27 adam Exp $

Avoid "sun" conflict.

--- src/helpers/proceduralskytexturedata.cpp.orig	2025-08-17 23:58:26.000000000 +0000
+++ src/helpers/proceduralskytexturedata.cpp
@@ -13,6 +13,8 @@
 
 #include <QtGui/qquaternion.h>
 
+#undef sun
+
 QT_BEGIN_NAMESPACE
 
 /*!
