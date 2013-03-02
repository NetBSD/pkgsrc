$NetBSD: patch-src_database.cc,v 1.1 2013/03/02 18:15:39 joerg Exp $

--- src/database.cc.orig	2011-03-26 06:40:58.000000000 +0000
+++ src/database.cc
@@ -92,7 +92,6 @@ using std::vector;
 using std::accumulate;
 
 using boost::shared_ptr;
-using boost::shared_dynamic_cast;
 using boost::lexical_cast;
 using boost::get;
 using boost::tuple;
@@ -3431,7 +3430,7 @@ database::encrypt_rsa(key_id const & pub
 
   shared_ptr<X509_PublicKey> x509_key(Botan::X509::load_key(pub_block));
   shared_ptr<RSA_PublicKey> pub_key
-    = shared_dynamic_cast<RSA_PublicKey>(x509_key);
+    = boost::dynamic_pointer_cast<RSA_PublicKey>(x509_key);
   if (!pub_key)
     throw recoverable_failure(origin::system,
                               "Failed to get RSA encrypting key");
@@ -3483,7 +3482,7 @@ database::check_signature(key_id const &
       L(FL("building verifier for %d-byte pub key") % pub_block.size());
       shared_ptr<X509_PublicKey> x509_key(Botan::X509::load_key(pub_block));
       shared_ptr<RSA_PublicKey> pub_key
-        = boost::shared_dynamic_cast<RSA_PublicKey>(x509_key);
+        = boost::dynamic_pointer_cast<RSA_PublicKey>(x509_key);
 
       E(pub_key, id.inner().made_from,
         F("Failed to get RSA verifying key for %s") % id);
