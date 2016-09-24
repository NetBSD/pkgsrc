$NetBSD: patch-src_fe-common_fe-icb.c,v 1.1.2.2 2016/09/24 09:48:32 bsiegert Exp $

Add `void MODULENAME ## _abicheck(int *version)' function required by
irssi>=0.8.18.

--- src/fe-common/fe-icb.c.orig	2011-06-13 18:10:41.000000000 +0000
+++ src/fe-common/fe-icb.c
@@ -531,3 +531,11 @@ void fe_icb_deinit(void)
 
 	signal_remove("server add fill", (SIGNAL_FUNC) sig_server_add_fill);
 }
+
+#ifdef IRSSI_ABI_VERSION
+void
+fe_icb_abicheck(int * version)
+{
+	*version = IRSSI_ABI_VERSION;
+}
+#endif
