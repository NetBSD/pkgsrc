$NetBSD: patch-qw_source_master.c,v 1.1 2013/08/31 14:49:08 joerg Exp $

--- qw/source/master.c.orig	2013-08-31 13:54:32.000000000 +0000
+++ qw/source/master.c
@@ -76,7 +76,7 @@ static __attribute__ ((unused)) const ch
 static void __attribute__ ((format (printf, 1, 2)))
 ma_log (const char *fmt, ...);
 
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && !defined(__NetBSD__)
 static int
 qf_sendmsg (int sock, void *data, size_t len, struct msghdr *msghdr)
 {
