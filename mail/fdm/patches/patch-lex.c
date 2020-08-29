$NetBSD: patch-lex.c,v 1.1 2020/08/29 13:43:54 leot Exp $

Add support for OAUTHBEARER (OAuth 2.0 bearer tokens, as documented by
RFC 7628) for IMAP.

Patch shared upstream via:

 <https://github.com/nicm/fdm/pull/84>

--- lex.c.orig	2019-02-12 22:08:26.000000000 +0000
+++ lex.c
@@ -157,6 +157,7 @@ static const struct token tokens[] = {
 	{ "no-verify", TOKNOVERIFY },
 	{ "none", TOKNONE },
 	{ "not", TOKNOT },
+	{ "oauthbearer", TOKOAUTHBEARER },
 	{ "old-only", TOKOLDONLY },
 	{ "or", TOKOR },
 	{ "parallel-accounts", TOKPARALLELACCOUNTS },
