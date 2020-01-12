$NetBSD: patch-qsmtpd_antispam.c,v 1.1 2020/01/12 23:03:28 joerg Exp $

Find LOCK_* on NetBSD.

--- qsmtpd/antispam.c.orig	2020-01-11 21:21:57.002915885 +0000
+++ qsmtpd/antispam.c
@@ -1,6 +1,7 @@
 /** \file antispam.c
  \brief several helper functions for spam filters
  */
+#define _NETBSD_SOURCE
 
 #include <qsmtpd/antispam.h>
 
