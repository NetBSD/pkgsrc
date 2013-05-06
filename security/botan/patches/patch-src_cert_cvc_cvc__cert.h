$NetBSD: patch-src_cert_cvc_cvc__cert.h,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_cert.h.orig	2013-04-30 23:03:11.000000000 +0000
+++ src/cert/cvc/cvc_cert.h
@@ -59,7 +59,7 @@ class BOTAN_DLL EAC1_1_CVC : public EAC1
        * Construct a CVC from a data source
        * @param source the data source
        */
-       EAC1_1_CVC(std::tr1::shared_ptr<DataSource>& source);
+       EAC1_1_CVC(shared_ptr<DataSource>& source);
 
        /**
        * Construct a CVC from a file
