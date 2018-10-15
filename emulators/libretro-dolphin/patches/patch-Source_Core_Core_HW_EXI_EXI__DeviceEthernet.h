$NetBSD: patch-Source_Core_Core_HW_EXI_EXI__DeviceEthernet.h,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Core/HW/EXI/EXI_DeviceEthernet.h.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Core/HW/EXI/EXI_DeviceEthernet.h
@@ -316,12 +316,13 @@ private:
   OVERLAPPED mWriteOverlapped = {};
   std::vector<u8> mWriteBuffer;
   bool mWritePending = false;
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || \
+      defined(__OpenBSD__)
   int fd = -1;
 #endif
 
-#if defined(_WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||          \
-    defined(__OpenBSD__)
+#if defined(_WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
   std::thread readThread;
   Common::Flag readEnabled;
   Common::Flag readThreadShutdown;
