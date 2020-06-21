$NetBSD: patch-ntpd_ntp__control.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/ntp_control.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpd/ntp_control.c
@@ -1910,7 +1910,11 @@ ctl_putsys(
 	)
 {
 	l_fp tmp;
+#ifndef HAVE_UNAME
 	char str[256];
+#else
+	char str[sizeof utsnamebuf.sysname + sizeof utsnamebuf.release];
+#endif
 	u_int u;
 	double kb;
 	double dtemp;
