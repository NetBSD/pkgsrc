$NetBSD: patch-src_cert_cvc_cvc__self.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/cvc_self.cpp.orig	2013-04-30 23:02:54.000000000 +0000
+++ src/cert/cvc/cvc_self.cpp
@@ -131,7 +131,7 @@ EAC1_1_Req create_cvc_req(Private_Key co
       .get_contents();
 
    MemoryVector<byte> signed_cert = EAC1_1_gen_CVC<EAC1_1_Req>::make_signed(signer, EAC1_1_gen_CVC<EAC1_1_Req>::build_cert_body(tbs), rng);
-   std::tr1::shared_ptr<DataSource> source(new DataSource_Memory(signed_cert));
+   shared_ptr<DataSource> source(new DataSource_Memory(signed_cert));
    return EAC1_1_Req(source);
    }
 
@@ -151,7 +151,7 @@ EAC1_1_ADO create_ado_req(Private_Key co
    SecureVector<byte> tbs_bits = req.BER_encode();
    tbs_bits.append(DER_Encoder().encode(car).get_contents());
    MemoryVector<byte> signed_cert = EAC1_1_ADO::make_signed(signer, tbs_bits, rng);
-   std::tr1::shared_ptr<DataSource> source(new DataSource_Memory(signed_cert));
+   shared_ptr<DataSource> source(new DataSource_Memory(signed_cert));
    return EAC1_1_ADO(source);
    }
 
