$NetBSD: patch-Source_FreeImage_PluginDDS.cpp,v 1.1 2022/06/26 10:49:54 he Exp $

Catch-up for big-endian hosts.

--- Source/FreeImage/PluginDDS.cpp.orig	2018-07-31 15:04:58.000000000 +0000
+++ Source/FreeImage/PluginDDS.cpp
@@ -356,14 +356,14 @@ SwapHeader(DDSHEADER *header) {
 	for(int i=0; i<11; i++) {
 		SwapLong(&header->surfaceDesc.dwReserved1[i]);
 	}
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwSize);
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwFlags);
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwFourCC);
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwRGBBitCount);
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwRBitMask);
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwGBitMask);
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwBBitMask);
-	SwapLong(&header->surfaceDesc.ddpfPixelFormat.dwRGBAlphaBitMask);
+	SwapLong(&header->surfaceDesc.ddspf.dwSize);
+	SwapLong(&header->surfaceDesc.ddspf.dwFlags);
+	SwapLong(&header->surfaceDesc.ddspf.dwFourCC);
+	SwapLong(&header->surfaceDesc.ddspf.dwRGBBitCount);
+	SwapLong(&header->surfaceDesc.ddspf.dwRBitMask);
+	SwapLong(&header->surfaceDesc.ddspf.dwGBitMask);
+	SwapLong(&header->surfaceDesc.ddspf.dwBBitMask);
+	SwapLong(&header->surfaceDesc.ddspf.dwRGBAlphaBitMask);
 	SwapLong(&header->surfaceDesc.ddsCaps.dwCaps1);
 	SwapLong(&header->surfaceDesc.ddsCaps.dwCaps2);
 	SwapLong(&header->surfaceDesc.ddsCaps.dwReserved[0]);
