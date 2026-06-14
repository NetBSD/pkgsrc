$NetBSD: patch-libmb_mbmenu.h,v 1.1 2026/06/14 19:11:54 nia Exp $

Include appropriate header for index(3) to avoid implicit
function declarations.

--- libmb/mbmenu.h.orig	2026-06-14 19:03:57.641819988 +0000
+++ libmb/mbmenu.h
@@ -26,6 +26,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <dirent.h>
