$NetBSD: patch-src_libOpenImageIO_imagebufalgo__compare.cpp,v 1.1 2025/08/13 06:35:13 wiz Exp $

--- src/libOpenImageIO/imagebufalgo_compare.cpp.orig	2025-08-13 06:18:52.121013693 +0000
+++ src/libOpenImageIO/imagebufalgo_compare.cpp
@@ -21,6 +21,8 @@
 
 #include "imageio_pvt.h"
 
+using namespace std;
+
 OIIO_NAMESPACE_BEGIN
 
 
