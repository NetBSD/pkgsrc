$NetBSD: patch-zathura_database-plain.c,v 1.2 2019/03/06 17:02:20 leot Exp $

Correctly define _POSIX_SOURCE and bump _XOPEN_SOURCE.

--- zathura/database-plain.c.orig	2018-12-22 15:33:23.000000000 +0000
+++ zathura/database-plain.c
@@ -1,7 +1,7 @@
 /* SPDX-License-Identifier: Zlib */
 
-#define _POSIX_SOURCE
-#define _XOPEN_SOURCE 500
+#define _POSIX_SOURCE 1
+#define _XOPEN_SOURCE 700
 
 #include <glib.h>
 #include <stdlib.h>
