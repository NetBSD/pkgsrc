$NetBSD: patch-backend_wbprivate_workbench_wb__model__file.cpp,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- backend/wbprivate/workbench/wb_model_file.cpp.orig	2013-02-28 23:16:25.000000000 +0000
+++ backend/wbprivate/workbench/wb_model_file.cpp
@@ -61,7 +61,7 @@
 #define DB_DIR "@db"
 #define DB_FILE "data.db"
 
-#define ZIP_FILE_COMMENT DOCUMENT_FORMAT" archive "ZIP_FILE_FORMAT
+#define ZIP_FILE_COMMENT DOCUMENT_FORMAT " archive " ZIP_FILE_FORMAT
 
 
 
