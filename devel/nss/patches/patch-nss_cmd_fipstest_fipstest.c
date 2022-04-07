$NetBSD: patch-nss_cmd_fipstest_fipstest.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/cmd/fipstest/fipstest.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/cmd/fipstest/fipstest.c
@@ -128,7 +128,7 @@ from_hex_str(unsigned char *buf, unsigne
 
     /* count the hex digits */
     nxdigit = 0;
-    for (nxdigit = 0; isxdigit(str[nxdigit]); nxdigit++) {
+    for (nxdigit = 0; isxdigit((unsigned char)str[nxdigit]); nxdigit++) {
         /* empty body */
     }
     if (nxdigit == 0) {
@@ -336,7 +336,7 @@ tdea_kat_mmt(char *reqfn)
         /* NumKeys */
         if (strncmp(&buf[0], "NumKeys", 7) == 0) {
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             numKeys = buf[i];
@@ -360,10 +360,10 @@ tdea_kat_mmt(char *reqfn)
         if (numKeys == 0) {
             if (strncmp(buf, "KEYs", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                     key[j + 8] = key[j];
                     key[j + 16] = key[j];
@@ -375,10 +375,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY1 = ... */
             if (strncmp(buf, "KEY1", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -387,10 +387,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY2 = ... */
             if (strncmp(buf, "KEY2", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 8; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 8; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -399,10 +399,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY3 = ... */
             if (strncmp(buf, "KEY3", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 16; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 16; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -414,7 +414,7 @@ tdea_kat_mmt(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             mode = NSS_DES_EDE3_CBC;
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -431,10 +431,10 @@ tdea_kat_mmt(char *reqfn)
                 goto loser;
             }
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -461,10 +461,10 @@ tdea_kat_mmt(char *reqfn)
             }
 
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -779,7 +779,7 @@ tdea_mct(int mode, char *reqfn)
         /* NumKeys */
         if (strncmp(&buf[0], "NumKeys", 7) == 0) {
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             numKeys = atoi(&buf[i]);
@@ -788,10 +788,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY1 = ... */
         if (strncmp(buf, "KEY1", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -799,10 +799,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY2 = ... */
         if (strncmp(buf, "KEY2", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 8; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 8; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -810,10 +810,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY3 = ... */
         if (strncmp(buf, "KEY3", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 16; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 16; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -822,7 +822,7 @@ tdea_mct(int mode, char *reqfn)
         /* IV = ... */
         if (strncmp(buf, "IV", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -840,7 +840,7 @@ tdea_mct(int mode, char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof plaintext; i += 2, j++) {
@@ -863,10 +863,10 @@ tdea_mct(int mode, char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -1071,10 +1071,10 @@ aes_gcm(char *reqfn, int encrypt)
         /* KEY = ... */
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
@@ -1084,7 +1084,7 @@ aes_gcm(char *reqfn, int encrypt)
         /* IV = ... */
         if (strncmp(buf, "IV", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -1101,10 +1101,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
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
@@ -1119,10 +1119,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
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
@@ -1131,10 +1131,10 @@ aes_gcm(char *reqfn, int encrypt)
         }
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
@@ -1183,10 +1183,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j + ciphertextlen]);
             }
             ciphertextlen += j;
@@ -1282,10 +1282,10 @@ aes_kat_mmt(char *reqfn)
         /* KEY = ... */
         if (strncmp(buf, "KEY", 3) == 0) {
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
@@ -1296,7 +1296,7 @@ aes_kat_mmt(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             mode = NSS_AES_CBC;
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -1313,10 +1313,10 @@ aes_kat_mmt(char *reqfn)
             }
 
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -1347,10 +1347,10 @@ aes_kat_mmt(char *reqfn)
             }
 
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -1486,10 +1486,10 @@ aes_ecb_mct(char *reqfn)
         if (strncmp(buf, "KEY", 3) == 0) {
             /* Key[0] = Key */
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
@@ -1503,7 +1503,7 @@ aes_ecb_mct(char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof plaintext; i += 2, j++) {
@@ -1601,10 +1601,10 @@ aes_ecb_mct(char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -1771,10 +1771,10 @@ aes_cbc_mct(char *reqfn)
         if (strncmp(buf, "KEY", 3) == 0) {
             /* Key[0] = Key */
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
@@ -1784,7 +1784,7 @@ aes_cbc_mct(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             /* IV[0] = IV */
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -1800,7 +1800,7 @@ aes_cbc_mct(char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof plaintext; i += 2, j++) {
@@ -1912,10 +1912,10 @@ aes_cbc_mct(char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -2417,7 +2417,7 @@ ecdsa_keypair_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2; /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2528,7 +2528,7 @@ ecdsa_pkv_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2; /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2565,7 +2565,7 @@ ecdsa_pkv_test(char *reqfn)
         if (strncmp(buf, "Qx", 2) == 0) {
             fputs(buf, ecdsaresp);
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&pubkey.data[1], len, &buf[i]);
@@ -2579,7 +2579,7 @@ ecdsa_pkv_test(char *reqfn)
                 continue;
             }
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&pubkey.data[1 + len], len, &buf[i]);
@@ -2653,7 +2653,7 @@ ecdsa_siggen_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2; /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2688,10 +2688,10 @@ ecdsa_siggen_test(char *reqfn)
             ECPrivateKey *ecpriv;
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             msglen = j;
@@ -2814,7 +2814,7 @@ ecdsa_sigver_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2; /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2869,10 +2869,10 @@ ecdsa_sigver_test(char *reqfn)
         /* Msg = ... */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             msglen = j;
@@ -2897,7 +2897,7 @@ ecdsa_sigver_test(char *reqfn)
         if (strncmp(buf, "Qx", 2) == 0) {
             fputs(buf, ecdsaresp);
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&ecpub.publicValue.data[1], flen,
@@ -2911,7 +2911,7 @@ ecdsa_sigver_test(char *reqfn)
                 continue;
             }
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&ecpub.publicValue.data[1 + flen], flen,
@@ -2933,7 +2933,7 @@ ecdsa_sigver_test(char *reqfn)
         if (buf[0] == 'R') {
             fputs(buf, ecdsaresp);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             sigvalid = from_hex_str(sig, olen, &buf[i]);
@@ -2943,7 +2943,7 @@ ecdsa_sigver_test(char *reqfn)
         if (buf[0] == 'S') {
             fputs(buf, ecdsaresp);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (sigvalid) {
@@ -3043,7 +3043,7 @@ ecdh_functional(char *reqfn, PRBool resp
                 while (*src && *src == ' ')
                     src++;
                 dst = &curve[4];
-                *dst++ = tolower(*src);
+                *dst++ = tolower((unsigned char)*src);
                 src += 2; /* skip the hyphen */
                 *dst++ = *src++;
                 *dst++ = *src++;
@@ -3128,7 +3128,7 @@ ecdh_functional(char *reqfn, PRBool resp
         if (strncmp(buf, "QeCAVSx", 7) == 0) {
             fputs(buf, ecdhresp);
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(&pubkey.data[1], len, &buf[i]);
@@ -3138,7 +3138,7 @@ ecdh_functional(char *reqfn, PRBool resp
         if (strncmp(buf, "QeCAVSy", 7) == 0) {
             fputs(buf, ecdhresp);
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(&pubkey.data[1 + len], len, &buf[i]);
@@ -3296,7 +3296,7 @@ ecdh_verify(char *reqfn, PRBool response
                 while (*src && *src == ' ')
                     src++;
                 dst = &curve[4];
-                *dst++ = tolower(*src);
+                *dst++ = tolower((unsigned char)*src);
                 src += 2; /* skip the hyphen */
                 *dst++ = *src++;
                 *dst++ = *src++;
@@ -3381,7 +3381,7 @@ ecdh_verify(char *reqfn, PRBool response
         if (strncmp(buf, "QeCAVSx", 7) == 0) {
             fputs(buf, ecdhresp);
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(&pubkey.data[1], len, &buf[i]);
@@ -3391,7 +3391,7 @@ ecdh_verify(char *reqfn, PRBool response
         if (strncmp(buf, "QeCAVSy", 7) == 0) {
             fputs(buf, ecdhresp);
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(&pubkey.data[1 + len], len, &buf[i]);
@@ -3400,7 +3400,7 @@ ecdh_verify(char *reqfn, PRBool response
         if (strncmp(buf, "deIUT", 5) == 0) {
             fputs(buf, ecdhresp);
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(private_data, len, &buf[i]);
@@ -3420,7 +3420,7 @@ ecdh_verify(char *reqfn, PRBool response
             (strncmp(buf, "HashZZ", 6) == 0)) {
             fputs(buf, ecdhresp);
             i = (buf[0] == 'C') ? 10 : 6;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(cavsHashBuf, fips_hashLen(hash), &buf[i]);
@@ -3577,11 +3577,11 @@ dh_functional(char *reqfn, PRBool respon
         }
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.prime.len; i += 2, j++) {
-                if (!isxdigit(buf[i])) {
+                if (!isxdigit((unsigned char)buf[i])) {
                     pqg.prime.len = j;
                     break;
                 }
@@ -3595,11 +3595,11 @@ dh_functional(char *reqfn, PRBool respon
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.subPrime.len; i += 2, j++) {
-                if (!isxdigit(buf[i])) {
+                if (!isxdigit((unsigned char)buf[i])) {
                     pqg.subPrime.len = j;
                     break;
                 }
@@ -3613,11 +3613,11 @@ dh_functional(char *reqfn, PRBool respon
         /* G = ... */
         if (buf[0] == 'G') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.base.len; i += 2, j++) {
-                if (!isxdigit(buf[i])) {
+                if (!isxdigit((unsigned char)buf[i])) {
                     pqg.base.len = j;
                     break;
                 }
@@ -3638,7 +3638,7 @@ dh_functional(char *reqfn, PRBool respon
         if (strncmp(buf, "YephemCAVS", 10) == 0) {
             fputs(buf, dhresp);
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(pubkeydata, pqg.prime.len, &buf[i]);
@@ -3771,11 +3771,11 @@ dh_verify(char *reqfn, PRBool response)
         }
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.prime.len; i += 2, j++) {
-                if (!isxdigit(buf[i])) {
+                if (!isxdigit((unsigned char)buf[i])) {
                     pqg.prime.len = j;
                     break;
                 }
@@ -3789,11 +3789,11 @@ dh_verify(char *reqfn, PRBool response)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.subPrime.len; i += 2, j++) {
-                if (!isxdigit(buf[i])) {
+                if (!isxdigit((unsigned char)buf[i])) {
                     pqg.subPrime.len = j;
                     break;
                 }
@@ -3807,11 +3807,11 @@ dh_verify(char *reqfn, PRBool response)
         /* G = ... */
         if (buf[0] == 'G') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.base.len; i += 2, j++) {
-                if (!isxdigit(buf[i])) {
+                if (!isxdigit((unsigned char)buf[i])) {
                     pqg.base.len = j;
                     break;
                 }
@@ -3832,7 +3832,7 @@ dh_verify(char *reqfn, PRBool response)
         if (strncmp(buf, "YephemCAVS", 10) == 0) {
             fputs(buf, dhresp);
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(pubkeydata, pqg.prime.len, &buf[i]);
@@ -3844,7 +3844,7 @@ dh_verify(char *reqfn, PRBool response)
         if (strncmp(buf, "XephemIUT", 9) == 0) {
             fputs(buf, dhresp);
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(privkeydata, pqg.subPrime.len, &buf[i]);
@@ -3862,7 +3862,7 @@ dh_verify(char *reqfn, PRBool response)
             (strncmp(buf, "HashZZ", 6) == 0)) {
             fputs(buf, dhresp);
             i = buf[0] == 'C' ? 10 : 6;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             from_hex_str(cavsHashBuf, fips_hashLen(hash), &buf[i]);
@@ -3908,7 +3908,7 @@ loser:
 PRBool
 isblankline(char *b)
 {
-    while (isspace(*b))
+    while (isspace((unsigned char)*b))
         b++;
     if ((*b == '\n') || (*b == 0)) {
         return PR_TRUE;
@@ -4067,7 +4067,7 @@ drbg(char *reqfn)
         if (strncmp(buf, "[PredictionResistance", 21) == 0) {
 #ifdef HANDLE_PREDICTION_RESISTANCE
             i = 21;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (strncmp(buf, "False", 5) == 0) {
@@ -4200,11 +4200,11 @@ drbg(char *reqfn)
             if (entropyInput) {
                 memset(entropyInput, 0, entropyInputLen);
                 i = 18;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
 
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<entropyInputLen*/
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<entropyInputLen*/
                     hex_to_byteval(&buf[i], &entropyInput[j]);
                 }
             }
@@ -4217,10 +4217,10 @@ drbg(char *reqfn)
             if (additionalInput) {
                 memset(additionalInput, 0, additionalInputLen);
                 i = 21;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<additionalInputLen*/
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<additionalInputLen*/
                     hex_to_byteval(&buf[i], &additionalInput[j]);
                 }
             }
@@ -4232,10 +4232,10 @@ drbg(char *reqfn)
         /* Entropy input = ... */
         if (strncmp(buf, "EntropyInput", 12) == 0) {
             i = 12;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<entropyInputLen*/
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<entropyInputLen*/
                 hex_to_byteval(&buf[i], &entropyInput[j]);
             }
             fputs(buf, rngresp);
@@ -4245,10 +4245,10 @@ drbg(char *reqfn)
         /* nouce = ... */
         if (strncmp(buf, "Nonce", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<nonceLen*/
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<nonceLen*/
                 hex_to_byteval(&buf[i], &nonce[j]);
             }
             fputs(buf, rngresp);
@@ -4259,10 +4259,10 @@ drbg(char *reqfn)
         if (strncmp(buf, "PersonalizationString", 21) == 0) {
             if (personalizationString) {
                 i = 21;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<personalizationStringLen*/
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<personalizationStringLen*/
                     hex_to_byteval(&buf[i], &personalizationString[j]);
                 }
             }
@@ -4275,10 +4275,10 @@ drbg(char *reqfn)
         if (strncmp(buf, "AdditionalInput", 15) == 0) {
             if (additionalInput) {
                 i = 15;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<additionalInputLen*/
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<additionalInputLen*/
                     hex_to_byteval(&buf[i], &additionalInput[j]);
                 }
             }
@@ -4295,10 +4295,10 @@ drbg(char *reqfn)
         /* Returned bits = ... */
         if (strncmp(buf, "ReturnedBits", 12) == 0) {
             i = 12;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<additionalInputLen*/
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<additionalInputLen*/
                 hex_to_byteval(&buf[i], &predictedreturn_bytes[j]);
             }
 
@@ -4397,7 +4397,7 @@ rng_vst(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof Q; i += 2, j++) {
@@ -4419,7 +4419,7 @@ rng_vst(char *reqfn)
         /* b = ... */
         if (buf[0] == 'b') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             b = atoi(&buf[i]);
@@ -4432,7 +4432,7 @@ rng_vst(char *reqfn)
         /* XKey = ... */
         if (strncmp(buf, "XKey", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -4444,7 +4444,7 @@ rng_vst(char *reqfn)
         /* XSeed = ... */
         if (strncmp(buf, "XSeed", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -4520,7 +4520,7 @@ rng_mct(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof Q; i += 2, j++) {
@@ -4542,7 +4542,7 @@ rng_mct(char *reqfn)
         /* b = ... */
         if (buf[0] == 'b') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             b = atoi(&buf[i]);
@@ -4555,7 +4555,7 @@ rng_mct(char *reqfn)
         /* XKey = ... */
         if (strncmp(buf, "XKey", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -4568,7 +4568,7 @@ rng_mct(char *reqfn)
         if (strncmp(buf, "XSeed", 5) == 0) {
             unsigned int k;
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -4719,7 +4719,7 @@ sha_test(char *reqfn)
         if (buf[0] == '[') {
             if (strncmp(&buf[1], "L ", 1) == 0) {
                 i = 2;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
                 MDlen = atoi(&buf[i]);
@@ -4730,7 +4730,7 @@ sha_test(char *reqfn)
         /* Len = Length of the Input Message Length  ... */
         if (strncmp(buf, "Len", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (msg) {
@@ -4754,7 +4754,7 @@ sha_test(char *reqfn)
         /* MSG = ... */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < msgLen; i += 2, j++) {
@@ -4778,7 +4778,7 @@ sha_test(char *reqfn)
         /* Seed = ... */
         if (strncmp(buf, "Seed", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof seed; i += 2, j++) {
@@ -4896,11 +4896,11 @@ hmac_test(char *reqfn)
     while (fgets(buf, bufSize, req) != NULL) {
         if (strncmp(buf, "Mac", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(expectedHMAC, 0, HASH_LENGTH_MAX);
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &expectedHMAC[j]);
             }
             if (memcmp(HMAC, expectedHMAC, TLen) != 0) {
@@ -4926,7 +4926,7 @@ hmac_test(char *reqfn)
         if (buf[0] == '[') {
             if (strncmp(&buf[1], "L ", 1) == 0) {
                 i = 2;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
                 /* HMACLen will get reused for Tlen */
@@ -4954,7 +4954,7 @@ hmac_test(char *reqfn)
         /* KLen = Length of the Input Secret Key ... */
         if (strncmp(buf, "Klen", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyLen = atoi(&buf[i]); /* in bytes */
@@ -4964,7 +4964,7 @@ hmac_test(char *reqfn)
         /* key = the secret key for the key to MAC */
         if (strncmp(buf, "Key", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < keyLen; i += 2, j++) {
@@ -4975,7 +4975,7 @@ hmac_test(char *reqfn)
         /* TLen = Length of the calculated HMAC */
         if (strncmp(buf, "Tlen", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             TLen = atoi(&buf[i]); /* in bytes */
@@ -4985,7 +4985,7 @@ hmac_test(char *reqfn)
         /* MSG = to HMAC always 128 bytes for these tests */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < msgLen; i += 2, j++) {
@@ -5265,7 +5265,7 @@ dsa_pqgver_test(char *reqfn)
         /* P = ... */
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.prime.len; i += 2, j++) {
@@ -5279,7 +5279,7 @@ dsa_pqgver_test(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.subPrime.len; i += 2, j++) {
@@ -5297,7 +5297,7 @@ dsa_pqgver_test(char *reqfn)
                 SECITEM_ZfreeItem(&pqg.base, PR_FALSE);
             }
             SECITEM_AllocItem(NULL, &pqg.base, pghSize);
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.base.len; i += 2, j++) {
@@ -5319,10 +5319,10 @@ dsa_pqgver_test(char *reqfn)
             i = 0;
         }
         if (i) {
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &vfy.seed.data[j]);
             }
             vfy.seed.len = j;
@@ -5347,10 +5347,10 @@ dsa_pqgver_test(char *reqfn)
         if ((strncmp(buf, "pseed", 5) == 0) ||
             (strncmp(buf, "qseed", 5) == 0)) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = vfy.seed.len; isxdigit(buf[i]); i += 2, j++) {
+            for (j = vfy.seed.len; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &vfy.seed.data[j]);
             }
             vfy.seed.len = j;
@@ -5360,7 +5360,7 @@ dsa_pqgver_test(char *reqfn)
         }
         if (strncmp(buf, "index", 4) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             hex_to_byteval(&buf[i], &vfy.h.data[0]);
@@ -5427,10 +5427,10 @@ dsa_pqgver_test(char *reqfn)
             SECStatus rv, result = SECFailure;
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &vfy.h.data[j]);
             }
             vfy.h.len = j;
@@ -5779,10 +5779,10 @@ dsa_siggen_test(char *reqfn)
             memset(sig, 0, sizeof sig);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             if (fips_hashBuf(hashType, hashBuf, msg, j) != SECSuccess) {
@@ -5924,7 +5924,7 @@ dsa_sigver_test(char *reqfn)
         /* P = ... */
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.prime.data, 0, pubkey.params.prime.len);
@@ -5939,7 +5939,7 @@ dsa_sigver_test(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.subPrime.data, 0, pubkey.params.subPrime.len);
@@ -5954,7 +5954,7 @@ dsa_sigver_test(char *reqfn)
         /* G = ... */
         if (buf[0] == 'G') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.base.data, 0, pubkey.params.base.len);
@@ -5977,10 +5977,10 @@ dsa_sigver_test(char *reqfn)
             }
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             if (fips_hashBuf(hashType, hashBuf, msg, j) != SECSuccess) {
@@ -5996,7 +5996,7 @@ dsa_sigver_test(char *reqfn)
         /* Y = ... */
         if (buf[0] == 'Y') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.publicValue.data, 0, pubkey.params.subPrime.len);
@@ -6012,7 +6012,7 @@ dsa_sigver_test(char *reqfn)
         if (buf[0] == 'R') {
             memset(sig, 0, sizeof sig);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pubkey.params.subPrime.len; i += 2, j++) {
@@ -6031,7 +6031,7 @@ dsa_sigver_test(char *reqfn)
             }
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = pubkey.params.subPrime.len;
@@ -6287,7 +6287,7 @@ rsa_siggen_test(char *reqfn)
         /* SHAAlg = ... */
         if (strncmp(buf, "SHAAlg", 6) == 0) {
             i = 6;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             /* set the SHA Algorithm */
@@ -6325,10 +6325,10 @@ rsa_siggen_test(char *reqfn)
             memset(rsa_computed_signature, 0, sizeof rsa_computed_signature);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]) && j < sizeof(msg); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof(msg); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             shaLength = fips_hashLen(shaAlg);
@@ -6455,7 +6455,7 @@ rsa_sigver_test(char *reqfn)
         /* n = ... modulus */
         if (buf[0] == 'n') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&rsaBlapiPublicKey.modulus.data[0],
@@ -6473,7 +6473,7 @@ rsa_sigver_test(char *reqfn)
         /* SHAAlg = ... */
         if (strncmp(buf, "SHAAlg", 6) == 0) {
             i = 6;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             /* set the SHA Algorithm */
@@ -6498,11 +6498,11 @@ rsa_sigver_test(char *reqfn)
             }
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             /* skip leading zero's */
-            while (isxdigit(buf[i])) {
+            while (isxdigit((unsigned char)buf[i])) {
                 hex_to_byteval(&buf[i], &t);
                 if (t == 0) {
                     i += 2;
@@ -6511,7 +6511,7 @@ rsa_sigver_test(char *reqfn)
             }
 
             /* get the exponent */
-            for (j = 0; isxdigit(buf[i]) && j < sizeof data; i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof data; i += 2, j++) {
                 hex_to_byteval(&buf[i], &data[j]);
             }
 
@@ -6540,11 +6540,11 @@ rsa_sigver_test(char *reqfn)
             memset(msg, 0, sizeof msg);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
 
-            for (j = 0; isxdigit(buf[i]) && j < sizeof msg; i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof msg; i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
 
@@ -6575,11 +6575,11 @@ rsa_sigver_test(char *reqfn)
 
             memset(signature, 0, sizeof(signature));
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
 
-            for (j = 0; isxdigit(buf[i]) && j < sizeof signature; i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof signature; i += 2, j++) {
                 hex_to_byteval(&buf[i], &signature[j]);
             }
 
@@ -6808,7 +6808,7 @@ tls(char *reqfn)
         /* pre_master_secret = ... */
         if (strncmp(buf, "pre_master_secret", 17) == 0) {
             i = 17;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pms_len; i += 2, j++) {
@@ -6820,7 +6820,7 @@ tls(char *reqfn)
         /* serverHello_random = ... */
         if (strncmp(buf, "serverHello_random", 18) == 0) {
             i = 18;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {
@@ -6832,7 +6832,7 @@ tls(char *reqfn)
         /* clientHello_random = ... */
         if (strncmp(buf, "clientHello_random", 18) == 0) {
             i = 18;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {
@@ -6844,7 +6844,7 @@ tls(char *reqfn)
         /* server_random = ... */
         if (strncmp(buf, "server_random", 13) == 0) {
             i = 13;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {
@@ -6860,7 +6860,7 @@ tls(char *reqfn)
             CK_OBJECT_HANDLE master_handle;
             CK_OBJECT_HANDLE fake_handle;
             i = 13;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {
@@ -7135,7 +7135,7 @@ ikev1(char *reqfn)
         /* Ni = ... */
         if (strncmp(buf, "Ni", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < Ni_len; i += 2, j++) {
@@ -7147,7 +7147,7 @@ ikev1(char *reqfn)
         /* Nr = ... */
         if (strncmp(buf, "Nr", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < Nr_len; i += 2, j++) {
@@ -7159,7 +7159,7 @@ ikev1(char *reqfn)
         /* CKYi = ... */
         if (strncmp(buf, "CKY_I", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < CKYi_len; i += 2, j++) {
@@ -7171,7 +7171,7 @@ ikev1(char *reqfn)
         /* CKYr = ... */
         if (strncmp(buf, "CKY_R", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < CKYr_len; i += 2, j++) {
@@ -7189,7 +7189,7 @@ ikev1(char *reqfn)
             CK_OBJECT_HANDLE skeyid_a_handle;
             CK_OBJECT_HANDLE skeyid_e_handle;
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < gxy_len; i += 2, j++) {
@@ -7541,7 +7541,7 @@ ikev1_psk(char *reqfn)
         /* Ni = ... */
         if (strncmp(buf, "Ni", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < Ni_len; i += 2, j++) {
@@ -7553,7 +7553,7 @@ ikev1_psk(char *reqfn)
         /* Nr = ... */
         if (strncmp(buf, "Nr", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < Nr_len; i += 2, j++) {
@@ -7565,7 +7565,7 @@ ikev1_psk(char *reqfn)
         /* CKYi = ... */
         if (strncmp(buf, "CKY_I", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < CKYi_len; i += 2, j++) {
@@ -7577,7 +7577,7 @@ ikev1_psk(char *reqfn)
         /* CKYr = ... */
         if (strncmp(buf, "CKY_R", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < CKYr_len; i += 2, j++) {
@@ -7589,7 +7589,7 @@ ikev1_psk(char *reqfn)
         /* g^xy = ... */
         if (strncmp(buf, "g^xy", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < gxy_len; i += 2, j++) {
@@ -7608,7 +7608,7 @@ ikev1_psk(char *reqfn)
             CK_OBJECT_HANDLE skeyid_a_handle;
             CK_OBJECT_HANDLE skeyid_e_handle;
             i = 14;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < psk_len; i += 2, j++) {
@@ -7980,7 +7980,7 @@ ikev2(char *reqfn)
         /* Ni = ... */
         if (strncmp(buf, "Ni", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < Ni_len; i += 2, j++) {
@@ -7992,7 +7992,7 @@ ikev2(char *reqfn)
         /* Nr = ... */
         if (strncmp(buf, "Nr", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < Nr_len; i += 2, j++) {
@@ -8004,7 +8004,7 @@ ikev2(char *reqfn)
         /* g^ir (new) = ... */
         if (strncmp(buf, "g^ir (new)", 10) == 0) {
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < gir_len; i += 2, j++) {
@@ -8016,7 +8016,7 @@ ikev2(char *reqfn)
         /* g^ir = ... */
         if (strncmp(buf, "g^ir", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < gir_len; i += 2, j++) {
@@ -8028,7 +8028,7 @@ ikev2(char *reqfn)
         /* SPIi = ... */
         if (strncmp(buf, "SPIi", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SPIi_len; i += 2, j++) {
@@ -8048,7 +8048,7 @@ ikev2(char *reqfn)
             CK_OBJECT_HANDLE dkm_handle;
             CK_OBJECT_HANDLE dkm_child_handle;
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SPIr_len; i += 2, j++) {
