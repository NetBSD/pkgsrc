$NetBSD: patch-src_ssl_polyorb-ssl.ads,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Fix old library usage

--- src/ssl/polyorb-ssl.ads.orig	2024-08-23 19:03:44.000000000 +0300
+++ src/ssl/polyorb-ssl.ads
@@ -39,6 +39,7 @@
 
 package PolyORB.SSL is
 
+   type INIT_SETTINGS_ACCESS is private;
    type SSL_Context_Type is private;
 
    type SSL_Socket_Type is private;
@@ -162,6 +163,9 @@
 
 private
 
+   type OPENSSL_INIT_SETTINGS is null record;
+   pragma Convention (C, OPENSSL_INIT_SETTINGS);
+   type INIT_SETTINGS_ACCESS is access all OPENSSL_INIT_SETTINGS;
    type Context_Record is null record;
    pragma Convention (C, Context_Record);
 
