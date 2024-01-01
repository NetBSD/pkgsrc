$NetBSD: patch-src_tools_singlejar_mapped__file__posix.inc,v 1.1 2024/01/01 12:01:00 ryoon Exp $

--- src/tools/singlejar/mapped_file_posix.inc.orig	2023-11-29 01:55:21.101251891 +0000
+++ src/tools/singlejar/mapped_file_posix.inc
@@ -26,7 +26,7 @@
 
 // The implementation is specific to 64-bit Linux / OS X / BSD.
 #if !((defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
-       defined(__OpenBSD__)) &&                                            \
+       defined(__OpenBSD__) || defined(__NetBSD__)) &&                                            \
       __SIZEOF_POINTER__ == 8)
 #error This code for 64 bit Unix.
 #endif
