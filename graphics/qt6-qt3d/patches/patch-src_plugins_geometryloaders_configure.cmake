$NetBSD: patch-src_plugins_geometryloaders_configure.cmake,v 1.1 2022/11/25 22:19:12 nros Exp $

* make sure fbx is disabled by -no-fbxsdk

--- src/plugins/geometryloaders/configure.cmake.orig	2021-01-28 05:17:13.000000000 +0000
+++ src/plugins/geometryloaders/configure.cmake
@@ -24,6 +24,7 @@ qt_config_compile_test("qt3d_fbxsdk"
 qt_feature("qt3d_fbxsdk" PRIVATE
     LABEL "Autodesk FBX"
     CONDITION libs.fbx #OR FIXME
+    DISABLE INPUT_fbxsdk STREQUAL 'no'
 )
 qt_feature_definition("qt3d_fbxsdk" "QT_3DGEOMETRYLOADERS_FBX")
 
