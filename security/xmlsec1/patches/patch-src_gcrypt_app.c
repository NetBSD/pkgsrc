$NetBSD: patch-src_gcrypt_app.c,v 1.1 2025/04/25 07:18:10 wiz Exp $

libxml2 2.14 compatibility.

--- src/gcrypt/app.c.orig	2025-04-25 07:16:07.004790752 +0000
+++ src/gcrypt/app.c
@@ -40,7 +40,7 @@
  * Returns: 0 on success or a negative value otherwise.
  */
 int
-xmlSecGCryptAppInit(const char* config ATTRIBUTE_UNUSED) {
+xmlSecGCryptAppInit(const char* config) {
     gcry_error_t err;
     /* Secure memory initialisation based on documentation from:
          http://www.gnupg.org/documentation/manuals/gcrypt/Initializing-the-library.html
@@ -212,9 +212,9 @@ xmlSecGCryptAppKeyLoad(const char *filen
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
@@ -335,9 +335,9 @@ xmlSecGCryptAppKeyCertLoadMemory(xmlSecK
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
@@ -361,9 +361,9 @@ xmlSecGCryptAppPkcs12Load(const char *fi
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
 
@@ -389,7 +389,7 @@ int
 xmlSecGCryptAppKeysMngrCertLoad(xmlSecKeysMngrPtr mngr, 
                                 const char *filename,
                                 xmlSecKeyDataFormat format,
-                                xmlSecKeyDataType type ATTRIBUTE_UNUSED) {
+                                xmlSecKeyDataType type) {
     xmlSecAssert2(mngr != NULL, -1);
     xmlSecAssert2(filename != NULL, -1);
     xmlSecAssert2(format != xmlSecKeyDataFormatUnknown, -1);
@@ -417,7 +417,7 @@ xmlSecGCryptAppKeysMngrCertLoadMemory(xm
                                       const xmlSecByte* data,
                                       xmlSecSize dataSize,
                                       xmlSecKeyDataFormat format,
-                                      xmlSecKeyDataType type ATTRIBUTE_UNUSED) {
+                                      xmlSecKeyDataType type) {
     xmlSecAssert2(mngr != NULL, -1);
     xmlSecAssert2(data != NULL, -1);
     xmlSecAssert2(dataSize > 0, -1);
