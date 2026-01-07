$NetBSD: patch-src_zm__packetqueue.cpp,v 1.1 2026/01/07 01:05:07 gdt Exp $

--- src/zm_packetqueue.cpp.orig	2026-01-07 00:37:01.465457236 +0000
+++ src/zm_packetqueue.cpp
@@ -260,7 +260,7 @@ void PacketQueue::clearPackets(const std
       --it;
     }
   }
-  Debug(1, "Tail count is %d, queue size is %lu", tail_count, pktQueue.size());
+  Debug(1, "Tail count is %d, queue size is %ju", tail_count, static_cast<uintmax_t>(pktQueue.size()));
 
   if (!keep_keyframes) {
     // If not doing passthrough, we don't care about starting with a keyframe so logic is simpler
