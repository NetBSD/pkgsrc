$NetBSD: patch-glib2_ext_glib2_rbglib.h,v 1.1 2013/02/07 13:41:54 obache Exp $

* Move rb_str_new_cstr() compatible macro to private header 
  Because all rbglib.h users should check rb_str_new_cstr() check when
  it exists in rbglib.h.
  https://github.com/ruby-gnome2/ruby-gnome2/commit/97e6965c4b4463c5aa687b4827f3ef52e7054571

--- glib2/ext/glib2/rbglib.h.orig	2013-01-30 14:00:35.000000000 +0000
+++ glib2/ext/glib2/rbglib.h
@@ -63,10 +63,6 @@ typedef int GPid;
 #  define G_SOURCE_CONTINUE TRUE
 #endif
 
-#ifndef HAVE_RB_STR_NEW_CSTR
-#  define rb_str_new_cstr(c_string) rb_str_new2(c_string)
-#endif
-
 #define RBG_INSPECT(object) (rbg_rval_inspect(object))
 
 #define RVAL2CSTR(v) (rbg_rval2cstr(&(v)))
