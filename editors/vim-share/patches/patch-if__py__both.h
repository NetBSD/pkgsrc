$NetBSD: patch-if__py__both.h,v 1.1 2014/05/03 07:30:19 richard Exp $

--- src/if_py_both.h.orig	2014-01-11 21:59:11.000000000 +0000
+++ src/if_py_both.h
@@ -2392,7 +2392,7 @@ ListAssItem(ListObject *self, Py_ssize_t
     if (obj == NULL)
     {
 	li = list_find(l, (long) index);
-	list_remove(l, li, li);
+	vimlist_remove(l, li, li);
 	clear_tv(&li->li_tv);
 	vim_free(li);
 	return 0;
