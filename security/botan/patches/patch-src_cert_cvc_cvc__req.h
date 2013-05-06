$NetBSD: patch-src_cert_cvc_cvc__req.h,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_req.h.orig	2013-04-30 23:01:50.000000000 +0000
+++ src/cert/cvc/cvc_req.h
@@ -36,7 +36,7 @@ class BOTAN_DLL EAC1_1_Req : public EAC1
       * Construct a CVC request from a data source.
       * @param source the data source
       */
-      EAC1_1_Req(std::tr1::shared_ptr<DataSource> source);
+      EAC1_1_Req(shared_ptr<DataSource> source);
 
       /**
       * Construct a CVC request from a DER encoded CVC reqeust file.
