$NetBSD: patch-src_cert_cvc_cvc__req.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_req.cpp.orig	2013-04-30 23:48:36.000000000 +0000
+++ src/cert/cvc/cvc_req.cpp
@@ -50,7 +50,7 @@ void EAC1_1_Req::force_decode()
 #endif
    }
 
-EAC1_1_Req::EAC1_1_Req(std::tr1::shared_ptr<DataSource> in)
+EAC1_1_Req::EAC1_1_Req(shared_ptr<DataSource> in)
    {
    init(in);
    self_signed = true;
@@ -59,7 +59,7 @@ EAC1_1_Req::EAC1_1_Req(std::tr1::shared_
 
 EAC1_1_Req::EAC1_1_Req(const std::string& in)
    {
-   std::tr1::shared_ptr<DataSource> stream(new DataSource_Stream(in, true));
+   shared_ptr<DataSource> stream(new DataSource_Stream(in, true));
    init(stream);
    self_signed = true;
    do_decode();
