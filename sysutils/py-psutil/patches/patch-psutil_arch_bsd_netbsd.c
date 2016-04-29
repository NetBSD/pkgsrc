$NetBSD: patch-psutil_arch_bsd_netbsd.c,v 1.4 2016/04/29 15:33:57 prlw1 Exp $

Declare warn().

https://github.com/giampaolo/psutil/pull/812

--- psutil/arch/bsd/netbsd.c.orig	2016-03-12 17:12:23.000000000 +0000
+++ psutil/arch/bsd/netbsd.c
@@ -13,6 +13,7 @@
 
 #include <Python.h>
 #include <assert.h>
+#include <err.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <stdio.h>
