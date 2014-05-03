$NetBSD: patch-eval.c,v 1.1 2014/05/03 07:30:19 richard Exp $

--- src/eval.c.orig	2014-01-11 21:59:11.000000000 +0000
+++ src/eval.c
@@ -5981,7 +5981,7 @@ listitem_remove(l, item)
     list_T  *l;
     listitem_T *item;
 {
-    list_remove(l, item, item);
+    vimlist_remove(l, item, item);
     listitem_free(item);
 }
 
@@ -6553,7 +6553,7 @@ list_copy(orig, deep, copyID)
  * Does not free the listitem or the value!
  */
     void
-list_remove(l, item, item2)
+vimlist_remove(l, item, item2)
     list_T	*l;
     listitem_T	*item;
     listitem_T	*item2;
@@ -15344,7 +15344,7 @@ f_remove(argvars, rettv)
 	    if (argvars[2].v_type == VAR_UNKNOWN)
 	    {
 		/* Remove one item, return its value. */
-		list_remove(l, item, item);
+		vimlist_remove(l, item, item);
 		*rettv = item->li_tv;
 		vim_free(item);
 	    }
@@ -15370,7 +15370,7 @@ f_remove(argvars, rettv)
 			EMSG(_(e_invrange));
 		    else
 		    {
-			list_remove(l, item, item2);
+			vimlist_remove(l, item, item2);
 			if (rettv_list_alloc(rettv) == OK)
 			{
 			    l = rettv->vval.v_list;
