$NetBSD: patch-install__many.c,v 1.2 2017/12/29 11:59:13 plunky Exp $

Fix const correctness.

--- install_many.c.orig	2009-03-08 14:25:53.000000000 +0000
+++ install_many.c
@@ -199,7 +199,7 @@ process_many(int action)
 		if ((list = build_list_from_slist()) == NULL)
 			goto out;
 		if ((etree = 
-		     build_tree_from_list((const char **)list)) == NULL)
+		     build_tree_from_list((const char *const *)list)) == NULL)
 			goto out;
 
 		XFREE(resp);
