$NetBSD: patch-client-src_sendsize.c,v 1.1 2012/07/30 07:21:11 sbd Exp $

Add dump-use-snapshot code.

--- client-src/sendsize.c.orig	2012-02-21 11:36:41.000000000 +0000
+++ client-src/sendsize.c
@@ -1492,6 +1492,9 @@ getsize_dump(
 	dumpkeys = vstralloc(level_str,
 			     PARAM_DUMP_ESTIMATE,
 			     PARAM_HONOR_NODUMP,
+#  ifdef HAVE_DUMP_SNAPSHOT
+			     "X",
+#  endif
 			     "s", "f", NULL);
 
 #  ifdef HAVE_DUMP_ESTIMATE
