$NetBSD: patch-etc_afpd_afp_mdns.c,v 1.1 2014/06/11 11:03:56 hauke Exp $

--- etc/afpd/afp_mdns.c.orig	2012-09-10 09:34:52.000000000 +0000
+++ etc/afpd/afp_mdns.c
@@ -167,7 +167,7 @@ static void register_stuff(const AFPConf
 
     // Allocate the memory to store our service refs
     svc_refs = calloc(svc_ref_count, sizeof(DNSServiceRef));
-    assert(svc_ref);
+    assert(svc_refs);
     svc_ref_count = 0;
 
     /* AFP server */
