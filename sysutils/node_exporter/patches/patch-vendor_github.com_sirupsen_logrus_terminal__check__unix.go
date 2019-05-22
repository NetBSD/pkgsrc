$NetBSD: patch-vendor_github.com_sirupsen_logrus_terminal__check__unix.go,v 1.1 2019/05/22 11:54:06 jperkin Exp $

Fix SunOS build.

--- vendor/github.com/sirupsen/logrus/terminal_check_unix.go.orig	2019-05-09 18:19:12.000000000 +0000
+++ vendor/github.com/sirupsen/logrus/terminal_check_unix.go
@@ -1,4 +1,4 @@
-// +build linux aix
+// +build linux aix solaris
 
 package logrus
 
