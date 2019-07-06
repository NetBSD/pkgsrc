$NetBSD: patch-qw_source_master.c,v 1.2 2019/07/06 22:53:25 nia Exp $

Don't use IN_PKTINFO on NetBSD.

--- qw/source/master.c.orig	2013-01-23 03:10:55.000000000 +0000
+++ qw/source/master.c
@@ -73,7 +73,7 @@
 static void __attribute__ ((format (printf, 1, 2)))
 ma_log (const char *fmt, ...);
 
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && !defined(__NetBSD__)
 static int
 qf_sendmsg (int sock, void *data, size_t len, struct msghdr *msghdr)
 {
