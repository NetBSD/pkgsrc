$NetBSD: patch-async_dnsparse.C,v 1.1 2017/09/09 19:45:46 dholland Exp $

Fix up illegal pointer aliasing.

--- async/dnsparse.C~	2009-02-12 13:20:42.000000000 +0000
+++ async/dnsparse.C
@@ -757,10 +757,15 @@ printaddrs (const char *msg, ptr<hostent
 void
 printhints (addrhint **hpp)
 {
-  for (; *hpp; hpp++)
-    if ((*hpp)->h_addrtype == AF_INET)
+  in_addr ia;
+
+  for (; *hpp; hpp++) {
+    if ((*hpp)->h_addrtype == AF_INET) {
+      memcpy(&ia, (*hpp)->h_address, sizeof(ia));
       printf ("    (hint:  %s %s)\n", (*hpp)->h_name,
-	      inet_ntoa (*(in_addr *) (*hpp)->h_address));
+	      inet_ntoa (ia));
+    }
+  }
 }
 
 void
