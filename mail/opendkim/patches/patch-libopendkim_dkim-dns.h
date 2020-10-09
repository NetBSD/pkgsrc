$NetBSD$

- https://github.com/trusteddomainproject/OpenDKIM/pull/99

--- libopendkim/dkim-dns.h.orig	2020-10-09 02:33:21.947346707 +0000
+++ libopendkim/dkim-dns.h
@@ -13,7 +13,6 @@
 extern int dkim_res_cancel __P((void *, void *));
 extern void dkim_res_close __P((void *));
 extern int dkim_res_init __P((void **));
-extern int dkim_res_nslist __P((void *, const char *));
 extern int dkim_res_query __P((void *, int, unsigned char *, unsigned char *,
                                size_t, void **));
 extern int dkim_res_waitreply __P((void *, void *, struct timeval *,
