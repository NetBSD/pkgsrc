$NetBSD: patch-pdns_botan18signers.cc,v 1.2 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- pdns/botan18signers.cc.orig	2015-03-02 13:17:09.000000000 +0000
+++ pdns/botan18signers.cc
@@ -36,8 +36,8 @@ public:
 
 private:
   static EC_Domain_Params getECParams(unsigned int algorithm);
-  shared_ptr<ECDSA_PrivateKey> d_key;
-  shared_ptr<ECDSA_PublicKey> d_pubkey;
+  boost::shared_ptr<ECDSA_PrivateKey> d_key;
+  boost::shared_ptr<ECDSA_PublicKey> d_pubkey;
 };
 
 EC_Domain_Params ECDSADNSCryptoKeyEngine::getECParams(unsigned int algorithm) 
@@ -56,7 +56,7 @@ void ECDSADNSCryptoKeyEngine::create(uns
   if(bits != 256 && bits != 384) {
     throw runtime_error("Unknown key length of "+lexical_cast<string>(bits)+" bits requested from ECDSA class");
   }
-  d_key = shared_ptr<ECDSA_PrivateKey>(new ECDSA_PrivateKey(rng, getECParams((bits == 256) ? 13 : 14)));
+  d_key = boost::shared_ptr<ECDSA_PrivateKey>(new ECDSA_PrivateKey(rng, getECParams((bits == 256) ? 13 : 14)));
   
 //  PKCS8_Encoder* pk8e= d_key->pkcs8_encoder();
 //  MemoryVector<byte> getbits=pk8e->key_bits();
@@ -113,7 +113,7 @@ void ECDSADNSCryptoKeyEngine::fromISCMap
   
   EC_Domain_Params params=getECParams(drc.d_algorithm);
   
-  d_key=shared_ptr<ECDSA_PrivateKey>(new ECDSA_PrivateKey);
+  d_key=boost::shared_ptr<ECDSA_PrivateKey>(new ECDSA_PrivateKey);
   AutoSeeded_RNG rng;
 
   SecureVector<byte> octstr_secret = BigInt::encode_1363(bigint, getBits()/8);
@@ -168,7 +168,7 @@ void ECDSADNSCryptoKeyEngine::fromPublic
   GFpElement gfpx(params.get_curve().get_ptr_mod(), x);
   GFpElement gfpy(params.get_curve().get_ptr_mod(), y);
   PointGFp point(params.get_curve(), gfpx,gfpy);
-  d_pubkey = shared_ptr<ECDSA_PublicKey>(new ECDSA_PublicKey(params, point));
+  d_pubkey = boost::shared_ptr<ECDSA_PublicKey>(new ECDSA_PublicKey(params, point));
   d_key.reset();
 }
 
