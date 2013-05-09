$NetBSD: patch-src_command__scheduler.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_scheduler.cc.orig	2012-03-20 16:25:05.000000000 +0000
+++ src/command_scheduler.cc
@@ -48,6 +48,16 @@
 #include "control.h"
 #include "command_helpers.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 torrent::Object
 cmd_scheduler_simple_added(core::Download* download) {
   unsigned int numActive = (*control->view_manager()->find("active"))->size_visible();
@@ -115,7 +125,7 @@ void
 initialize_command_scheduler() {
   CMD2_VAR_VALUE("scheduler.max_active", int64_t(-1));
 
-  CMD2_DL("scheduler.simple.added",   tr1::bind(&cmd_scheduler_simple_added, tr1::placeholders::_1));
-  CMD2_DL("scheduler.simple.removed", tr1::bind(&cmd_scheduler_simple_removed, tr1::placeholders::_1));
-  CMD2_DL("scheduler.simple.update",  tr1::bind(&cmd_scheduler_simple_update, tr1::placeholders::_1));
+  CMD2_DL("scheduler.simple.added",   bind(&cmd_scheduler_simple_added, STD_PLACEHOLDERS::_1));
+  CMD2_DL("scheduler.simple.removed", bind(&cmd_scheduler_simple_removed, STD_PLACEHOLDERS::_1));
+  CMD2_DL("scheduler.simple.update",  bind(&cmd_scheduler_simple_update, STD_PLACEHOLDERS::_1));
 }
