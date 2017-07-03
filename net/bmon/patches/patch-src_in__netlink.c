$NetBSD: patch-src_in__netlink.c,v 1.1 2017/07/03 11:53:11 wiedi Exp $

no netlink support on SunOS
--- src/in_netlink.c.orig	2015-07-25 09:03:55.000000000 +0000
+++ src/in_netlink.c
@@ -31,7 +31,7 @@
 #include <bmon/input.h>
 #include <bmon/utils.h>
 
-#ifndef SYS_BSD
+#if !defined(SYS_BSD) && !defined(__sun)
 
 static int c_notc = 0;
 static struct element_group *grp;
