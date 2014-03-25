$NetBSD: patch-src_compat_hsearch__r.c,v 1.1 2014/03/25 23:06:07 asau Exp $

--- src/compat/hsearch_r.c.orig	2009-12-16 15:18:51.000000000 +0000
+++ src/compat/hsearch_r.c
@@ -18,7 +18,7 @@
    Boston, MA 02111-1307, USA.  */
 
 #include <errno.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #define __USE_GNU
