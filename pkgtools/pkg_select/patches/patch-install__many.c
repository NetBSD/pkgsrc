$NetBSD: patch-install__many.c,v 1.1 2013/11/29 23:13:56 dholland Exp $

Fix const correctness.

--- install_many.c~	2009-03-08 14:25:53.000000000 +0000
+++ install_many.c
@@ -199,7 +199,7 @@ process_many(int action)
 		if ((list = build_list_from_slist()) == NULL)
 			goto out;
 		if ((etree = 
-		     build_tree_from_list((const char **)list)) == NULL)
+		     build_tree_from_list((const char *const *)list)) == NULL)
 			goto out;
 
 		XFREE(resp);
