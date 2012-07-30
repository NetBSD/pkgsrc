$NetBSD: patch-client-src_sendbackup-dump.c,v 1.1 2012/07/30 07:21:11 sbd Exp $

Add dump-use-snapshot code.

--- client-src/sendbackup-dump.c.orig	2012-02-21 11:36:41.000000000 +0000
+++ client-src/sendbackup-dump.c
@@ -391,6 +391,9 @@ start_backup(
 			     FREEBSD_EXTRA_KEYS,
 			     "s",
 			     PARAM_HONOR_NODUMP,
+#ifdef HAVE_DUMP_SNAPSHOT
+			     "X",
+#endif
 			     "f",
 			     NULL);
 
