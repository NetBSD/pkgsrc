$NetBSD: patch-src_control.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/control.cc.orig	2013-05-03 23:09:27.000000000 +0000
+++ src/control.cc
@@ -58,6 +58,14 @@
 
 #include "control.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 Control::Control() :
   m_ui(new ui::Root()),
   m_display(new display::Manager()),
@@ -77,7 +85,7 @@ Control::Control() :
 
   m_inputStdin->slot_pressed(sigc::mem_fun(m_input, &input::Manager::pressed));
 
-  m_taskShutdown.slot() = std::tr1::bind(&Control::handle_shutdown, this);
+  m_taskShutdown.slot() = std::bind(&Control::handle_shutdown, this);
 
   m_commandScheduler->set_slot_error_message(rak::mem_fn(m_core, &core::Manager::push_log_std));
 }
