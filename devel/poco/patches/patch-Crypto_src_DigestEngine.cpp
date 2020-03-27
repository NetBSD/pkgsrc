$NetBSD: patch-Crypto_src_DigestEngine.cpp,v 1.1 2020/03/27 02:08:11 joerg Exp $

--- Crypto/src/DigestEngine.cpp.orig	2020-03-27 00:22:29.908133661 +0000
+++ Crypto/src/DigestEngine.cpp
@@ -39,7 +39,7 @@ DigestEngine::~DigestEngine()
 
 int DigestEngine::nid() const
 {
-	return EVP_MD_nid(_ctx->digest);
+	return EVP_MD_nid(EVP_MD_CTX_md(_ctx));
 }
 
 std::size_t DigestEngine::digestLength() const
@@ -50,7 +50,7 @@ std::size_t DigestEngine::digestLength()
 
 void DigestEngine::reset()
 {
-	EVP_MD_CTX_cleanup(_ctx);
+	EVP_MD_CTX_reset(_ctx);
 	const EVP_MD* md = EVP_get_digestbyname(_name.c_str());
 	if (!md) throw Poco::NotFoundException(_name);
 	EVP_DigestInit_ex(_ctx, md, NULL);
