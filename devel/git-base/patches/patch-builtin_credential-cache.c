$NetBSD: patch-builtin_credential-cache.c,v 1.1 2024/10/15 06:22:17 nia Exp $

Sync the prototype with reality to fix non-unix-sockets builds
(needed for old Darwin)

--- builtin/credential-cache.c.orig	2024-10-15 06:20:35.585417706 +0000
+++ builtin/credential-cache.c
@@ -189,7 +189,10 @@ int cmd_credential_cache(int argc,
 
 #else
 
-int cmd_credential_cache(int argc, const char **argv, const char *prefix)
+int cmd_credential_cache(int argc,
+			 const char **argv,
+			 const char *prefix,
+			 struct repository *repo UNUSED)
 {
 	const char * const usage[] = {
 		"git credential-cache [options] <action>",
