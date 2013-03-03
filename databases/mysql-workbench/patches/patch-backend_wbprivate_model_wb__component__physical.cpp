$NetBSD: patch-backend_wbprivate_model_wb__component__physical.cpp,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- backend/wbprivate/model/wb_component_physical.cpp.orig	2013-02-28 23:01:03.000000000 +0000
+++ backend/wbprivate/model/wb_component_physical.cpp
@@ -89,12 +89,12 @@ void WBComponentPhysical::load_app_optio
 
     toolbar= app_ToolbarRef::cast_from(
       grt->unserialize(make_path(_wb->get_datadir(),"data/model_option_toolbar_physical_relationship.xml")));
-    _toolbars["main/"WB_TOOL_PREL11_NOID]= toolbar;
-    _toolbars["main/"WB_TOOL_PREL1n_NOID]= toolbar;
-    _toolbars["main/"WB_TOOL_PREL11]= toolbar;
-    _toolbars["main/"WB_TOOL_PREL1n]= toolbar;
-    _toolbars["main/"WB_TOOL_PRELnm]= toolbar;
-    _toolbars["main/"WB_TOOL_PREL_PICK]= toolbar;
+    _toolbars["main/" WB_TOOL_PREL11_NOID]= toolbar;
+    _toolbars["main/" WB_TOOL_PREL1n_NOID]= toolbar;
+    _toolbars["main/" WB_TOOL_PREL11]= toolbar;
+    _toolbars["main/" WB_TOOL_PREL1n]= toolbar;
+    _toolbars["main/" WB_TOOL_PRELnm]= toolbar;
+    _toolbars["main/" WB_TOOL_PREL_PICK]= toolbar;
 
     _shortcuts= grt::ListRef<app_ShortcutItem>::cast_from(
       grt->unserialize(make_path(_wb->get_datadir(),"data/shortcuts_physical.xml")));
