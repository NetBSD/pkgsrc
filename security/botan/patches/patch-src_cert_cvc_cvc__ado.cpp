$NetBSD: patch-src_cert_cvc_cvc__ado.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_ado.cpp.orig	2013-04-30 23:02:37.000000000 +0000
+++ src/cert/cvc/cvc_ado.cpp
@@ -12,7 +12,7 @@
 
 namespace Botan {
 
-EAC1_1_ADO::EAC1_1_ADO(std::tr1::shared_ptr<DataSource> in)
+EAC1_1_ADO::EAC1_1_ADO(shared_ptr<DataSource> in)
    {
    init(in);
    do_decode();
@@ -20,7 +20,7 @@ EAC1_1_ADO::EAC1_1_ADO(std::tr1::shared_
 
 EAC1_1_ADO::EAC1_1_ADO(const std::string& in)
    {
-   std::tr1::shared_ptr<DataSource> stream(new DataSource_Stream(in, true));
+   shared_ptr<DataSource> stream(new DataSource_Stream(in, true));
    init(stream);
    do_decode();
    }
@@ -41,7 +41,7 @@ void EAC1_1_ADO::force_decode()
       .end_cons()
       .get_contents();
 
-   std::tr1::shared_ptr<DataSource> req_source(new DataSource_Memory(req_bits));
+   shared_ptr<DataSource> req_source(new DataSource_Memory(req_bits));
    m_req = EAC1_1_Req(req_source);
    sig_algo = m_req.sig_algo;
    }
