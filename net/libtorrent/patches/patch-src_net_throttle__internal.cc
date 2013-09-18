$NetBSD: patch-src_net_throttle__internal.cc,v 1.3 2013/09/18 16:32:05 joerg Exp $

--- src/net/throttle_internal.cc.orig	2012-02-14 03:15:27.000000000 +0000
+++ src/net/throttle_internal.cc
@@ -47,6 +47,12 @@
 
 #include "globals.h"
 
+#if __cplusplus >= 201103L
+using std::bind;
+#else
+using std::tr1::bind;
+#endif
+
 namespace torrent {
 
 // Plans:
@@ -62,7 +68,7 @@ ThrottleInternal::ThrottleInternal(int f
   m_timeLastTick(cachedTime) {
 
   if (is_root())
-    m_taskTick.slot() = std::tr1::bind(&ThrottleInternal::receive_tick, this);
+    m_taskTick.slot() = bind(&ThrottleInternal::receive_tick, this);
 }
 
 ThrottleInternal::~ThrottleInternal() {
