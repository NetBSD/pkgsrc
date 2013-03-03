$NetBSD: patch-backend_wbprivate_workbench_wb__module.cpp,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- backend/wbprivate/workbench/wb_module.cpp.orig	2013-03-02 18:27:50.000000000 +0000
+++ backend/wbprivate/workbench/wb_module.cpp
@@ -85,7 +85,7 @@ void WorkbenchImpl::set_context(WBContex
 #define def_plugin(group, aName, type, aCaption, descr)\
   {\
     app_PluginRef plugin(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -98,7 +98,7 @@ void WorkbenchImpl::set_context(WBContex
 #define def_object_plugin(group, klass, aName, aCaption, descr)\
   {\
     app_PluginRef plugin(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -116,7 +116,7 @@ void WorkbenchImpl::set_context(WBContex
 #define def_view_plugin(group, aName, aCaption, descr)\
   {\
     app_PluginRef plugin(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -134,7 +134,7 @@ void WorkbenchImpl::set_context(WBContex
 #define def_model_plugin(group, aName, aCaption, descr)\
   {\
     app_PluginRef plugin(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -152,7 +152,7 @@ void WorkbenchImpl::set_context(WBContex
 #define def_form_model_plugin(group, aName, aCaption, descr)\
   {\
     app_PluginRef plugin(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -170,7 +170,7 @@ void WorkbenchImpl::set_context(WBContex
 #define def_form_plugin(group, aName, aCaption, descr)\
   {\
     app_PluginRef plugin(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -185,7 +185,7 @@ void WorkbenchImpl::set_context(WBContex
   {\
     app_PluginRef plugin(get_grt());\
     app_PluginInputDefinitionRef pdef(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -201,7 +201,7 @@ void WorkbenchImpl::set_context(WBContex
 #define def_model_arg_plugin(group, aName, type, aCaption, descr)\
   {\
     app_PluginRef plugin(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -224,7 +224,7 @@ void WorkbenchImpl::set_context(WBContex
   {\
     app_PluginRef plugin(get_grt());\
     app_PluginFileInputRef pdef(get_grt());\
-    plugin->name("wb."group"."aName);\
+    plugin->name("wb." group "." aName);\
     plugin->caption(aCaption);\
     plugin->description(descr);\
     plugin->moduleName("Workbench");\
@@ -1127,7 +1127,7 @@ int WorkbenchImpl::debugShowInfo()
 #define NATIVE_RENDERER "Native"
 #endif
 
-  grt->send_output(strfmt("MySQL Workbench "EDITION_NAME" for "PLATFORM_NAME" version %i.%i.%i\n", APP_MAJOR_NUMBER, APP_MINOR_NUMBER, APP_RELEASE_NUMBER));
+  grt->send_output(strfmt("MySQL Workbench " EDITION_NAME " for " PLATFORM_NAME " version %i.%i.%i\n", APP_MAJOR_NUMBER, APP_MINOR_NUMBER, APP_RELEASE_NUMBER));
 
   grt->send_output(strfmt("Configuration Directory: %s\n", _wb->get_grt_manager()->get_user_datadir().c_str()));
   grt->send_output(strfmt("Data Directory: %s\n", _wb->get_grt_manager()->get_basedir().c_str()));
@@ -1153,9 +1153,9 @@ int WorkbenchImpl::debugShowInfo()
   else
   {
     if (_wb->is_opengl_available())
-      render_mode=  ("but "NATIVE_RENDERER" was requested. Using "NATIVE_RENDERER" for rendering.");
+      render_mode=  ("but " NATIVE_RENDERER " was requested. Using " NATIVE_RENDERER " for rendering.");
     else
-      render_mode=  ("so "NATIVE_RENDERER" is used for rendering.");
+      render_mode=  ("so " NATIVE_RENDERER " is used for rendering.");
   }
 
   grt->send_output(strfmt("Rendering Mode: %s, %s\n", ogl_state, render_mode));
