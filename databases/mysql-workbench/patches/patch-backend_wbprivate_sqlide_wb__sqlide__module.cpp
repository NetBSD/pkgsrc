$NetBSD: patch-backend_wbprivate_sqlide_wb__sqlide__module.cpp,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- backend/wbprivate/sqlide/wb_sqlide_module.cpp.orig	2013-02-28 23:08:16.000000000 +0000
+++ backend/wbprivate/sqlide/wb_sqlide_module.cpp
@@ -23,7 +23,7 @@ grt::ListRef<app_Plugin> WbSqlIdeImpl::g
 {\
   plugin= app_PluginRef(grt);\
   plugin->name(Recordset_data_storage::DATA_STORAGE_MODULE_NAME_PREFIX + data_format);\
-  plugin->caption("Get "data_format" data storage");\
+  plugin->caption("Get " data_format " data storage");\
   plugin->description(desc);\
   plugin->moduleName("WbSqlIde");\
   plugin->moduleFunctionName(Recordset_data_storage::DATA_STORAGE_MODULE_GETTER);\
