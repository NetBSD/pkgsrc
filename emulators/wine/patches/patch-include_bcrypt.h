$NetBSD: patch-include_bcrypt.h,v 1.1 2020/05/22 17:44:42 nia Exp $

Use parantheses around expression to prevent gcc from complaining
when using -D_FORTIFY_SOURCE=2 flag

--- include/bcrypt.h.orig	2019-08-14 15:05:32.929387224 +0000
+++ include/bcrypt.h
@@ -91,7 +91,7 @@ typedef LONG NTSTATUS;
 #define BCRYPT_CHAIN_MODE_ECB       (const WCHAR []){'C','h','a','i','n','i','n','g','M','o','d','e','E','C','B',0}
 #define BCRYPT_CHAIN_MODE_CFB       (const WCHAR []){'C','h','a','i','n','i','n','g','M','o','d','e','C','F','B',0}
 #define BCRYPT_CHAIN_MODE_CCM       (const WCHAR []){'C','h','a','i','n','i','n','g','M','o','d','e','C','C','M',0}
-#define BCRYPT_CHAIN_MODE_GCM       (const WCHAR []){'C','h','a','i','n','i','n','g','M','o','d','e','G','C','M',0}
+#define BCRYPT_CHAIN_MODE_GCM       ((const WCHAR []){'C','h','a','i','n','i','n','g','M','o','d','e','G','C','M',0})
 
 #define BCRYPT_ECDSA_PUBLIC_P256_MAGIC  0x31534345
 #define BCRYPT_ECDSA_PRIVATE_P256_MAGIC 0x32534345
