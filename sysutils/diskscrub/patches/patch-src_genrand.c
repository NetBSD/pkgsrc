$NetBSD: patch-src_genrand.c,v 1.1 2013/12/15 19:44:39 joerg Exp $

--- src/genrand.c.orig	2013-12-15 13:03:04.000000000 +0000
+++ src/genrand.c
@@ -106,7 +106,7 @@ genrandraw(unsigned char *buf, int bufle
                 buf[n] = result;
             }
 #endif
-            return;
+            return 0;
         }
     }
 
