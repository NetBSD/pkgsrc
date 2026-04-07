$NetBSD: patch-plugins_preauth_pkinit_pkinit__matching.c,v 1.1 2026/04/07 14:12:48 tnn Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f

--- plugins/preauth/pkinit/pkinit_matching.c.orig	2026-04-07 12:42:54.690188776 +0000
+++ plugins/preauth/pkinit/pkinit_matching.c
@@ -262,7 +262,7 @@ parse_rule_component(krb5_context contex
     char err_buf[128];
     int ret;
     struct keyword_desc *kw, *nextkw;
-    char *nk;
+    const char *nk;
     int found_next_kw = 0;
     char *value = NULL;
     size_t len;
