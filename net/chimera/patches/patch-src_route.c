$NetBSD: patch-src_route.c,v 1.1 2012/11/19 02:58:41 joerg Exp $

--- src/route.c.orig	2012-11-18 16:29:00.000000000 +0000
+++ src/route.c
@@ -435,7 +435,7 @@ ChimeraHost *find_closest_key (void *sta
     if (size == 0)
 	{
 	    min = NULL;
-	    return;
+	    return NULL;
 	}
 
     else
