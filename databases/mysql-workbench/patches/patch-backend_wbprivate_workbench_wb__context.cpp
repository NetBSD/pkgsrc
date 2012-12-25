$NetBSD: patch-backend_wbprivate_workbench_wb__context.cpp,v 1.1 2012/12/25 21:12:31 joerg Exp $

--- backend/wbprivate/workbench/wb_context.cpp.orig	2012-12-25 15:17:54.000000000 +0000
+++ backend/wbprivate/workbench/wb_context.cpp
@@ -128,6 +128,8 @@ ENABLE_LOG("wbprivate")
 #define HAVE_BUNDLED_MYSQLDUMP
 #endif
 
+void register_all_metaclasses();
+
 using namespace grt;
 using namespace bec;
 using namespace wb;
@@ -194,7 +196,6 @@ WBContext::WBContext(WBContextUI *ui, bo
   : _asked_for_saving(false), _uicontext(ui), _model_context(0), _sqlide_context(ui), _file(0),
     _save_point(0), _tunnel_manager(0)
 { 
-  extern void register_all_metaclasses();
   static bool registered_metaclasses= false;
 
   g_log_set_handler(NULL, (GLogLevelFlags)0xfffff, log_func, this);
