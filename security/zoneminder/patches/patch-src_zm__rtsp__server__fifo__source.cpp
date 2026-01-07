$NetBSD: patch-src_zm__rtsp__server__fifo__source.cpp,v 1.1 2026/01/07 01:05:07 gdt Exp $

--- src/zm_rtsp_server_fifo_source.cpp.orig	2026-01-07 00:40:02.455387707 +0000
+++ src/zm_rtsp_server_fifo_source.cpp
@@ -214,8 +214,8 @@ int ZoneMinderFifoSource::getNextFrame()
       return 0;
     }
     if (header_start != m_buffer) {
-      Debug(4, "ZM Packet didn't start at beginning of buffer %ld. %c%c",
-            header_start - m_buffer.head(), m_buffer[0], m_buffer[1]);
+      Debug(4, "ZM Packet didn't start at beginning of buffer %jd. %c%c",
+            static_cast<intmax_t>(header_start - m_buffer.head()), m_buffer[0], m_buffer[1]);
     }
 
     // read_into may invalidate packet_start
