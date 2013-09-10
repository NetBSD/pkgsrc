$NetBSD: patch-choparp.c,v 1.1 2013/09/10 14:27:18 joerg Exp $

--- choparp.c.orig	2013-09-09 22:24:29.000000000 +0000
+++ choparp.c
@@ -36,6 +36,7 @@
 
 */
 
+#include <inttypes.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -354,7 +355,7 @@ atoip(char *buf, u_int32_t *ip_addr){
 	*ip_addr = (i0 << 24) + (i1 << 16) + (i2 << 8) + i3;
 	return(0);
     }
-    if (sscanf(buf, "0x%lx", ip_addr) == 1)
+    if (sscanf(buf, "0x%" PRIx32, ip_addr) == 1)
 	return(0);
 
     return(-1);	
