$NetBSD: patch-es-app_src_FileFilterIndex.h,v 1.1 2020/04/20 00:35:23 joerg Exp $

--- es-app/src/FileFilterIndex.h.orig	2020-04-19 17:33:56.878739257 +0000
+++ es-app/src/FileFilterIndex.h
@@ -3,6 +3,7 @@
 #define ES_APP_FILE_FILTER_INDEX_H
 
 #include <map>
+#include <string>
 #include <vector>
 
 class FileData;
