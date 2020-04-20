$NetBSD: patch-es-app_src_MetaData.h,v 1.1 2020/04/20 00:35:23 joerg Exp $

--- es-app/src/MetaData.h.orig	2020-04-19 17:33:17.811997487 +0000
+++ es-app/src/MetaData.h
@@ -3,6 +3,7 @@
 #define ES_APP_META_DATA_H
 
 #include <map>
+#include <string>
 #include <vector>
 
 namespace pugi { class xml_node; }
