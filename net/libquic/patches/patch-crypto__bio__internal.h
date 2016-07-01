$NetBSD: patch-crypto__bio__internal.h,v 1.1 2016/07/01 20:32:35 agc Exp $

NetBSD portability patches

--- boringssl/crypto/bio/internal.h.orig	2015-12-30 15:55:50.000000000 -0800
+++ boringssl/crypto/bio/internal.h	2015-12-30 18:06:05.000000000 -0800
@@ -59,6 +59,8 @@
 
 #include <openssl/base.h>
 
+#include <netdb.h>
+
 #if !defined(OPENSSL_WINDOWS)
 #if defined(OPENSSL_PNACL)
 /* newlib uses u_short in socket.h without defining it. */
