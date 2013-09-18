$NetBSD: patch-src_ui_element__log__complete.cc,v 1.3 2013/09/18 16:33:09 joerg Exp $

--- src/ui/element_log_complete.cc.orig	2012-03-13 12:10:49.000000000 +0000
+++ src/ui/element_log_complete.cc
@@ -48,15 +48,23 @@
 #include "control.h"
 #include "element_log_complete.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace ui {
 
 ElementLogComplete::ElementLogComplete(torrent::log_buffer* l) :
   m_window(NULL),
   m_log(l) {
 
-  unsigned int signal_index = torrent::main_thread()->signal_bitfield()->add_signal(std::tr1::bind(&ElementLogComplete::received_update, this));
+  unsigned int signal_index = torrent::main_thread()->signal_bitfield()->add_signal(bind(&ElementLogComplete::received_update, this));
 
-  m_log->lock_and_set_update_slot(std::tr1::bind(&torrent::thread_base::send_event_signal, torrent::main_thread(), signal_index, false));
+  m_log->lock_and_set_update_slot(bind(&torrent::thread_base::send_event_signal, torrent::main_thread(), signal_index, false));
 }
 
 void
