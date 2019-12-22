$NetBSD: patch-libcurvecpr-glib_include_curvecpr__glib_messager__glib.h,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr-glib/include/curvecpr_glib/messager_glib.h.orig	2019-12-22 17:54:31.023786330 +0000
+++ libcurvecpr-glib/include/curvecpr_glib/messager_glib.h
@@ -2,12 +2,11 @@
 #define __CURVECPR_GLIB_MESSAGER_GLIB_H
 
 #include <curvecpr/block.h>
+#include <curvecpr/bytes.h>
 #include <curvecpr/messager.h>
 
 #include <string.h>
 
-#include <sodium/crypto_uint64.h>
-
 #include <glib.h>
 
 struct curvecpr_messager_glib;
