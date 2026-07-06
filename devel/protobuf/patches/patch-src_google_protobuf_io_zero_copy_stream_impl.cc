$NetBSD: patch-src_google_protobuf_io_zero_copy_stream_impl.cc,v 1.1 2026/07/06 14:03:04 sborrill Exp $

Defining _POSIX_C_SOURCE breaks the build with pkgsrc gcc10.
It is only used to bring in posix_close which is not available
on most platforms, so make Linux-only:
https://www.gnu.org/software/gnulib/manual/html_node/posix_005fclose.html

--- src/google/protobuf/io/zero_copy_stream_impl.cc.orig	2026-07-02 16:27:56.892638162 +0000
+++ src/google/protobuf/io/zero_copy_stream_impl.cc	2026-07-03 14:15:11.882956200 +0000
@@ -10,7 +10,9 @@
 //  Sanjay Ghemawat, Jeff Dean, and others.
 
 // We request posix_close if available. See the comment on "robust_close".
+#ifdef __linux__
 #define _POSIX_C_SOURCE 202405L
+#endif
 
 #ifndef _MSC_VER
 #include <fcntl.h>
