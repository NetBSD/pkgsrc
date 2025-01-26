$NetBSD: patch-torch_csrc_distributed_c10d_ProcessGroupGloo.cpp,v 1.2 2025/01/26 12:33:03 wiz Exp $

* Support NetBSD.

--- torch/csrc/distributed/c10d/ProcessGroupGloo.cpp.orig	2025-01-21 17:59:06.880466509 +0000
+++ torch/csrc/distributed/c10d/ProcessGroupGloo.cpp
@@ -16,6 +16,10 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <unistd.h>
+#if !defined(HOST_NAME_MAX)
+#include <limits.h>
+#define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
+#endif
 #endif
 #include <sys/types.h>
 
@@ -693,7 +697,7 @@ std::shared_ptr<::gloo::transport::Devic
   return ::c10d::GlooDeviceFactory::makeDeviceForHostname(hostname);
 }
 
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__linux__) || defined(_WIN32) || defined(__NetBSD__)
 std::shared_ptr<::gloo::transport::Device> ProcessGroupGloo::
     createDefaultDevice() {
   // Use the hostname to resolve the network address to
