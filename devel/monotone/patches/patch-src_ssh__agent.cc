$NetBSD: patch-src_ssh__agent.cc,v 1.1 2013/03/02 18:15:39 joerg Exp $

--- src/ssh_agent.cc.orig	2011-03-26 06:41:01.000000000 +0000
+++ src/ssh_agent.cc
@@ -32,7 +32,6 @@ using std::string;
 using std::vector;
 
 using boost::shared_ptr;
-using boost::shared_dynamic_cast;
 
 using Botan::RSA_PublicKey;
 using Botan::RSA_PrivateKey;
@@ -391,7 +390,7 @@ ssh_agent::has_key(const keypair & key)
   L(FL("has_key: building %d-byte pub key") % pub_block.size());
   shared_ptr<X509_PublicKey> x509_key =
     shared_ptr<X509_PublicKey>(Botan::X509::load_key(pub_block));
-  shared_ptr<RSA_PublicKey> pub_key = shared_dynamic_cast<RSA_PublicKey>(x509_key);
+  shared_ptr<RSA_PublicKey> pub_key = boost::dynamic_pointer_cast<RSA_PublicKey>(x509_key);
 
   if (!pub_key)
     throw recoverable_failure(origin::system,
