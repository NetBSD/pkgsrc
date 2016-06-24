$NetBSD: patch-libfreerdp-core_crypto.c,v 1.1 2016/06/24 16:39:58 he Exp $

Ensure proper operator order so we don't scribble randomly on other memory.

--- libfreerdp-core/crypto.c.orig	2013-01-02 21:46:59.000000000 +0000
+++ libfreerdp-core/crypto.c
@@ -443,7 +443,7 @@ char** crypto_cert_subject_alt_name(X509
 		{
 			length = ASN1_STRING_to_UTF8(&string, subject_alt_name->d.dNSName);
 			strings[*count] = (char*) string;
-			*lengths[*count] = length;
+			(*lengths)[*count] = length;
 			(*count)++;
 		}
 	}
