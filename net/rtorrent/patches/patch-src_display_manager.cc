$NetBSD: patch-src_display_manager.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/display/manager.cc.orig	2013-05-03 22:48:16.000000000 +0000
+++ src/display/manager.cc
@@ -45,12 +45,20 @@
 #include "manager.h"
 #include "window.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace display {
 
 Manager::Manager() :
   m_forceRedraw(false) {
 
-  m_taskUpdate.slot() = std::tr1::bind(&Manager::receive_update, this);
+  m_taskUpdate.slot() = bind(&Manager::receive_update, this);
 }
 
 Manager::~Manager() {
