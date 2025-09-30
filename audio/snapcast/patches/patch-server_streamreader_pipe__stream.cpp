$NetBSD: patch-server_streamreader_pipe__stream.cpp,v 1.2 2025/09/30 06:49:38 adam Exp $

Add NetBSD support.

--- server/streamreader/pipe_stream.cpp.orig	2025-09-29 07:26:16.257566594 +0000
+++ server/streamreader/pipe_stream.cpp
@@ -73,7 +73,7 @@ void PipeStream::connect()
     }
 
     int pipe_size = -1;
-#if !defined(MACOS) && !defined(FREEBSD)
+#ifdef __linux__
     pipe_size = fcntl(fd, F_GETPIPE_SZ);
 #endif
     LOG(TRACE, LOG_TAG) << "Stream: " << name_ << ", connect to pipe: " << uri_.path << ", fd: " << fd << ", pipe size: " << pipe_size << "\n";
