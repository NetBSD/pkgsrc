$NetBSD: patch-addrs_ioctl.c,v 1.1 2017/12/11 10:44:17 manu Exp $

Enable BSD features for NetBSD  
From <Jean-Jacques.Puig@espci.fr>

--- addrs_ioctl.c
+++ addrs_ioctl.c
@@ -18,7 +18,7 @@
 #include <net/if.h>
 #include <netinet/in.h>
 
-#if defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__ \
+#if defined __NetBSD__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__ \
       || ( defined __GLIBC__ && ! defined __linux__ )
 #include <sys/param.h>
 #include <sys/sysctl.h>
@@ -80,7 +80,7 @@ get_addrs_ioctl(char *interface, u_int8_t if_hw_addr[], struct in_addr *if_ip_ad
     got_hw_addr = 1;
   }
 #else
-#if defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__ \
+#if defined __NetBSD__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__ \
       || ( defined __GLIBC__ && ! defined __linux__ )
   {
     int sysctlparam[6] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST, 0};
