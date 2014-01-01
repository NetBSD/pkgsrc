$NetBSD: patch-lib_irrlicht_source_Irrlicht_os.cpp,v 1.2 2014/01/01 02:46:49 ryoon Exp $

* Fix build on NetBSD and OpenBSD

--- lib/irrlicht/source/Irrlicht/os.cpp.orig	2013-12-31 07:04:37.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/os.cpp
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
