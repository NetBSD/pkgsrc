$NetBSD: patch-src_helpers_proceduralskytexturedata.cpp,v 1.1 2024/11/04 09:39:14 jperkin Exp $

Avoid "sun" conflict.

--- src/helpers/proceduralskytexturedata.cpp.orig	2024-11-04 09:36:59.905773824 +0000
+++ src/helpers/proceduralskytexturedata.cpp
@@ -11,6 +11,8 @@
 #include <QtQuick3DRuntimeRender/private/qssgrendertexturedata_p.h>
 #include <QtQuick3DRuntimeRender/private/qssgrenderimage_p.h>
 
+#undef sun
+
 QT_BEGIN_NAMESPACE
 
 /*!
