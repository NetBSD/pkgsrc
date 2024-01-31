$NetBSD: patch-src_dkimsign.cpp,v 1.1 2024/01/31 19:19:58 schmonz Exp $

Fix build with newer OpenSSL (from FreeBSD).

--- src/dkimsign.cpp.orig	2024-01-30 15:33:54.094028460 +0000
+++ src/dkimsign.cpp
@@ -41,20 +41,26 @@ CDKIMSign::CDKIMSign()
 	m_EmptyLineCount = 0;
 	m_pfnHdrCallback = NULL;
 
-	EVP_SignInit( &m_allman_sha1ctx, EVP_sha1() );
-	EVP_SignInit( &m_Hdr_ietf_sha1ctx, EVP_sha1() );
-	EVP_SignInit( &m_Hdr_ietf_sha256ctx, EVP_sha256() );
-	EVP_DigestInit( &m_Bdy_ietf_sha1ctx, EVP_sha1() );
-	EVP_DigestInit( &m_Bdy_ietf_sha256ctx, EVP_sha256() );
+	m_allman_sha1ctx = EVP_MD_CTX_create();
+	m_Hdr_ietf_sha1ctx = EVP_MD_CTX_create();
+	m_Hdr_ietf_sha256ctx = EVP_MD_CTX_create();
+	m_Bdy_ietf_sha1ctx = EVP_MD_CTX_create();
+	m_Bdy_ietf_sha256ctx = EVP_MD_CTX_create();
+
+	EVP_SignInit( m_allman_sha1ctx, EVP_sha1() );
+	EVP_SignInit( m_Hdr_ietf_sha1ctx, EVP_sha1() );
+	EVP_SignInit( m_Hdr_ietf_sha256ctx, EVP_sha256() );
+	EVP_DigestInit( m_Bdy_ietf_sha1ctx, EVP_sha1() );
+	EVP_DigestInit( m_Bdy_ietf_sha256ctx, EVP_sha256() );
 }
 
 CDKIMSign::~CDKIMSign()
 {
-	EVP_MD_CTX_cleanup( &m_allman_sha1ctx );
-	EVP_MD_CTX_cleanup( &m_Hdr_ietf_sha1ctx );
-	EVP_MD_CTX_cleanup( &m_Hdr_ietf_sha256ctx );
-	EVP_MD_CTX_cleanup( &m_Bdy_ietf_sha1ctx );
-	EVP_MD_CTX_cleanup( &m_Bdy_ietf_sha256ctx );
+	EVP_MD_CTX_destroy( m_allman_sha1ctx );
+	EVP_MD_CTX_destroy( m_Hdr_ietf_sha1ctx );
+	EVP_MD_CTX_destroy( m_Hdr_ietf_sha256ctx );
+	EVP_MD_CTX_destroy( m_Bdy_ietf_sha1ctx );
+	EVP_MD_CTX_destroy( m_Bdy_ietf_sha256ctx );
 }
 
 ////////////////////////////////////////////////////////////////////////////////
@@ -150,34 +156,34 @@ void CDKIMSign::Hash( const char* szBuff
 	{
 		if( m_nIncludeBodyHash & DKIM_BODYHASH_ALLMAN_1 )
 		{
-			EVP_SignUpdate( &m_allman_sha1ctx, szBuffer, nBufLength );
+			EVP_SignUpdate( m_allman_sha1ctx, szBuffer, nBufLength );
 		}
 	}
 	else
 	{
 		if( m_nIncludeBodyHash < DKIM_BODYHASH_IETF_1 )
 		{
-			EVP_SignUpdate( &m_allman_sha1ctx, szBuffer, nBufLength );
+			EVP_SignUpdate( m_allman_sha1ctx, szBuffer, nBufLength );
 		}
 		else if( m_nIncludeBodyHash & DKIM_BODYHASH_IETF_1 )
 		{
 			if( m_nIncludeBodyHash & DKIM_BODYHASH_ALLMAN_1 )
 			{
-				EVP_SignUpdate( &m_allman_sha1ctx, szBuffer, nBufLength );
+				EVP_SignUpdate( m_allman_sha1ctx, szBuffer, nBufLength );
 			}
 			if( m_nHash & DKIM_HASH_SHA256 )
 			{
 				if( bHdr )
-					EVP_SignUpdate( &m_Hdr_ietf_sha256ctx, szBuffer, nBufLength );
+					EVP_SignUpdate( m_Hdr_ietf_sha256ctx, szBuffer, nBufLength );
 				else
-					EVP_DigestUpdate( &m_Bdy_ietf_sha256ctx, szBuffer, nBufLength );
+					EVP_DigestUpdate( m_Bdy_ietf_sha256ctx, szBuffer, nBufLength );
 			}
 			if( m_nHash != DKIM_HASH_SHA256 )
 			{
 				if( bHdr )
-					EVP_SignUpdate( &m_Hdr_ietf_sha1ctx, szBuffer, nBufLength );
+					EVP_SignUpdate( m_Hdr_ietf_sha1ctx, szBuffer, nBufLength );
 				else
-					EVP_DigestUpdate( &m_Bdy_ietf_sha1ctx, szBuffer, nBufLength );
+					EVP_DigestUpdate( m_Bdy_ietf_sha1ctx, szBuffer, nBufLength );
 			}
 		}
 	}
@@ -865,7 +871,7 @@ int CDKIMSign::ConstructSignature( char*
 		unsigned char Hash[EVP_MAX_MD_SIZE];
 		unsigned int nHashLen = 0;
 
-		EVP_DigestFinal( bUseSha256 ? &m_Bdy_ietf_sha256ctx : &m_Bdy_ietf_sha1ctx, Hash, &nHashLen );
+		EVP_DigestFinal( bUseSha256 ? m_Bdy_ietf_sha256ctx : m_Bdy_ietf_sha1ctx, Hash, &nHashLen );
 
 		bio = BIO_new(BIO_s_mem());
 		if (!bio) {
@@ -936,11 +942,11 @@ int CDKIMSign::ConstructSignature( char*
 
 	if( bUseIetfBodyHash )
 	{
-		EVP_SignUpdate( bUseSha256 ? &m_Hdr_ietf_sha256ctx : &m_Hdr_ietf_sha1ctx, sTemp.c_str(), sTemp.size() );
+		EVP_SignUpdate( bUseSha256 ? m_Hdr_ietf_sha256ctx : m_Hdr_ietf_sha1ctx, sTemp.c_str(), sTemp.size() );
 	}
 	else
 	{
-		EVP_SignUpdate( &m_allman_sha1ctx, sTemp.c_str(), sTemp.size() );
+		EVP_SignUpdate( m_allman_sha1ctx, sTemp.c_str(), sTemp.size() );
 	}
  
 	bio = BIO_new_mem_buf(szPrivKey, -1);
@@ -967,11 +973,11 @@ int CDKIMSign::ConstructSignature( char*
 	
 	if( bUseIetfBodyHash )
 	{
-		nSignRet = EVP_SignFinal( bUseSha256 ? &m_Hdr_ietf_sha256ctx : &m_Hdr_ietf_sha1ctx, sig, &siglen, pkey);
+		nSignRet = EVP_SignFinal( bUseSha256 ? m_Hdr_ietf_sha256ctx : m_Hdr_ietf_sha1ctx, sig, &siglen, pkey);
 	}
 	else
 	{
-		nSignRet = EVP_SignFinal( &m_allman_sha1ctx, sig, &siglen, pkey);
+		nSignRet = EVP_SignFinal( m_allman_sha1ctx, sig, &siglen, pkey);
 	}
 
     EVP_PKEY_free(pkey);
