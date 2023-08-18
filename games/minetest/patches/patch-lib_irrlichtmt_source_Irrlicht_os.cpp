$NetBSD: patch-lib_irrlichtmt_source_Irrlicht_os.cpp,v 1.1 2023/08/18 10:51:52 pin Exp $

Add NetBSD's endian functions

--- lib/irrlichtmt/source/Irrlicht/os.cpp.orig	2023-03-05 20:45:09.000000000 +0000
+++ lib/irrlichtmt/source/Irrlicht/os.cpp
@@ -33,6 +33,11 @@
 	#define bswap_16(X) letoh16(X)
 	#define bswap_32(X) letoh32(X)
 	#define bswap_64(X) letoh64(X)
+#elif defined(__NetBSD__)
+	#include <endian.h>
+	#define bswap_16(X) htole16(X)
+	#define bswap_32(X) htole32(X)
+	#define bswap_64(X) htole64(X)
 #elif !defined(_IRR_SOLARIS_PLATFORM_) && !defined(__PPC__) && !defined(_IRR_WINDOWS_API_)
 	#include <byteswap.h>
 #else
