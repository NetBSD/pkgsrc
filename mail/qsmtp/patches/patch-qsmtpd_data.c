$NetBSD: patch-qsmtpd_data.c,v 1.1 2020/01/12 23:03:28 joerg Exp $

Find LOCK_* on NetBSD.

--- qsmtpd/data.c.orig	2020-01-11 21:11:14.750764277 +0000
+++ qsmtpd/data.c
@@ -4,6 +4,7 @@
 
 #define _STD_SOURCE
 #define _GNU_SOURCE
+#define _NETBSD_SOURCE
 #include <qsmtpd/qsdata.h>
 
 #include <fmt.h>
