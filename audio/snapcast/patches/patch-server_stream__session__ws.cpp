$NetBSD: patch-server_stream__session__ws.cpp,v 1.1 2025/01/31 16:20:06 wiz Exp $

Fix build with boost 1.87.
https://github.com/badaix/snapcast/commit/6190041e863968d76b6d16140bba90be6dff848f

--- server/stream_session_ws.cpp.orig	2025-01-31 16:03:19.618894855 +0000
+++ server/stream_session_ws.cpp
@@ -107,7 +107,7 @@ void StreamSessionWebsocket::on_read_ws(
         return;
     }
 
-    auto* data = boost::asio::buffer_cast<char*>(buffer_.data());
+    auto* data = static_cast<char*>(buffer_.data().data());
     baseMessage_.deserialize(data);
     LOG(DEBUG, LOG_TAG) << "getNextMessage: " << baseMessage_.type << ", size: " << baseMessage_.size << ", id: " << baseMessage_.id
                         << ", refers: " << baseMessage_.refersTo << "\n";
