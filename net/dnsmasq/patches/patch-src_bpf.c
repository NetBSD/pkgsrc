$NetBSD: patch-src_bpf.c,v 1.1 2013/04/04 12:38:59 jperkin Exp $

Pull in upstream fixes for interface enumeration.

--- src/bpf.c.orig	2012-12-03 14:05:59.000000000 +0000
+++ src/bpf.c
@@ -111,7 +111,7 @@ int iface_enumerate(int family, void *pa
 	{
 	  int iface_index = if_nametoindex(addrs->ifa_name);
 
-	  if (iface_index == 0)
+	  if (iface_index == 0 || !addrs->ifa_addr || !addrs->ifa_netmask)
 	    continue;
 
 	  if (family == AF_INET)
@@ -119,7 +119,10 @@ int iface_enumerate(int family, void *pa
 	      struct in_addr addr, netmask, broadcast;
 	      addr = ((struct sockaddr_in *) addrs->ifa_addr)->sin_addr;
 	      netmask = ((struct sockaddr_in *) addrs->ifa_netmask)->sin_addr;
-	      broadcast = ((struct sockaddr_in *) addrs->ifa_broadaddr)->sin_addr; 
+	      if (addrs->ifa_broadaddr)
+		broadcast = ((struct sockaddr_in *) addrs->ifa_broadaddr)->sin_addr; 
+	      else
+		broadcast.s_addr = 0;
 	      if (!((*callback)(addr, iface_index, netmask, broadcast, parm)))
 		goto err;
 	    }
