$NetBSD: patch-unix-socket.cxx,v 1.1 2011/12/04 21:59:37 marino Exp $

--- src/ptlib/unix/socket.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/socket.cxx
@@ -55,7 +55,7 @@
 #define  ifr_macaddr         ifr_hwaddr.sa_data
 #endif
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_SOLARIS) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_IRIX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_SOLARIS) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_IRIX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
 #define ifr_netmask ifr_addr
 
 #include <net/if_dl.h>
@@ -76,7 +76,7 @@
 
 #endif
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_QNX) || defined(P_DRAGONFLY)
 #include <sys/sysctl.h>
 #endif
 
@@ -90,7 +90,7 @@
 #include <be/bone/sys/sockio.h> // for SIOCGI*
 #endif
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
 // Define _SIZEOF_IFREQ for platforms (eg OpenBSD) which do not have it.
 #ifndef _SIZEOF_ADDR_IFREQ
 #define _SIZEOF_ADDR_IFREQ(ifr) \
@@ -515,7 +515,7 @@ PBoolean PIPSocket::IsLocalHost(const PS
         }
       }
       
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
       // move the ifName pointer along to the next ifreq entry
       ifName = (struct ifreq *)((char *)ifName + _SIZEOF_ADDR_IFREQ(*ifName));
 #elif !defined(P_NETBSD)
@@ -1069,7 +1069,7 @@ PBoolean PIPSocket::GetRouteTable(RouteT
   return nTime > 0;
 }
 
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_QNX) 
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_QNX) || defined(P_DRAGONFLY)
 
 PBoolean process_rtentry(struct rt_msghdr *rtm, char *ptr, unsigned long *p_net_addr,
                      unsigned long *p_net_mask, unsigned long *p_dest_addr, int *p_metric);
@@ -1693,7 +1693,7 @@ PBoolean PIPSocket::GetInterfaceTable(In
         }
       }
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
       // move the ifName pointer along to the next ifreq entry
       ifName = (struct ifreq *)((char *)ifName + _SIZEOF_ADDR_IFREQ(*ifName));
 #elif !defined(P_NETBSD)
