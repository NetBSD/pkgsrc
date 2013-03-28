$NetBSD: patch-SRC_dqs__select__queue.c,v 1.1 2013/03/28 21:37:23 joerg Exp $

--- SRC/dqs_select_queue.c.orig	2013-03-28 16:10:42.000000000 +0000
+++ SRC/dqs_select_queue.c
@@ -1054,8 +1054,7 @@ int dqs_return_consumable(job, cname,  a
 
 
 /************************************************************/
-int dqs_reset_consumable(cname)
-     char *cname;
+void dqs_reset_consumable(char *cname)
 {
   dqs_list_type *cons_lp;
   dqs_list_type *cp;
