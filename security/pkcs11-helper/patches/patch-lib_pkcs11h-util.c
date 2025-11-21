$NetBSD: patch-lib_pkcs11h-util.c,v 1.1.2.2 2025/11/21 08:43:43 bsiegert Exp $

Fix ctype usage.

--- lib/pkcs11h-util.c.orig	2025-11-19 08:30:09.777808327 +0000
+++ lib/pkcs11h-util.c
@@ -179,7 +179,7 @@ _pkcs11h_util_escapeString (
 
 	while (*s != '\x0') {
 
-		if (*s == '\\' || strchr (invalid_chars, (unsigned char)*s) || !isgraph (*s)) {
+		if (*s == '\\' || strchr (invalid_chars, (unsigned char)*s) || !isgraph ((unsigned char)*s)) {
 			if (t != NULL) {
 				if (n+4 > *max) {
 					rv = CKR_ATTRIBUTE_VALUE_INVALID;
