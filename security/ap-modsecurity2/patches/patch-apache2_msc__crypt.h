$NetBSD: patch-apache2_msc__crypt.h,v 1.1 2016/12/24 10:16:50 joerg Exp $

Avoid conflict with NetBSD's hmac(3).

--- apache2/msc_crypt.h.orig	2016-12-24 09:55:12.580528917 +0000
+++ apache2/msc_crypt.h
@@ -27,7 +27,7 @@
 #define INT32_MAX      (2147483647)
 #endif
 
-char DSOLOCAL *hmac(modsec_rec *msr, const char *key, int key_len,
+char DSOLOCAL *mschmac(modsec_rec *msr, const char *key, int key_len,
                      unsigned char *msg, int msglen);
 char DSOLOCAL *do_hash_link(modsec_rec *msr, char *link,
                       int type);
