$NetBSD: patch-src_gcrypt_signatures.c,v 1.1 2025/04/25 07:18:10 wiz Exp $

libxml2 2.14 compatibility.

--- src/gcrypt/signatures.c.orig	2025-04-25 07:15:42.654086302 +0000
+++ src/gcrypt/signatures.c
@@ -595,7 +595,7 @@ xmlSecGCryptAppendMpi(gcry_mpi_t a, xmlS
  *
  ***************************************************************************/
 static int
-xmlSecGCryptDsaPkSign(int digest ATTRIBUTE_UNUSED, xmlSecKeyDataPtr key_data,
+xmlSecGCryptDsaPkSign(int digest, xmlSecKeyDataPtr key_data,
                       const xmlSecByte* dgst, xmlSecSize dgstSize,
                       xmlSecBufferPtr out) {
     gcry_mpi_t m_hash = NULL;
@@ -732,7 +732,7 @@ done:
 }
 
 static int
-xmlSecGCryptDsaPkVerify(int digest ATTRIBUTE_UNUSED, xmlSecKeyDataPtr key_data,
+xmlSecGCryptDsaPkVerify(int digest, xmlSecKeyDataPtr key_data,
                         const xmlSecByte* dgst, xmlSecSize dgstSize,
                         const xmlSecByte* data, xmlSecSize dataSize) {
     gcry_mpi_t m_hash = NULL;
