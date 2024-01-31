$NetBSD: patch-src_dkimsign.h,v 1.1 2024/01/31 19:19:58 schmonz Exp $

Fix build with newer OpenSSL (from FreeBSD).

--- src/dkimsign.h.orig	2024-01-30 15:32:51.926798884 +0000
+++ src/dkimsign.h
@@ -60,13 +60,13 @@ protected:
 
 	int AssembleReturnedSig( char* szPrivKey );
 
-	EVP_MD_CTX m_Hdr_ietf_sha1ctx;		/* the header hash for ietf sha1  */
-	EVP_MD_CTX m_Hdr_ietf_sha256ctx;	/* the header hash for ietf sha256 */
+	EVP_MD_CTX *m_Hdr_ietf_sha1ctx;		/* the header hash for ietf sha1  */
+	EVP_MD_CTX *m_Hdr_ietf_sha256ctx;	/* the header hash for ietf sha256 */
 
-	EVP_MD_CTX m_Bdy_ietf_sha1ctx;		/* the body hash for ietf sha1  */
-	EVP_MD_CTX m_Bdy_ietf_sha256ctx;	/* the body hash for ietf sha256 */
+	EVP_MD_CTX *m_Bdy_ietf_sha1ctx;		/* the body hash for ietf sha1  */
+	EVP_MD_CTX *m_Bdy_ietf_sha256ctx;	/* the body hash for ietf sha256 */
 
-	EVP_MD_CTX m_allman_sha1ctx;		/* the hash for allman sha1  */
+	EVP_MD_CTX *m_allman_sha1ctx;		/* the hash for allman sha1  */
 
 	int m_Canon;				// canonization method
 
