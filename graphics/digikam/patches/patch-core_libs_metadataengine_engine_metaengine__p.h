$NetBSD: patch-core_libs_metadataengine_engine_metaengine__p.h,v 1.1 2023/07/02 07:44:18 wiz Exp $

Fix build with exiv2 0.28.0.
https://invent.kde.org/graphics/digikam/-/commit/4896cef0.patch

--- core/libs/metadataengine/engine/metaengine_p.h.orig	2023-04-12 16:24:31.000000000 +0000
+++ core/libs/metadataengine/engine/metaengine_p.h
@@ -89,6 +89,7 @@
 #   define AutoPtr UniquePtr
 #   define AnyError Error
 #   define kerErrorMessage ErrorCode::kerErrorMessage
+#   include <exiv2/photoshop.hpp>
 #endif
 
 #if EXIV2_TEST_VERSION(0,27,4)
