$NetBSD: patch-storage_myisam_myisamchk.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/myisamchk.c.orig	2013-04-28 14:00:35.000000000 +0000
+++ storage/myisam/myisamchk.c
@@ -1118,7 +1118,7 @@ static int myisamchk(MI_CHECK *param, ch
   if ((param->testflag & T_AUTO_INC) ||
       ((param->testflag & T_REP_ANY) && info->s->base.auto_key))
     update_auto_increment_key(param, info,
-			      (my_bool) !test(param->testflag & T_AUTO_INC));
+			      (my_bool) !my_test(param->testflag & T_AUTO_INC));
 
   if (!(param->testflag & T_DESCRIPT))
   {
