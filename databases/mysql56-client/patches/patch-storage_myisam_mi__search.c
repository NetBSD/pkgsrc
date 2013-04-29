$NetBSD: patch-storage_myisam_mi__search.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_search.c.orig	2013-04-28 13:59:30.000000000 +0000
+++ storage/myisam/mi_search.c
@@ -82,7 +82,7 @@ int _mi_search(register MI_INFO *info, r
   }
 
   if (!(buff=_mi_fetch_keypage(info,keyinfo,pos,DFLT_INIT_HITS,info->buff,
-                               test(!(nextflag & SEARCH_SAVE_BUFF)))))
+                               my_test(!(nextflag & SEARCH_SAVE_BUFF)))))
     goto err;
   DBUG_DUMP("page", buff, mi_getint(buff));
 
@@ -125,7 +125,7 @@ int _mi_search(register MI_INFO *info, r
   {
     uchar *old_buff=buff;
     if (!(buff=_mi_fetch_keypage(info,keyinfo,pos,DFLT_INIT_HITS,info->buff,
-                                 test(!(nextflag & SEARCH_SAVE_BUFF)))))
+                                 my_test(!(nextflag & SEARCH_SAVE_BUFF)))))
       goto err;
     keypos=buff+(keypos-old_buff);
     maxpos=buff+(maxpos-old_buff);
