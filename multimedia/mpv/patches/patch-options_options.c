$NetBSD: patch-options_options.c,v 1.2 2019/12/28 17:20:33 leot Exp $

autosync=0 requires "a perfect audio delay measurement".

NetBSD does not provide this. Setting it to 30 (as recommended in
mpv's man page) fixes frame drops in NetBSD.

PR kern/54230

--- options/options.c.orig	2019-12-28 11:07:07.000000000 +0000
+++ options/options.c
@@ -992,6 +992,10 @@ static const struct MPOpts mp_default_op
     },
 
     .cuda_device = -1,
+
+#ifdef __NetBSD__
+    .autosync = 30,
+#endif
 };
 
 const struct m_sub_options mp_opt_root = {
