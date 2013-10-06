$NetBSD: patch-plugins_symbol-db_anjuta-tags_c.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/c.c.orig	2013-09-29 15:17:23.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/c.c
@@ -622,7 +622,7 @@ static const char *keywordString (const 
 	return name;
 }
 
-static void __unused__ pt (tokenInfo *const token)
+static void  pt (tokenInfo *const token)
 {
 	if (isType (token, TOKEN_NAME))
 		printf ("type: %-12s: %-13s   line: %lu\n",
@@ -637,7 +637,7 @@ static void __unused__ pt (tokenInfo *co
 			tokenString (token->type), token->lineNumber);
 }
 
-static void __unused__ ps (statementInfo *const st)
+static void  ps (statementInfo *const st)
 {
 	unsigned int i;
 	printf ("scope: %s   decl: %s   gotName: %s   gotParenName: %s isPointer: %s\n",
