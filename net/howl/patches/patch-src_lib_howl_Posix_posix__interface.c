$NetBSD: patch-src_lib_howl_Posix_posix__interface.c,v 1.1 2012/02/16 19:30:30 hans Exp $

--- src/lib/howl/Posix/posix_interface.c.orig	2005-05-19 23:39:27.000000000 +0200
+++ src/lib/howl/Posix/posix_interface.c	2012-01-17 00:31:41.251184693 +0100
@@ -367,7 +367,7 @@ sw_posix_network_interface_init_from_nam
 	sw_debug(SW_LOG_VERBOSE, "got ip address: %s\n", tmpname);
 
 	/* mac address */
-#if defined(SIOCGIFHWADDR)
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 	res = ioctl(sock, SIOCGIFHWADDR, &ifr);
 	err = sw_translate_error(res == 0, errno);
 	sw_check_okay_log(err, exit);
@@ -436,7 +436,7 @@ sw_posix_network_interface_init_from_ifr
 	sw_ipv4_address_init_from_saddr(&(nif->m_super.m_netmask), ((struct sockaddr_in*) &ifr->ifr_addr )->sin_addr.s_addr );
 #endif
 
-#if defined(SIOCGIFHWADDR)
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 	/* mac address */
 	res = ioctl(sock, SIOCGIFHWADDR, ifr);
 	err = sw_translate_error(res != -1, errno);
