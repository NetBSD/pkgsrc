$NetBSD: patch-include_violite.h,v 1.1.2.2 2015/07/19 17:58:43 tron Exp $

Backport from upstream to mysql 5.6.x:
https://github.com/mysql/mysql-server/commit/866b988a76e8e7e217017a7883a52a12ec5024b9

From 866b988a76e8e7e217017a7883a52a12ec5024b9 Mon Sep 17 00:00:00 2001
From: Marek Szymczak <marek.szymczak@oracle.com>
Date: Thu, 9 Oct 2014 16:39:43 +0200
Subject: [PATCH] Bug#18367167 DH KEY LENGTH OF 1024 BITS TO MEET MINIMUM REQ
 OF FIPS 140-2

Perfect Forward Secrecy (PFS) requires Diffie-Hellman (DH) parameters to be set.
 Current implementation uses DH key of 512 bit.

--- include/violite.h.orig	2015-05-05 13:05:53.000000000 +0200
+++ include/violite.h	2015-07-14 05:20:18.000000000 +0200
@@ -146,9 +146,10 @@
 enum enum_ssl_init_error
 {
   SSL_INITERR_NOERROR= 0, SSL_INITERR_CERT, SSL_INITERR_KEY, 
   SSL_INITERR_NOMATCH, SSL_INITERR_BAD_PATHS, SSL_INITERR_CIPHERS, 
-  SSL_INITERR_MEMFAIL, SSL_INITERR_LASTERR
+  SSL_INITERR_MEMFAIL, SSL_INITERR_NO_USABLE_CTX, SSL_INITERR_DHFAIL,
+  SSL_INITERR_LASTERR
 };
 const char* sslGetErrString(enum enum_ssl_init_error err);
 
 struct st_VioSSLFd
