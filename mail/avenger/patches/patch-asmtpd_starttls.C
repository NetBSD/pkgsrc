$NetBSD: patch-asmtpd_starttls.C,v 1.1 2019/12/18 12:39:09 joerg Exp $

--- asmtpd/starttls.C.orig	2019-12-13 12:08:22.007397245 +0000
+++ asmtpd/starttls.C
@@ -264,7 +264,7 @@ smtpd::received_starttls (strbuf r) cons
     return;
 
   r << "    (";
-  if (char *vers = SSL_get_cipher_version (ssl->get_ssl ()))
+  if (const char *vers = SSL_get_cipher_version (ssl->get_ssl ()))
     r << vers;
   else
     r << "SSL";
@@ -299,7 +299,7 @@ smtpd::env_starttls (vec<str> *envp) con
   envp->push_back (strbuf ("SSL_CIPHER_BITS=%d", cipher_bits));
   envp->push_back (strbuf ("SSL_ALG_BITS=%d", alg_bits));
 
-  if (char *vers = SSL_get_cipher_version (ssl->get_ssl ()))
+  if (const char *vers = SSL_get_cipher_version (ssl->get_ssl ()))
       envp->push_back (strbuf () << "SSL_VERSION=" << vers);
 
   if (ssl->issuer)
