$NetBSD: patch-src_Cedar_VLanUnix.c,v 1.1 2024/03/07 11:48:35 hauke Exp $

Include netinet/if_ether.h for NetBSD

Conditionalize SIOCSIFLLADDR use

Special-case NetBSD's ifr buffer name

--- src/Cedar/VLanUnix.c.orig	2023-12-03 16:16:54.000000000 +0000
+++ src/Cedar/VLanUnix.c
@@ -29,7 +29,7 @@
 #include <net/if.h>
 #include <sys/ioctl.h>
 
-#if defined(UNIX_OPENBSD) || defined(UNIX_SOLARIS)
+#if defined(UNIX_NETBSD) || defined(UNIX_OPENBSD) || defined(UNIX_SOLARIS)
 #include <netinet/if_ether.h>
 #else
 #include <net/ethernet.h>
@@ -463,6 +463,7 @@ int UnixCreateTapDeviceEx(char *name, ch
 		StrCpy(tap_name, sizeof(tap_name), ifr.ifr_name);
 #endif	// SIOCSIFNAME
 
+#ifdef 	SIOCSIFLLADDR	
 		// Set the MAC address
 		if (mac_address != NULL)
 		{
@@ -473,14 +474,20 @@ int UnixCreateTapDeviceEx(char *name, ch
 			Copy(&ifr.ifr_addr.sa_data, mac_address, ETHER_ADDR_LEN);
 			ioctl(s, SIOCSIFLLADDR, &ifr);
 		}
+#endif
 
-		// Set interface description
+// Set interface description
 #ifdef	SIOCSIFDESCR
 		{
 			char desc[] = CEDAR_PRODUCT_STR " Virtual Network Adapter";
 
+#ifdef UNIX_NETBSD
+			ifr.ifr_ifru.ifru_b.b_buf = desc;
+			ifr.ifr_ifru.ifru_b.b_buflen = StrLen(desc) + 1;
+#else			
 			ifr.ifr_buffer.buffer = desc;
 			ifr.ifr_buffer.length = StrLen(desc) + 1;
+#endif
 			ioctl(s, SIOCSIFDESCR, &ifr);
 		}
 #endif
