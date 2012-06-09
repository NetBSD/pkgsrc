$NetBSD: patch-lib_kadm5_srv_svr__principal.c,v 1.1.2.2 2012/06/09 15:34:09 tron Exp $

Fix for CVE-2012-1013 from:
 https://github.com/krb5/krb5/commit/ca2909440015d33be42e77d1955194963d8c0955

--- lib/kadm5/srv/svr_principal.c.orig	2012-06-06 17:25:54.168189200 +0000
+++ lib/kadm5/srv/svr_principal.c
@@ -196,7 +196,7 @@ check_1_6_dummy(kadm5_principal_ent_t en
     char *password = *passptr;
 
     /* Old-style randkey operations disallowed tickets to start. */
-    if (!(mask & KADM5_ATTRIBUTES) ||
+    if (password == NULL || !(mask & KADM5_ATTRIBUTES) ||
         !(entry->attributes & KRB5_KDB_DISALLOW_ALL_TIX))
         return;
 
