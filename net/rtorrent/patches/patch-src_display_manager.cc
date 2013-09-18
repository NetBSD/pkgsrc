$NetBSD: patch-src_display_manager.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/display/manager.cc.orig	2012-02-14 03:32:01.000000000 +0000
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
