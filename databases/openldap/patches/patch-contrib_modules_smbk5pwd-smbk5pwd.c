$NetBSD: patch-contrib_modules_smbk5pwd-smbk5pwd.c,v 1.1 2016/10/30 05:04:09 manu Exp $

Submitted upstream as ITS#8525
http://www.openldap.org/its/index.cgi/Incoming?id=8525

From 1aad89bbdd1f58f3b2d794067cc8c4a60876f584 Mon Sep 17 00:00:00 2001
From: Emmanuel Dreyfus <manu@netbsd.org>
Date: Sun, 30 Oct 2016 05:34:58 +0100
Subject: [PATCH] Use newer DES API so that smbk5pwd loads with newer OpenSSL

OpenSSL removed old DES API which used des_* functions.
https://github.com/openssl/openssl/commit/24956ca00f014a917fb181a8abc39b349f3f316f

In order to link with libcrypto from recent OpenSSL releases, we need
to replace the older API des_* functions by the newer API DES_* functions.

Signed-off-by: Emmanuel Dreyfus <manu@netbsd.org>
---
 contrib/slapd-modules/smbk5pwd/smbk5pwd.c | 10 +++++-----
 1 file changed, 5 insertions(+), 5 deletions(-)

diff --git contrib/slapd-modules/smbk5pwd/smbk5pwd.c contrib/slapd-modules/smbk5pwd/smbk5pwd.c
index bec5e1b..97e0055 100644
--- contrib/slapd-modules/smbk5pwd/smbk5pwd.c
+++ contrib/slapd-modules/smbk5pwd/smbk5pwd.c
@@ -154,7 +154,7 @@ static void lmPasswd_to_key(
 	k[7] = ((lpw[6]&0x7F)<<1);
 
 #ifdef HAVE_OPENSSL
-	des_set_odd_parity( key );
+	DES_set_odd_parity( key );
 #endif
 }
 
@@ -210,12 +210,12 @@ static void lmhash(
 	des_set_key( &ctx, key );
 	des_encrypt( &ctx, sizeof(key), hbuf[1], StdText );
 #elif defined(HAVE_OPENSSL)
-	des_set_key_unchecked( &key, schedule );
-	des_ecb_encrypt( &StdText, &hbuf[0], schedule , DES_ENCRYPT );
+	DES_set_key_unchecked( &key, &schedule );
+	DES_ecb_encrypt( &StdText, &hbuf[0], &schedule , DES_ENCRYPT );
 
 	lmPasswd_to_key( &UcasePassword[7], &key );
-	des_set_key_unchecked( &key, schedule );
-	des_ecb_encrypt( &StdText, &hbuf[1], schedule , DES_ENCRYPT );
+	DES_set_key_unchecked( &key, &schedule );
+	DES_ecb_encrypt( &StdText, &hbuf[1], &schedule , DES_ENCRYPT );
 #endif
 
 	hexify( (char *)hbuf, hash );
-- 
2.3.2

