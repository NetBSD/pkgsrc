$NetBSD: patch-src_gcrypt_symkeys.c,v 1.2 2025/04/25 07:23:35 wiz Exp $

libxml2 2.14 compatibility.
https://github.com/lsh123/xmlsec/issues/904

--- src/gcrypt/symkeys.c.orig	2025-04-25 07:15:55.924534537 +0000
+++ src/gcrypt/symkeys.c
@@ -131,7 +131,7 @@ xmlSecGCryptSymKeyDataBinWrite(xmlSecKey
 }
 
 static int
-xmlSecGCryptSymKeyDataGenerate(xmlSecKeyDataPtr data, xmlSecSize sizeBits, xmlSecKeyDataType type ATTRIBUTE_UNUSED) {
+xmlSecGCryptSymKeyDataGenerate(xmlSecKeyDataPtr data, xmlSecSize sizeBits, xmlSecKeyDataType type) {
     xmlSecBufferPtr buffer;
 
     xmlSecAssert2(xmlSecGCryptSymKeyDataCheckId(data), -1);
