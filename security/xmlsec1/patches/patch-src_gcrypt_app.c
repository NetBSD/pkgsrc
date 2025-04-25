$NetBSD: patch-src_gcrypt_app.c,v 1.2 2025/04/25 07:20:42 wiz Exp $

libxml2 2.14 compatibility.

--- src/gcrypt/app.c.orig	2024-07-18 19:46:42.000000000 +0000
+++ src/gcrypt/app.c
@@ -41,7 +41,7 @@
  * Returns: 0 on success or a negative value otherwise.
  */
 int
-xmlSecGCryptAppInit(const char* config ATTRIBUTE_UNUSED) {
+xmlSecGCryptAppInit(const char* config) {
     gcry_error_t err;
     /* Secure memory initialisation based on documentation from:
          http://www.gnupg.org/documentation/manuals/gcrypt/Initializing-the-library.html
@@ -214,9 +214,9 @@ xmlSecGCryptAppKeyLoad(const char *filen
 xmlSecKeyPtr
 xmlSecGCryptAppKeyLoadMemory(const xmlSecByte* data, xmlSecSize dataSize,
                         xmlSecKeyDataFormat format,
-                        const char *pwd ATTRIBUTE_UNUSED,
-                        void* pwdCallback ATTRIBUTE_UNUSED,
-                        void* pwdCallbackCtx ATTRIBUTE_UNUSED)
+                        const char *pwd,
+                        void* pwdCallback,
+                        void* pwdCallbackCtx)
 {
     xmlSecKeyPtr key = NULL;
     xmlSecKeyDataPtr key_data = NULL;
@@ -337,9 +337,9 @@ xmlSecGCryptAppKeyCertLoadMemory(xmlSecK
  */
 xmlSecKeyPtr
 xmlSecGCryptAppPkcs12Load(const char *filename,
-                          const char *pwd ATTRIBUTE_UNUSED,
-                          void* pwdCallback ATTRIBUTE_UNUSED,
-                          void* pwdCallbackCtx ATTRIBUTE_UNUSED) {
+                          const char *pwd,
+                          void* pwdCallback,
+                          void* pwdCallbackCtx) {
     xmlSecAssert2(filename != NULL, NULL);
 
     /* TODO */
@@ -363,9 +363,9 @@ xmlSecGCryptAppPkcs12Load(const char *fi
  */
 xmlSecKeyPtr
 xmlSecGCryptAppPkcs12LoadMemory(const xmlSecByte* data, xmlSecSize dataSize,
-                           const char *pwd ATTRIBUTE_UNUSED,
-                           void* pwdCallback ATTRIBUTE_UNUSED,
-                           void* pwdCallbackCtx ATTRIBUTE_UNUSED) {
+                           const char *pwd,
+                           void* pwdCallback,
+                           void* pwdCallbackCtx) {
     xmlSecAssert2(data != NULL, NULL);
     xmlSecAssert2(dataSize > 0, NULL);
 
@@ -391,7 +391,7 @@ int
 xmlSecGCryptAppKeysMngrCertLoad(xmlSecKeysMngrPtr mngr,
                                 const char *filename,
                                 xmlSecKeyDataFormat format,
-                                xmlSecKeyDataType type ATTRIBUTE_UNUSED) {
+                                xmlSecKeyDataType type) {
     xmlSecAssert2(mngr != NULL, -1);
     xmlSecAssert2(filename != NULL, -1);
     xmlSecAssert2(format != xmlSecKeyDataFormatUnknown, -1);
@@ -419,7 +419,7 @@ xmlSecGCryptAppKeysMngrCertLoadMemory(xm
                                       const xmlSecByte* data,
                                       xmlSecSize dataSize,
                                       xmlSecKeyDataFormat format,
-                                      xmlSecKeyDataType type ATTRIBUTE_UNUSED) {
+                                      xmlSecKeyDataType type) {
     xmlSecAssert2(mngr != NULL, -1);
     xmlSecAssert2(data != NULL, -1);
     xmlSecAssert2(dataSize > 0, -1);
