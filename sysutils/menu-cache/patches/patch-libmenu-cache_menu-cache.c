$NetBSD: patch-libmenu-cache_menu-cache.c,v 1.1 2018/05/25 14:32:18 youri Exp $

Fix for SunOS.

--- libmenu-cache/menu-cache.c.orig	2017-11-02 17:51:23.000000000 +0000
+++ libmenu-cache/menu-cache.c
@@ -29,6 +29,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
