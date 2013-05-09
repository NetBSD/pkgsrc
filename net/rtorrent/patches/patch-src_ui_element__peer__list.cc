$NetBSD: patch-src_ui_element__peer__list.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/ui/element_peer_list.cc.orig	2013-05-03 22:56:26.000000000 +0000
+++ src/ui/element_peer_list.cc
@@ -54,6 +54,16 @@
 #include "element_peer_list.h"
 #include "element_text.h"
 
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
 namespace ui {
 
 ElementPeerList::ElementPeerList(core::Download* d) :
@@ -68,9 +78,9 @@ ElementPeerList::ElementPeerList(core::D
   torrent::ConnectionList* connection_list = m_download->download()->connection_list();
 
   m_peer_connected = connection_list->signal_connected().insert(connection_list->signal_connected().end(),
-                                                                tr1::bind(&ElementPeerList::receive_peer_connected, this, tr1::placeholders::_1));
+                                                                bind(&ElementPeerList::receive_peer_connected, this, STD_PLACEHOLDERS::_1));
   m_peer_disconnected = connection_list->signal_disconnected().insert(connection_list->signal_disconnected().end(),
-                                                                      tr1::bind(&ElementPeerList::receive_peer_disconnected, this, tr1::placeholders::_1));
+                                                                      bind(&ElementPeerList::receive_peer_disconnected, this, STD_PLACEHOLDERS::_1));
 
   m_windowList  = new display::WindowPeerList(m_download, &m_list, &m_listItr);
   m_elementInfo = create_info();
