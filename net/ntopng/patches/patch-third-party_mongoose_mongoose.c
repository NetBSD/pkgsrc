$NetBSD: patch-third-party_mongoose_mongoose.c,v 1.3 2018/10/18 16:25:40 adam Exp $

Do not redefine SOCKET.

--- third-party/mongoose/mongoose.c.orig	2018-10-18 15:46:36.000000000 +0000
+++ third-party/mongoose/mongoose.c
@@ -270,7 +270,9 @@ struct pollfd {
 #endif
 
 //#define INT64_FMT PRId64
+#ifndef SOCKET
 typedef int SOCKET;
+#endif
 #define WINCDECL
 
 #endif // End of Windows and UNIX specific includes
