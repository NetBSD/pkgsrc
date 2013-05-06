$NetBSD: patch-src_cert_cvc_cvc__ca.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_ca.cpp.orig	2013-04-30 23:02:49.000000000 +0000
+++ src/cert/cvc/cvc_ca.cpp
@@ -38,7 +38,7 @@ EAC1_1_CVC EAC1_1_CVC_CA::make_cert(std:
                               EAC1_1_CVC::build_cert_body(tbs),
                               rng);
 
-   std::tr1::shared_ptr<DataSource> source(new DataSource_Memory(signed_cert));
+   shared_ptr<DataSource> source(new DataSource_Memory(signed_cert));
 
    return EAC1_1_CVC(source);
    }
