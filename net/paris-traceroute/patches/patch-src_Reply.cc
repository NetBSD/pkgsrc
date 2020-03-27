$NetBSD: patch-src_Reply.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/Reply.cc.orig	2020-03-27 18:20:05.312213338 +0000
+++ src/Reply.cc
@@ -20,11 +20,11 @@ Reply::replyFactory (const uint8* packet
       case 6:  // TCP
         return new TCPReply(packet, packet_len);
       default:
-        log(DUMP, "The reply used protocol %d", protocol);
+        mylog(DUMP, "The reply used protocol %d", protocol);
         return NULL;
     }
   } else {
-    log(DUMP, "Malformed reply");
+    mylog(DUMP, "Malformed reply");
     return NULL;
   }
 }
