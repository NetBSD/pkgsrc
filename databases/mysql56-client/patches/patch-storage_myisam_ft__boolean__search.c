$NetBSD: patch-storage_myisam_ft__boolean__search.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/ft_boolean_search.c.orig	2013-04-28 13:58:51.000000000 +0000
+++ storage/myisam/ft_boolean_search.c
@@ -533,7 +533,7 @@ static void _ftb_init_index_search(FT_IN
       {
         if (ftbe->flags & FTB_FLAG_NO ||                     /* 2 */
             ftbe->up->ythresh - ftbe->up->yweaks >
-            (uint) test(ftbe->flags & FTB_FLAG_YES))         /* 1 */
+            (uint) my_test(ftbe->flags & FTB_FLAG_YES))         /* 1 */
         {
           FTB_EXPR *top_ftbe=ftbe->up;
           ftbw->docid[0]=HA_OFFSET_ERROR;
