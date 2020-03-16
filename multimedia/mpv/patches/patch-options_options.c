$NetBSD: patch-options_options.c,v 1.3 2020/03/16 20:31:44 nia Exp $

Workaround for frame drops with a high default blocksize.
Can be removed when we are blk_ms=4 everywhere.

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
