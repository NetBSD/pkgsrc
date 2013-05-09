$NetBSD: patch-src_core_manager.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/manager.cc.orig	2013-05-03 22:47:33.000000000 +0000
+++ src/core/manager.cc
@@ -205,7 +205,7 @@ Manager::get_address_throttle(const sock
 // Most of this should be possible to move out.
 void
 Manager::initialize_second() {
-  torrent::Http::slot_factory() = std::tr1::bind(&CurlStack::new_object, m_httpStack);
+  torrent::Http::slot_factory() = bind(&CurlStack::new_object, m_httpStack);
   m_httpQueue->slot_factory(sigc::mem_fun(m_httpStack, &CurlStack::new_object));
 
   CurlStack::global_init();
