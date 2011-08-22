$NetBSD: patch-ext_standard_php__crypt__r.c,v 1.1 2011/08/22 09:40:00 taca Exp $

Fix for MD5 password encryption problem (r315218 from PHP repository).

--- ext/standard/php_crypt_r.c.orig	2011-08-07 16:10:34.000000000 +0000
+++ ext/standard/php_crypt_r.c
@@ -382,7 +382,7 @@ char * php_md5_crypt_r(const char *pw, c
 	/* Now make the output string */
 	memcpy(passwd, MD5_MAGIC, MD5_MAGIC_LEN);
 	strlcpy(passwd + MD5_MAGIC_LEN, sp, sl + 1);
-	strlcat(passwd, "$", 1);
+	strcat(passwd, "$");
 
 	PHP_MD5Final(final, &ctx);
 
