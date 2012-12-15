$NetBSD: patch-lib_if__pfkeyv2.c,v 1.1 2012/12/15 08:10:59 marino Exp $

Fix "error: variable 'keytype' set but not used" errors on gcc4.6+

--- lib/if_pfkeyv2.c.orig	2008-04-25 06:02:56.000000000 +0000
+++ lib/if_pfkeyv2.c
@@ -1139,19 +1139,16 @@ rcpfk_set_sadbkey(rc_vchar_t **msg, stru
 {
 	rc_vchar_t *buf;
 	struct sadb_key *p;
-	int keytype;
 	size_t keylen;
 	caddr_t key;
 	int len, prevlen, extlen;
 
 	switch (type) {
 	case SADB_EXT_KEY_AUTH:
-		keytype = rct2pfk_authtype(rc->authtype);
 		key = rc->authkey;
 		keylen = rc->authkeylen;
 		break;
 	case SADB_EXT_KEY_ENCRYPT:
-		keytype = rct2pfk_enctype(rc->enctype);
 		key = rc->enckey;
 		keylen = rc->enckeylen;
 		break;
