$NetBSD: patch-zathura_database-plain.c,v 1.1 2016/02/17 09:43:24 leot Exp $

Correctly define _POSIX_SOURCE and bump _XOPEN_SOURCE.

--- zathura/database-plain.c.orig	2015-12-21 10:19:18.000000000 +0000
+++ zathura/database-plain.c
@@ -1,7 +1,7 @@
 /* See LICENSE file for license and copyright information */
 
-#define _POSIX_SOURCE
-#define _XOPEN_SOURCE 500
+#define _POSIX_SOURCE 1
+#define _XOPEN_SOURCE 700
 
 #include <glib.h>
 #include <stdlib.h>
