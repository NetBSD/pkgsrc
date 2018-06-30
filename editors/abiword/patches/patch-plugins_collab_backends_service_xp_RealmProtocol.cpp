$NetBSD: patch-plugins_collab_backends_service_xp_RealmProtocol.cpp,v 1.1 2018/06/30 12:43:29 maya Exp $

Bug 13754 - Fix build on gcc-6 (default to C++11)
https://github.com/AbiWord/abiword/commit/a83e6f50dbd5efa16fb39efe32b9de370f103130

--- plugins/collab/backends/service/xp/RealmProtocol.cpp.orig	2009-05-27 05:41:59.000000000 +0000
+++ plugins/collab/backends/service/xp/RealmProtocol.cpp
@@ -6,8 +6,8 @@ namespace protocolv1 {
 
 #define MAX_PACKET_DATA_SIZE 64*1024*1024
 		
-#define RPV1_PACKET_NONEXISTENT -2
-#define RPV1_PACKET_VARIABLE -1
+#define RPV1_PACKET_NONEXISTENT uint32_t(-2)
+#define RPV1_PACKET_VARIABLE uint32_t(-1)
 	
 static uint32_t body_size[6] = {
 	RPV1_PACKET_NONEXISTENT, /* 0: reserved */
