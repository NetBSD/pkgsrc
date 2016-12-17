$NetBSD: patch-browser_mongoose.c,v 1.3 2016/12/17 12:55:29 rillig Exp $

__BSD_VISIBLE is needed on FreeBSD.
_XOPEN_SOURCE is not needed on sunos.

--- browser/mongoose.c.orig	2011-11-17 17:17:36.000000000 +0000
+++ browser/mongoose.c
@@ -21,7 +21,10 @@
 #if defined(_WIN32)
 #define _CRT_SECURE_NO_WARNINGS // Disable deprecation warning in VS2005
 #else
+#if !defined(__sun)
 #define _XOPEN_SOURCE 600 // For flockfile() on Linux
+#define __BSD_VISIBLE 1 // For PF_INET on FreeBSD
+#endif
 #define _LARGEFILE_SOURCE // Enable 64-bit file offsets
 #define __STDC_FORMAT_MACROS // <inttypes.h> wants this for C++
 #endif
@@ -213,6 +216,10 @@ typedef int SOCKET;
 
 #endif // End of Windows and UNIX specific includes
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#endif
+
 #include "mongoose.h"
 
 #define MONGOOSE_VERSION "3.0"
