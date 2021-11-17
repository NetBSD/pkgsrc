$NetBSD: patch-kdc_krb5tgs.c,v 1.1 2021/11/17 08:46:02 wiz Exp $

Fix CVE-2021-3671
Patch from samba
https://gitlab.com/samba-team/samba/-/commit/0cb4b939f192376bf5e33637863a91a20f74c5a5
via https://github.com/heimdal/heimdal/issues/849

--- kdc/krb5tgs.c.orig	2019-06-07 06:21:39.000000000 +0000
+++ kdc/krb5tgs.c
@@ -1660,6 +1660,11 @@ tgs_build_reply(krb5_context context,
 
 	s = &adtkt.cname;
 	r = adtkt.crealm;
+    } else if (s == NULL) {
+	ret = KRB5KDC_ERR_S_PRINCIPAL_UNKNOWN;
+	krb5_set_error_message(context, ret, "No server in request");
+	goto out;
+
     }
 
     _krb5_principalname2krb5_principal(context, &sp, *s, r);
