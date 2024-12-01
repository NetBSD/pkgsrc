$NetBSD: patch-dep_RtspServer_src_net_Socket.h,v 1.1 2024/12/01 13:49:47 gdt Exp $

Extend BSDish OS detection to NetBSD.

Not yet filed upstream.

--- dep/RtspServer/src/net/Socket.h.orig	2024-01-14 21:10:13.216456825 +0000
+++ dep/RtspServer/src/net/Socket.h
@@ -4,7 +4,7 @@
 #ifndef XOP_SOCKET_H
 #define XOP_SOCKET_H
 
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>         
 #include <sys/socket.h>
 #include <sys/ioctl.h>
@@ -17,7 +17,7 @@
 #include <net/ethernet.h>   
 #endif
 
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <net/route.h>  
 #include <netdb.h>
 #include <net/if.h>
