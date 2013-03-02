$NetBSD: patch-lib_ext_wocky_wocky_wocky-muc.c,v 1.1 2013/03/02 18:19:10 joerg Exp $

--- lib/ext/wocky/wocky/wocky-muc.c.orig	2013-03-01 14:32:26.000000000 +0000
+++ lib/ext/wocky/wocky/wocky-muc.c
@@ -1480,7 +1480,7 @@ extract_chat_state (WockyNode *msg)
 
   if (child == NULL ||
       !wocky_enum_from_nick (WOCKY_TYPE_MUC_MSG_STATE, child->name, &mstate))
-    mstate = WOCKY_MUC_MSG_NONE;
+    mstate = WOCKY_MUC_MSG_STATE_NONE;
 
   return mstate;
 }
