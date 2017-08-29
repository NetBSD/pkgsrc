$NetBSD: patch-src_crlfetch.c,v 1.2 2017/08/29 11:56:04 wiz Exp $

Function is now void, do not use it as argument to return.

--- src/crlfetch.c.orig	2009-08-07 14:09:47.000000000 +0000
+++ src/crlfetch.c
@@ -389,7 +389,7 @@ fetch_next_ksba_cert (cert_fetch_context
 void
 end_cert_fetch (cert_fetch_context_t context)
 {
-  return end_cert_fetch_ldap (context);
+  end_cert_fetch_ldap (context);
 }
 
 
