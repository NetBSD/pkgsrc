$NetBSD: patch-master_page.c,v 1.1 2015/02/23 18:19:34 joerg Exp $

--- master/page.c.orig	2015-02-23 13:01:40.000000000 +0000
+++ master/page.c
@@ -73,7 +73,7 @@ page(char *argv[], struct sockaddr_in *s
      *	from the lower 4 bits of the time.  
      */
 
-    snprintf(new->id, sizeof(new->id), "%05ld",(now & 9999L));
+    snprintf(new->id, sizeof(new->id), "%05ld",(long)(now & 9999L));
     sendit(misc, sin, "%c%c%c%s", ESC, PAGE, ACK, new->id);
 
     /* figure out host name */
