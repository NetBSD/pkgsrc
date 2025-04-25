$NetBSD: patch-src_gcrypt_asymkeys.c,v 1.1 2025/04/25 07:18:10 wiz Exp $

libxml2 2.14 compatibility.

--- src/gcrypt/asymkeys.c.orig	2025-04-25 07:15:25.968184022 +0000
+++ src/gcrypt/asymkeys.c
@@ -810,7 +810,7 @@ xmlSecGCryptKeyDataDsaFinalize(xmlSecKey
 }
 
 static int
-xmlSecGCryptKeyDataDsaGenerate(xmlSecKeyDataPtr data, xmlSecSize sizeBits, xmlSecKeyDataType type ATTRIBUTE_UNUSED) {
+xmlSecGCryptKeyDataDsaGenerate(xmlSecKeyDataPtr data, xmlSecSize sizeBits, xmlSecKeyDataType type) {
     xmlSecAssert2(xmlSecKeyDataCheckId(data, xmlSecGCryptKeyDataDsaId), -1);
     xmlSecAssert2(sizeBits > 0, -1);
 
@@ -1387,7 +1387,7 @@ xmlSecGCryptKeyDataRsaFinalize(xmlSecKey
 }
 
 static int
-xmlSecGCryptKeyDataRsaGenerate(xmlSecKeyDataPtr data, xmlSecSize sizeBits, xmlSecKeyDataType type ATTRIBUTE_UNUSED) {
+xmlSecGCryptKeyDataRsaGenerate(xmlSecKeyDataPtr data, xmlSecSize sizeBits, xmlSecKeyDataType type) {
     xmlSecAssert2(xmlSecKeyDataCheckId(data, xmlSecGCryptKeyDataRsaId), -1);
     xmlSecAssert2(sizeBits > 0, -1);
 
