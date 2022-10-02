$NetBSD: patch-src_pm_hydra_mpl_src_sock_mpl__sockaddr.c,v 1.1 2022/10/02 15:35:24 he Exp $

Conditionalize use of AI_V4MAPPED (not present on NetBSD).

--- src/pm/hydra/mpl/src/sock/mpl_sockaddr.c.orig	2021-12-16 16:59:29.000000000 +0000
+++ src/pm/hydra/mpl/src/sock/mpl_sockaddr.c
@@ -98,7 +98,9 @@ int MPL_get_sockaddr(const char *s_hostn
     ai_hint.ai_family = af_type;
     ai_hint.ai_socktype = SOCK_STREAM;
     ai_hint.ai_protocol = IPPROTO_TCP;
+#ifdef AI_V4MAPPED
     ai_hint.ai_flags = AI_V4MAPPED;
+#endif
     ret = getaddrinfo(s_hostname, NULL, &ai_hint, &ai_list);
     if (ret) {
         return ret;
