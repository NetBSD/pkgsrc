$NetBSD: patch-plugins_preauth_pkinit_pkinit__crypto.h,v 1.1 2026/04/07 14:12:48 tnn Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f

--- plugins/preauth/pkinit/pkinit_crypto.h.orig	2026-04-07 12:41:48.863872949 +0000
+++ plugins/preauth/pkinit/pkinit_crypto.h
@@ -440,7 +440,7 @@ krb5_error_code crypto_load_cas_and_crls
 		    defines the storage type (file, directory, etc) */
 	int catype,					/* IN
 		    defines the ca type (anchor, intermediate, crls) */
-	char *id);					/* IN
+	const char *id);					/* IN
 		    defines the location (filename, directory name, etc) */
 
 /*
