$NetBSD: patch-src_crlfetch.c,v 1.1 2015/12/29 23:18:50 bsiegert Exp $

--- src/crlfetch.c.orig	2009-08-07 14:09:47.000000000 +0000
+++ src/crlfetch.c
@@ -389,7 +389,7 @@ fetch_next_ksba_cert (cert_fetch_context
 void
 end_cert_fetch (cert_fetch_context_t context)
 {
-  return end_cert_fetch_ldap (context);
+  end_cert_fetch_ldap (context);
 }
 
 
