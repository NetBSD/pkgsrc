$NetBSD: patch-spmd_spmd__pfkey.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Remove unused.

--- spmd/spmd_pfkey.c.orig	2008-07-11 18:35:46.000000000 -0400
+++ spmd/spmd_pfkey.c	2018-05-28 19:45:26.942125292 -0400
@@ -326,7 +326,6 @@
 spmd_nonfqdn_sp_add(struct rcf_selector *sl)
 {
 	struct rcf_policy *pl = NULL;
-	struct rcf_ipsec *ips = NULL;
 	struct rc_addrlist *al = NULL;
 	struct rc_addrlist *ipal = NULL;
 	struct rc_addrlist *ipal_tmp = NULL;
@@ -373,7 +372,6 @@
 	if (!sl->pl->ips) {
 		return -1;
 	}
-	ips = sl->pl->ips;
 
 	/* check rcf_ipsec{} sa_* set or NULL */
 	if (set_satype(sl, rc)<0) {
