$NetBSD: patch-source_Irrlicht_os.cpp,v 1.1 2019/06/30 22:13:14 nia Exp $

Support NetBSD.

--- source/Irrlicht/os.cpp.orig	Sun Jan  6 13:20:50 2013
+++ source/Irrlicht/os.cpp
@@ -22,10 +22,14 @@
 	#include <libkern/OSByteOrder.h>
 	#define bswap_16(X) OSReadSwapInt16(&X,0)
 	#define bswap_32(X) OSReadSwapInt32(&X,0)
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 	#include <sys/endian.h>
 	#define bswap_16(X) bswap16(X)
 	#define bswap_32(X) bswap32(X)
+#elif defined(__OpenBSD__)
+	#include <sys/endian.h>
+	#define bswap_16(x) letoh16(x)
+	#define bswap_32(x) letoh32(x)
 #elif !defined(_IRR_SOLARIS_PLATFORM_) && !defined(__PPC__) && !defined(_IRR_WINDOWS_API_)
 	#include <byteswap.h>
 #else
