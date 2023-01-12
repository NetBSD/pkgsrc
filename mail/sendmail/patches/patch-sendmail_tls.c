$NetBSD: patch-sendmail_tls.c,v 1.1 2023/01/12 11:09:34 markd Exp $

Support openssl3

--- sendmail/tls.c.orig	2020-06-02 09:41:43.000000000 +0000
+++ sendmail/tls.c
@@ -29,7 +29,13 @@ SM_RCSID("@(#)$Id: tls.c,v 8.127 2013-11
 # ERROR: OpenSSL version OPENSSL_VERSION_NUMBER is unsupported.
 # endif
 
-# if OPENSSL_VERSION_NUMBER >= 0x10100000L && OPENSSL_VERSION_NUMBER < 0x20000000L
+/*
+ **  *SSL version numbers:
+ **  OpenSSL 0.9 - 1.1 (so far), 3.0 (in alpha)
+ **  LibreSSL 2.0 (0x20000000L - part of "These will never change")
+ */
+
+# if (OPENSSL_VERSION_NUMBER >= 0x10100000L && OPENSSL_VERSION_NUMBER < 0x20000000L) || OPENSSL_VERSION_NUMBER >= 0x30000000L
 #  define MTA_HAVE_DH_set0_pqg 1
 #  define MTA_HAVE_DSA_GENERATE_EX	1
 
