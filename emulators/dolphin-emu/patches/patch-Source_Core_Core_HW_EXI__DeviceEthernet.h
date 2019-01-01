$NetBSD: patch-Source_Core_Core_HW_EXI__DeviceEthernet.h,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/Core/HW/EXI_DeviceEthernet.h.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Core/HW/EXI_DeviceEthernet.h
@@ -331,11 +331,11 @@ public:
 	OVERLAPPED mWriteOverlapped;
 	std::vector<u8> mWriteBuffer;
 	bool mWritePending;
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 	int fd;
 #endif
 
-#if defined(WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 	std::thread readThread;
 	Common::Flag readEnabled;
 	Common::Flag readThreadShutdown;
