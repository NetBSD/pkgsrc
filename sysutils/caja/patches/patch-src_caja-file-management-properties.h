$NetBSD: patch-src_caja-file-management-properties.h,v 1.1 2016/05/22 13:01:45 youri Exp $

Fix build on Darwin.

--- src/caja-file-management-properties.h.orig	2015-07-16 07:11:15.000000000 +0000
+++ src/caja-file-management-properties.h
@@ -38,4 +38,6 @@ extern "C" {
 }
 #endif
 
+GSettings *caja_preferences;
+
 #endif /* CAJA_FILE_MANAGEMENT_PROPERTIES_H */
