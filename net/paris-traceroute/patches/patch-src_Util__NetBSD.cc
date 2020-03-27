$NetBSD: patch-src_Util__NetBSD.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/Util_NetBSD.cc.orig	2020-03-27 18:20:30.573271054 +0000
+++ src/Util_NetBSD.cc
@@ -37,7 +37,7 @@ Util::getRoute (const char* dest) {
   //#fscanf(fd, "%s", buff);
   //pclose(fd);
 
-  log(INFO, "Source address = %s\n", buff);
+  mylog(INFO, "Source address = %s\n", buff);
 
   return strdup(buff);
 }
@@ -191,7 +191,7 @@ Util::write32 (uint8* data, int ofs, uin
 int
 Util::protocol2int (const char* protocol) {
   struct protoent* proto = getprotobyname(protocol);
-  log(DUMP, "p_proto = %d", proto->p_proto);
+  mylog(DUMP, "p_proto = %d", proto->p_proto);
   return proto->p_proto;
 }
 
