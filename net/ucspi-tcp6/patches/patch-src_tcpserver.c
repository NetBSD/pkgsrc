$NetBSD: patch-src_tcpserver.c,v 1.1 2019/08/19 22:05:39 schmonz Exp $

Apply upstream patch to fix incorrect behavior in tcpserver when an IPv4
address is given as the hostname.

--- src/tcpserver.c.orig	2019-07-14 10:16:33.000000000 +0000
+++ src/tcpserver.c
@@ -137,8 +137,9 @@ void doit(int t)
 {
   uint32 netif;
   int j;
-
-  ipv4socket = ip6_isv4mapped(remoteip);
+ 
+  if (!ipv4socket) 
+    ipv4socket = ip6_isv4mapped(remoteip);
 
   if (socket_local(t,localip,&localport,&netif) == -1)
     logmsg(WHO,111,FATAL,"unable to get local address");
@@ -392,10 +393,11 @@ int main(int argc,char **argv)
 
   /* Name qualification */
 
-  if (ip4_scan(hostname,localip)) {
+  if (ip4_scan(hostname,localip + 12)) {
     if (!stralloc_copys(&addresses,"")) drop_nomem();
     byte_copy(addresses.s,12,V4mappedprefix);
-    byte_copy(addresses.s + 12,4,localip);
+    byte_copy(addresses.s + 12,4,localip + 12);
+    ipv4socket = 1;
   } else if (ip6_scan(hostname,localip))
     if (!stralloc_copyb(&addresses,localip,16)) drop_nomem();
 
@@ -403,10 +405,9 @@ int main(int argc,char **argv)
     if (!stralloc_copys(&tmp,hostname)) drop_nomem();
     if (!dns_ip6_qualify(&addresses,&fqdn,&tmp))
       logmsg(WHO,111,FATAL,B("temporarily unable to figure out IP address for: ",(char *)hostname));
-    if (addresses.len < 16)
-      logmsg(WHO,111,FATAL,B("no IP address for: ",(char *)hostname));
   }
-  byte_copy(localip,16,addresses.s);
+  if (addresses.len < 16)
+    logmsg(WHO,111,FATAL,B("no IP address for: ",(char *)hostname));
 
   s = socket_tcp();
   if (s == -1)
