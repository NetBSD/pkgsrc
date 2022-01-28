$NetBSD: patch-gio_gcredentialsprivate.h,v 1.5 2022/01/28 21:34:51 schmonz Exp $

NetBSD has G_CREDENTIALS_SOCKET_GET_CREDENTIALS_SUPPORTED.
Sufficiently old Darwin (e.g., Snow Leopard) needs SOL_LOCAL defined.

--- gio/gcredentialsprivate.h.orig	2021-12-03 10:02:55.000000000 +0000
+++ gio/gcredentialsprivate.h
@@ -134,7 +134,7 @@
 #define G_CREDENTIALS_USE_NETBSD_UNPCBID 1
 #define G_CREDENTIALS_NATIVE_TYPE G_CREDENTIALS_TYPE_NETBSD_UNPCBID
 #define G_CREDENTIALS_NATIVE_SIZE (sizeof (struct unpcbid))
-/* #undef G_CREDENTIALS_UNIX_CREDENTIALS_MESSAGE_SUPPORTED */
+#define G_CREDENTIALS_SOCKET_GET_CREDENTIALS_SUPPORTED 1
 #define G_CREDENTIALS_SPOOFING_SUPPORTED 1
 #define G_CREDENTIALS_HAS_PID 1
 
@@ -159,6 +159,9 @@
 
 #elif defined(__APPLE__)
 #include <sys/ucred.h>
+#ifndef SOL_LOCAL
+#define SOL_LOCAL 0
+#endif
 #define G_CREDENTIALS_SUPPORTED 1
 #define G_CREDENTIALS_USE_APPLE_XUCRED 1
 #define G_CREDENTIALS_NATIVE_TYPE G_CREDENTIALS_TYPE_APPLE_XUCRED
