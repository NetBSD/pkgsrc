$NetBSD: patch-src_core_icb-core.c,v 1.1 2016/08/14 21:15:12 leot Exp $

Add `void MODULENAME ## _abicheck(int *version)' function required by
irssi>=0.8.18.

--- src/core/icb-core.c.orig	2002-05-20 04:17:44.000000000 +0000
+++ src/core/icb-core.c
@@ -156,3 +156,11 @@ void icb_core_deinit(void)
 	signal_emit("chat protocol deinit", 1, chat_protocol_find("ICB"));
 	chat_protocol_unregister("ICB");
 }
+
+#ifdef IRSSI_ABI_VERSION
+void
+icb_core_abicheck(int * version)
+{
+	*version = IRSSI_ABI_VERSION;
+}
+#endif
