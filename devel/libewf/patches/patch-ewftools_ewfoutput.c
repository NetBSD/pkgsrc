$NetBSD: patch-ewftools_ewfoutput.c,v 1.1 2024/12/14 08:32:35 wiz Exp $

Compatibility with recent openssl.

--- ewftools/ewfoutput.c.orig	2024-12-14 08:30:37.221675021 +0000
+++ ewftools/ewfoutput.c
@@ -188,7 +188,7 @@ void ewfoutput_version_detailed_fprint(
 	fprintf(
 	 stream,
 	 " (libcrypto %s)",
-	 SHLIB_VERSION_NUMBER );
+	 OPENSSL_VERSION_STR );
 #endif
 #endif
 
