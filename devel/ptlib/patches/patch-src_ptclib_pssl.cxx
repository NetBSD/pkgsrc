$NetBSD: patch-src_ptclib_pssl.cxx,v 1.1 2016/07/16 03:23:50 markd Exp $

--- src/ptclib/pssl.cxx.orig	2012-08-23 02:12:41.000000000 +0000
+++ src/ptclib/pssl.cxx
@@ -805,12 +805,17 @@ void PSSLContext::Construct(Method metho
   SSL_METHOD * meth;
 
   switch (method) {
+#ifndef OPENSSL_NO_SSL3
     case SSLv3:
       meth = SSLv3_method();
       break;
+#endif
     case TLSv1:
       meth = TLSv1_method(); 
       break;
+#ifdef OPENSSL_NO_SSL3
+    case SSLv3:
+#endif
     case SSLv23:
     default:
       meth = SSLv23_method();
