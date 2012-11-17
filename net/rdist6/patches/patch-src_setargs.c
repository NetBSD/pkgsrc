$NetBSD: patch-src_setargs.c,v 1.1 2012/11/17 22:48:50 markd Exp $

MAXUSERENVIRON is not set anywhere and not needed anymore.

--- src/setargs.c.orig	2012-09-26 15:27:57.000000000 +0000
+++ src/setargs.c
@@ -70,7 +70,7 @@ setargs_settup(int argc, char **argv, ch
 	for (i = 0; envp[i] != NULL; i++)
 		continue;
 	UserEnviron = xmalloc(sizeof(*UserEnviron) * ++i);
-	for (i = 0; i < MAXUSERENVIRON && envp[i] != NULL; i++)
+	for (i = 0; envp[i] != NULL; i++)
 		UserEnviron[i] = xstrdup(envp[i]);
 	UserEnviron[i] = NULL;
 	environ = UserEnviron;
