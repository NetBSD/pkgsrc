$NetBSD: patch-src_ConcurrentTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ConcurrentTracert.cc.orig	2020-03-27 18:19:16.969383442 +0000
+++ src/ConcurrentTracert.cc
@@ -19,7 +19,7 @@ ConcurrentTracert::ConcurrentTracert (Op
 
   ttl_max = ttl;
   
-  log(INFO, "Concurrent algo");
+  mylog(INFO, "Concurrent algo");
 }
 
 ConcurrentTracert::~ConcurrentTracert () {
@@ -117,6 +117,6 @@ ConcurrentTracert::getMaxTTL () {
 
 uint8
 ConcurrentTracert::getNbrReplies(uint8 ttl) {
-  log(WARN, "TODO");
+  mylog(WARN, "TODO");
   return 0;
 }
