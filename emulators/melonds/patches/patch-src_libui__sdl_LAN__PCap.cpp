$NetBSD: patch-src_libui__sdl_LAN__PCap.cpp,v 1.1 2019/09/13 10:12:07 nia Exp $

Support non-Linux.

--- src/libui_sdl/LAN_PCap.cpp.orig	2019-06-25 17:29:21.000000000 +0000
+++ src/libui_sdl/LAN_PCap.cpp
@@ -33,8 +33,10 @@
 	#include <sys/types.h>
 	#include <ifaddrs.h>
 	#include <netinet/in.h>
+#ifdef __linux__
 	#include <linux/if_packet.h>
 #endif
+#endif
 
 
 // welp
@@ -270,6 +272,7 @@ bool Init(bool open_adapter)
                 struct sockaddr_in* sa = (sockaddr_in*)curaddr->ifa_addr;
                 memcpy(adata->IP_v4, &sa->sin_addr, 4);
             }
+#ifdef AF_PACKET
             else if (af == AF_PACKET)
             {
                 struct sockaddr_ll* sa = (sockaddr_ll*)curaddr->ifa_addr;
@@ -278,6 +281,7 @@ bool Init(bool open_adapter)
                 else
                     memcpy(adata->MAC, sa->sll_addr, 6);
             }
+#endif
             
             curaddr = curaddr->ifa_next;
         }
