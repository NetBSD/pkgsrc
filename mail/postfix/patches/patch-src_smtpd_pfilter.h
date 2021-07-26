$NetBSD: patch-src_smtpd_pfilter.h,v 1.1 2021/07/26 15:38:10 taca Exp $

Add blocklist(3) support.

--- src/smtpd/pfilter.h.orig	2021-07-26 14:19:32.266525421 +0000
+++ src/smtpd/pfilter.h
@@ -0,0 +1,13 @@
+
+#if defined(HAVE_BLOCKLIST) || defined(HAVE_BLACKLIST)
+
+void pfilter_notify(int, int);
+
+#ifdef HAVE_BLACKLIST
+#define	blocklist			blacklist
+#define blocklist_open()		blacklist_open()
+#define	blocklist_r(a, b, c, d)		blacklist_r((a), (b), (c), (d))
+#define blocklist_close(a)		blacklist_close((a))
+#endif
+
+#endif
