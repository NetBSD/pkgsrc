$NetBSD: patch-lib_cfsetup.c,v 1.1 2012/12/15 08:10:59 marino Exp $

Fix "error: variable 'va' set but not used" errors on gcc4.6+

--- lib/cfsetup.c.orig	2008-11-13 05:59:53.000000000 +0000
+++ lib/cfsetup.c
@@ -3026,7 +3026,6 @@ rcf_fix_addrlist(struct cf_list *head, s
 {
 	struct rc_addrlist *new_head = 0, *new = 0, **lastap;
 	struct cf_list *n, *m;
-	rc_vchar_t va;
 	struct rc_addrlist *al = 0;
 	char port[10];
 	int nport;
@@ -3060,8 +3059,6 @@ rcf_fix_addrlist(struct cf_list *head, s
 				    "at %d in %s\n", m->lineno, m->file);
 				goto err;
 			}
-			va.l = strlen(n->d.str);
-			va.v = n->d.str;
 			error = rcs_getaddrlist(n->d.str, port, RCT_ADDR_FQDN, &al);
 			if (error) {
 				plog(PLOG_INTERR, PLOGLOC, NULL,
