$NetBSD: patch-src_ScoutTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ScoutTracert.cc.orig	2020-03-27 18:20:08.083937225 +0000
+++ src/ScoutTracert.cc
@@ -68,6 +68,6 @@ ScoutTracert::trace (char* target, int i
 
 uint8
 ScoutTracert::getNbrReplies(uint8 ttl) {
-  log(WARN, "TODO");
+  mylog(WARN, "TODO");
   return 0;
 }
