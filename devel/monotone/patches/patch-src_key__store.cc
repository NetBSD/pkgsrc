$NetBSD: patch-src_key__store.cc,v 1.1 2013/03/02 18:15:39 joerg Exp $

--- src/key_store.cc.orig	2011-03-26 06:40:59.000000000 +0000
+++ src/key_store.cc
@@ -43,7 +43,6 @@ using std::vector;
 
 using boost::scoped_ptr;
 using boost::shared_ptr;
-using boost::shared_dynamic_cast;
 
 using Botan::RSA_PrivateKey;
 using Botan::RSA_PublicKey;
@@ -628,7 +627,7 @@ key_store_state::decrypt_private_key(key
   I(pkcs8_key);
 
   shared_ptr<RSA_PrivateKey> priv_key;
-  priv_key = shared_dynamic_cast<RSA_PrivateKey>(pkcs8_key);
+  priv_key = boost::dynamic_pointer_cast<RSA_PrivateKey>(pkcs8_key);
   E(priv_key, origin::no_fault,
     F("failed to extract RSA private key from PKCS#8 keypair"));
 
@@ -862,7 +861,7 @@ key_store::make_signature(database & db,
         L(FL("make_signature: building %d-byte pub key") % pub_block.size());
         shared_ptr<X509_PublicKey> x509_key =
           shared_ptr<X509_PublicKey>(Botan::X509::load_key(pub_block));
-        shared_ptr<RSA_PublicKey> pub_key = shared_dynamic_cast<RSA_PublicKey>(x509_key);
+        shared_ptr<RSA_PublicKey> pub_key = boost::dynamic_pointer_cast<RSA_PublicKey>(x509_key);
 
         if (!pub_key)
           throw recoverable_failure(origin::system,
@@ -1065,7 +1064,7 @@ key_store_state::migrate_old_key_pair
         continue;
       }
 
-  priv_key = shared_dynamic_cast<RSA_PrivateKey>(pkcs8_key);
+  priv_key = boost::dynamic_pointer_cast<RSA_PrivateKey>(pkcs8_key);
   I(priv_key);
 
   // now we can write out the new key
