$NetBSD: patch-options_options.c,v 1.1 2019/06/04 13:55:43 nia Exp $

autosync=0 requires "a perfect audio delay measurement".

NetBSD does not provide this. Setting it to 30 (as recommended in
mpv's man page) fixes frame drops in NetBSD.

PR kern/54230
--- options/options.c.orig	2018-10-02 19:03:41.000000000 +0000
+++ options/options.c
@@ -972,6 +972,10 @@ const struct MPOpts mp_default_opts = {
     },
 
     .cuda_device = -1,
+
+#ifdef __NetBSD__
+    .autosync = 30,
+#endif
 };
 
 #endif /* MPLAYER_CFG_MPLAYER_H */
