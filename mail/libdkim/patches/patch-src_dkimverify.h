$NetBSD: patch-src_dkimverify.h,v 1.1 2024/01/31 19:19:58 schmonz Exp $

Fix build with newer OpenSSL (from FreeBSD).

--- src/dkimverify.h.orig	2024-01-30 15:38:58.878663825 +0000
+++ src/dkimverify.h
@@ -83,8 +83,8 @@ public:
 	unsigned VerifiedBodyCount;
 	unsigned UnverifiedBodyCount;
 
-	EVP_MD_CTX m_Hdr_ctx;
-	EVP_MD_CTX m_Bdy_ctx;
+	EVP_MD_CTX *m_Hdr_ctx;
+	EVP_MD_CTX *m_Bdy_ctx;
 	SelectorInfo *m_pSelector;
 
 	int Status;
