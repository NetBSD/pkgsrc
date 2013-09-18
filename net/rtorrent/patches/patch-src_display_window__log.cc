$NetBSD: patch-src_display_window__log.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/display/window_log.cc.orig	2012-03-13 12:10:49.000000000 +0000
+++ src/display/window_log.cc
@@ -44,17 +44,25 @@
 #include "utils.h"
 #include "window_log.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace display {
 
 WindowLog::WindowLog(torrent::log_buffer* l) :
   Window(new Canvas, 0, 0, 0, extent_full, extent_static),
   m_log(l) {
 
-  m_taskUpdate.slot() = std::tr1::bind(&WindowLog::receive_update, this);
+  m_taskUpdate.slot() = bind(&WindowLog::receive_update, this);
 
-  unsigned int signal_index = torrent::main_thread()->signal_bitfield()->add_signal(std::tr1::bind(&WindowLog::receive_update, this));
+  unsigned int signal_index = torrent::main_thread()->signal_bitfield()->add_signal(bind(&WindowLog::receive_update, this));
 
-  m_log->lock_and_set_update_slot(std::tr1::bind(&torrent::thread_base::send_event_signal, torrent::main_thread(), signal_index, false));
+  m_log->lock_and_set_update_slot(bind(&torrent::thread_base::send_event_signal, torrent::main_thread(), signal_index, false));
 }
 
 WindowLog::~WindowLog() {
