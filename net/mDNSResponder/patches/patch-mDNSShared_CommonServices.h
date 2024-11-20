$NetBSD: patch-mDNSShared_CommonServices.h,v 1.1 2024/11/20 17:56:21 hauke Exp $

Cater to various *BSDs

--- mDNSShared/CommonServices.h.orig	2024-09-24 20:38:46.000000000 +0000
+++ mDNSShared/CommonServices.h
@@ -54,6 +54,16 @@ extern "C" {
     #endif
 #endif
 
+// NetBSD
+
+#if ( !defined( TARGET_OS_NETBSD ) )
+    #if ( defined( __NetBSD__ ) )
+        #define TARGET_OS_NETBSD       1
+    #else
+        #define TARGET_OS_NETBSD       0
+    #endif
+#endif
+
 // FreeBSD
 
 #if ( !defined( TARGET_OS_FREEBSD ) )
@@ -64,6 +74,16 @@ extern "C" {
     #endif
 #endif
 
+// DragonFly
+
+#if ( !defined( TARGET_OS_DRAGONFLY ) )
+    #if ( defined( __DragonFly__ ) )
+        #define TARGET_OS_DRAGONFLY       1
+    #else
+        #define TARGET_OS_DRAGONFLY       0
+    #endif
+#endif
+
 // Linux
 
 #if ( !defined( TARGET_OS_LINUX ) )
@@ -84,6 +104,16 @@ extern "C" {
     #endif
 #endif
 
+// OpenBSD
+
+#if ( !defined( TARGET_OS_OPENBSD ) )
+    #if ( defined( __OpenBSD__ ) )
+        #define TARGET_OS_OPENBSD       1
+    #else
+        #define TARGET_OS_OPENBSD       0
+    #endif
+#endif
+
 // Palm
 
 #if ( !defined( TARGET_OS_PALM ) )
@@ -177,6 +207,22 @@ extern "C" {
     #include    <libkern/OSTypes.h>
     #include    <sys/types.h>
 
+#elif ( TARGET_OS_NETBSD )
+
+// NetBSD
+    #include    <stdint.h>
+    #include    <pthread.h>
+    #include    <netinet/in.h>
+    #include    <arpa/inet.h>
+    #include    <sys/socket.h>
+
+    #if ( defined( BYTE_ORDER ) && defined( LITTLE_ENDIAN ) && ( BYTE_ORDER == LITTLE_ENDIAN ) )
+        #define TARGET_RT_LITTLE_ENDIAN     1
+    #endif
+    #if ( defined( BYTE_ORDER ) && defined( BIG_ENDIAN ) && ( BYTE_ORDER == BIG_ENDIAN ) )
+        #define TARGET_RT_BIG_ENDIAN        1
+    #endif
+
 #elif ( TARGET_OS_FREEBSD )
 
 // FreeBSD
@@ -186,6 +232,15 @@ extern "C" {
     #include    <arpa/inet.h>
     #include    <sys/socket.h>
 
+#elif ( TARGET_OS_DRAGONFLY )
+
+// DragonFly BSD
+    #include    <stdint.h>
+    #include    <pthread.h>
+    #include    <netinet/in.h>
+    #include    <arpa/inet.h>
+    #include    <sys/socket.h>
+
 #elif ( TARGET_OS_LINUX )
 
 // Linux
@@ -209,6 +264,15 @@ extern "C" {
         #define TARGET_RT_BIG_ENDIAN        1
     #endif
 
+#elif ( TARGET_OS_OPENBSD )
+
+// OpenBSD
+    #include    <stdint.h>
+    #include    <pthread.h>
+    #include    <netinet/in.h>
+    #include    <arpa/inet.h>
+    #include    <sys/socket.h>
+
 #elif ( TARGET_OS_PALM )
 
 // Palm (no special includes yet).
@@ -447,7 +511,7 @@ typedef int socklen_t;
 // - Mac OS X when not building with BSD headers
 // - Windows
 
-#if ( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_FREEBSD && !TARGET_OS_LINUX && !TARGET_OS_MAC)
+#if ( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_NETBSD && !TARGET_OS_FREEBSD && !TARGET_OS_DRAGONFLY && !TARGET_OS_LINUX && !TARGET_OS_OPENBSD && !TARGET_OS_MAC)
 typedef int ssize_t;
 #endif
 
