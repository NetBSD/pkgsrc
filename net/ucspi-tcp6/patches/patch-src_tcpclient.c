$NetBSD: patch-src_tcpclient.c,v 1.1 2019/08/19 22:05:39 schmonz Exp $

Apply upstream patch to fix incorrect behavior in tcpclient when an IPv4
address is given as the hostname.

--- src/tcpclient.c.orig	2019-07-19 17:32:34.000000000 +0000
+++ src/tcpclient.c
@@ -133,12 +133,10 @@ int main(int argc,char **argv)
 
   if (!*++argv) usage();
 
-
-  if (ipv4socket) {
-     if (ip4_scan(hostname,ipremote)) {
-       if (!stralloc_copyb(&addresses,(char *)V4mappedprefix,12)) nomem();
-       byte_copy(addresses.s + 12,4,ipremote);
-     }
+  if (ip4_scan(hostname,ipremote + 12)) {
+    if (!stralloc_copys(&addresses,"")) nomem();
+    byte_copy(addresses.s,12,V4mappedprefix);
+    byte_copy(addresses.s + 12,4,ipremote + 12);
   } else if (ip6_scan(hostname,ipremote))
      if (!stralloc_copyb(&addresses,ipremote,16)) nomem();
 
