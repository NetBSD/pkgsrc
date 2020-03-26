$NetBSD: patch-device_common_misc.cpp,v 1.1 2020/03/26 02:28:58 joerg Exp $

--- device/common/misc.cpp.orig	2020-03-25 13:09:41.814154865 +0000
+++ device/common/misc.cpp
@@ -198,7 +198,7 @@ const char *Device::cidrToNetmask(const 
 unsigned int Device::ipAddressToNum(const char *address)
 {
 	// Variables...
-	char *addressPointer = 0;
+	const char *addressPointer = 0;
 	unsigned int returnAddress = 0;
 	int tempInt = 0; 
 
