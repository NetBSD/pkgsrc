$NetBSD: patch-src_network_bufferedconnection.h,v 1.1 2020/07/27 15:21:43 nia Exp $

Needs std::map.

--- src/network/bufferedconnection.h.orig	2020-07-12 19:33:44.000000000 +0000
+++ src/network/bufferedconnection.h
@@ -20,6 +20,7 @@
 #ifndef WL_NETWORK_BUFFEREDCONNECTION_H
 #define WL_NETWORK_BUFFEREDCONNECTION_H
 
+#include <map>
 #include <memory>
 #include <mutex>
 #include <thread>
