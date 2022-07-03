$NetBSD: patch-server_streamreader_pipe__stream.cpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Add NetBSD support.

--- server/streamreader/pipe_stream.cpp.orig	2021-12-22 17:40:36.000000000 +0000
+++ server/streamreader/pipe_stream.cpp
@@ -59,7 +59,7 @@ void PipeStream::do_connect()
 {
     int fd = open(uri_.path.c_str(), O_RDONLY | O_NONBLOCK);
     int pipe_size = -1;
-#if !defined(MACOS) && !defined(FREEBSD)
+#ifdef __linux__
     pipe_size = fcntl(fd, F_GETPIPE_SZ);
 #endif
     LOG(TRACE, LOG_TAG) << "Stream: " << name_ << ", connect to pipe: " << uri_.path << ", fd: " << fd << ", pipe size: " << pipe_size << "\n";
