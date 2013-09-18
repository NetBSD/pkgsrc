$NetBSD: patch-src_core_manager.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/core/manager.cc.orig	2012-04-16 06:19:49.000000000 +0000
+++ src/core/manager.cc
@@ -74,6 +74,14 @@
 #include "poll_manager.h"
 #include "view.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace core {
 
 void
@@ -205,7 +213,7 @@ Manager::get_address_throttle(const sock
 // Most of this should be possible to move out.
 void
 Manager::initialize_second() {
-  torrent::Http::slot_factory() = std::tr1::bind(&CurlStack::new_object, m_httpStack);
+  torrent::Http::slot_factory() = bind(&CurlStack::new_object, m_httpStack);
   m_httpQueue->slot_factory(sigc::mem_fun(m_httpStack, &CurlStack::new_object));
 
   CurlStack::global_init();
