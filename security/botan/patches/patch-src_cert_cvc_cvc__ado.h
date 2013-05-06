$NetBSD: patch-src_cert_cvc_cvc__ado.h,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_ado.h.orig	2013-04-30 23:02:27.000000000 +0000
+++ src/cert/cvc/cvc_ado.h
@@ -39,7 +39,7 @@ class BOTAN_DLL EAC1_1_ADO : public EAC1
       * Construct a CVC ADO request from a data source
       * @param source the data source
       */
-      EAC1_1_ADO(std::tr1::shared_ptr<DataSource> source);
+      EAC1_1_ADO(shared_ptr<DataSource> source);
 
       /**
       * Create a signed CVC ADO request from to be signed (TBS) data
