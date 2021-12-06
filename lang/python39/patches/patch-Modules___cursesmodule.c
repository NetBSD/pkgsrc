$NetBSD: patch-Modules___cursesmodule.c,v 1.2 2021/12/06 16:36:15 wiz Exp $

NetBSD curses compatibility.
https://bugs.python.org/issue46000

--- Modules/_cursesmodule.c.orig	2021-11-15 17:43:00.000000000 +0000
+++ Modules/_cursesmodule.c
@@ -1077,8 +1077,8 @@ PyCursesWindow_ChgAt(PyCursesWindowObjec
         return NULL;
     }
 
-    color = (short)((attr >> 8) & 0xff);
-    attr = attr - (color << 8);
+    color = (short) PAIR_NUMBER(attr);
+    attr = attr & A_ATTRIBUTES;
 
     if (use_xy) {
         rtn = mvwchgat(self->win,y,x,num,attr,color,NULL);
