$NetBSD: patch-proto_eval.pro,v 1.1 2014/05/03 07:30:19 richard Exp $

'list_remove', being defined as well on SunOS under <sys/list.h>, causes
a 'conflicting types' error when building with perl, python and/or ruby.
Affects the following files: eval.c, if_lua.c and if_py_both.c

--- src/proto/eval.pro.orig	2013-07-06 19:39:48.000000000 +0000
+++ src/proto/eval.pro
@@ -59,7 +59,7 @@ int list_append_tv __ARGS((list_T *l, ty
 int list_append_dict __ARGS((list_T *list, dict_T *dict));
 int list_append_string __ARGS((list_T *l, char_u *str, int len));
 int list_insert_tv __ARGS((list_T *l, typval_T *tv, listitem_T *item));
-void list_remove __ARGS((list_T *l, listitem_T *item, listitem_T *item2));
+void vimlist_remove __ARGS((list_T *l, listitem_T *item, listitem_T *item2));
 int garbage_collect __ARGS((void));
 void set_ref_in_ht __ARGS((hashtab_T *ht, int copyID));
 void set_ref_in_list __ARGS((list_T *l, int copyID));
