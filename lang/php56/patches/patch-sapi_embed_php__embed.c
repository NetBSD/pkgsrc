$NetBSD: patch-sapi_embed_php__embed.c,v 1.1.2.2 2026/11/09 08:24:27 maya Exp $

Remove one warning.

--- sapi/embed/php_embed.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ sapi/embed/php_embed.c
@@ -108,7 +108,7 @@ static int php_embed_startup(sapi_module
 	return SUCCESS;
 }
 
-extern EMBED_SAPI_API sapi_module_struct php_embed_module = {
+EMBED_SAPI_API sapi_module_struct php_embed_module = {
 	"embed",                       /* name */
 	"PHP Embedded Library",        /* pretty name */
 	
