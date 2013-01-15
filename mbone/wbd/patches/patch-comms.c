$NetBSD: patch-comms.c,v 1.1 2013/01/15 15:22:54 joerg Exp $

--- comms.c.orig	2013-01-11 15:02:20.000000000 +0000
+++ comms.c
@@ -1450,7 +1450,7 @@ int ParseDrawMsg (struct pk_draw_msg *Dr
         return 0;
 
     if (ntohl(DrawMsg->page_num) < 1)
-        return;
+        return 0;
 
 	if ((ntohl(DrawMsg->page_num))!=(PageCurrent()->page_number)) 
 		PageSet ((ntohl(DrawMsg->page_num)), (ntohl(DrawMsg->page_ip)));
