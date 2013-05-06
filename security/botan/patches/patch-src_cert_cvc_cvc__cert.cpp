$NetBSD: patch-src_cert_cvc_cvc__cert.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_cert.cpp.orig	2013-04-30 23:03:08.000000000 +0000
+++ src/cert/cvc/cvc_cert.cpp
@@ -78,7 +78,7 @@ void EAC1_1_CVC::force_decode()
 /*
 * CVC Certificate Constructor
 */
-EAC1_1_CVC::EAC1_1_CVC(std::tr1::shared_ptr<DataSource>& in)
+EAC1_1_CVC::EAC1_1_CVC(shared_ptr<DataSource>& in)
    {
    init(in);
    self_signed = false;
@@ -87,7 +87,7 @@ EAC1_1_CVC::EAC1_1_CVC(std::tr1::shared_
 
 EAC1_1_CVC::EAC1_1_CVC(const std::string& in)
    {
-   std::tr1::shared_ptr<DataSource> stream(new DataSource_Stream(in, true));
+   shared_ptr<DataSource> stream(new DataSource_Stream(in, true));
    init(stream);
    self_signed = false;
    do_decode();
