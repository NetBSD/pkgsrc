$NetBSD: patch-nss_cmd_pk11gcmtest_pk11gcmtest.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/cmd/pk11gcmtest/pk11gcmtest.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/cmd/pk11gcmtest/pk11gcmtest.c
@@ -269,10 +269,10 @@ aes_gcm_kat(const char *respfn)
         /* Key = ... */
         if (strncmp(buf, "Key", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -286,10 +286,10 @@ aes_gcm_kat(const char *respfn)
         /* IV = ... */
         if (strncmp(buf, "IV", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &iv[j]);
             }
             ivsize = j;
@@ -303,10 +303,10 @@ aes_gcm_kat(const char *respfn)
         /* PT = ... */
         if (strncmp(buf, "PT", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -357,10 +357,10 @@ aes_gcm_kat(const char *respfn)
         /* AAD = ... */
         if (strncmp(buf, "AAD", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &aad[j]);
             }
             aadlen = j;
@@ -374,10 +374,10 @@ aes_gcm_kat(const char *respfn)
         /* CT = ... */
         if (strncmp(buf, "CT", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -391,10 +391,10 @@ aes_gcm_kat(const char *respfn)
         /* Tag = ... */
         if (strncmp(buf, "Tag", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &tag[j]);
             }
             tagsize = j;
