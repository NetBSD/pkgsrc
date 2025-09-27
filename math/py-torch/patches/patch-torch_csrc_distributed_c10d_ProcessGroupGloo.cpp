$NetBSD: patch-torch_csrc_distributed_c10d_ProcessGroupGloo.cpp,v 1.3 2025/09/27 01:19:55 ryoon Exp $

* Support NetBSD.

--- torch/csrc/distributed/c10d/ProcessGroupGloo.cpp.orig	2025-08-06 17:08:06.000000000 +0000
+++ torch/csrc/distributed/c10d/ProcessGroupGloo.cpp
@@ -21,6 +21,10 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <unistd.h>
+#if !defined(HOST_NAME_MAX)
+#include <limits.h>
+#define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
+#endif
 #endif
 #include <sys/types.h>
 
@@ -491,7 +495,7 @@ std::shared_ptr<::gloo::transport::Devic
   return ::c10d::GlooDeviceFactory::makeDeviceForHostname(hostname, lazyInit);
 }
 
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__linux__) || defined(_WIN32) || defined(__NetBSD__)
 std::shared_ptr<::gloo::transport::Device> ProcessGroupGloo::
     createDefaultDevice(bool lazyInit) {
   // Use the hostname to resolve the network address to
