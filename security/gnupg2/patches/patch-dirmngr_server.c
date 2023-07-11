$NetBSD: patch-dirmngr_server.c,v 1.3 2023/07/11 08:40:45 tnn Exp $

From: NIIBE Yutaka <gniibe@fsij.org>
Date: Wed, 5 Jul 2023 00:29:54 +0000 (+0900)
Subject: dirmngr: Enable the call of ks_ldap_help_variables when USE_LDAP.
X-Git-Url: http://git.gnupg.org/cgi-bin/gitweb.cgi?p=gnupg.git;a=commitdiff_plain;h=dc13361524c1477b2106c7385f2059f9ea111b84;hp=2c5a93e66e3e0f15b17e5dc92b503b708ce9b58f

dirmngr: Enable the call of ks_ldap_help_variables when USE_LDAP.

* dirmngr/server.c [USE_LDAP] (cmd_ad_query): Conditionalize.

--- dirmngr/server.c.orig	2023-06-30 08:53:58.000000000 +0000
+++ dirmngr/server.c
@@ -2776,7 +2776,9 @@ cmd_ad_query (assuan_context_t ctx, char
 
   if (opt_help)
     {
+#if USE_LDAP
       ks_ldap_help_variables (ctrl);
+#endif
       err = 0;
       goto leave;
     }
