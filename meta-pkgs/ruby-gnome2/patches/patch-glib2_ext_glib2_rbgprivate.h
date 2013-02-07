$NetBSD: patch-glib2_ext_glib2_rbgprivate.h,v 1.1 2013/02/07 13:41:54 obache Exp $

* Move rb_str_new_cstr() compatible macro to private header 
  Because all rbglib.h users should check rb_str_new_cstr() check when
  it exists in rbglib.h.
  https://github.com/ruby-gnome2/ruby-gnome2/commit/97e6965c4b4463c5aa687b4827f3ef52e7054571

--- glib2/ext/glib2/rbgprivate.h.orig	2012-07-21 14:29:19.000000000 +0000
+++ glib2/ext/glib2/rbgprivate.h
@@ -1,6 +1,6 @@
 /* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
 /*
- *  Copyright (C) 2011  Ruby-GNOME2 Project Team
+ *  Copyright (C) 2011-2013  Ruby-GNOME2 Project Team
  *  Copyright (C) 2007  Ruby-GNOME2 Project Team
  *
  *  This library is free software; you can redistribute it and/or
@@ -29,6 +29,10 @@
 #  define rb_errinfo() (ruby_errinfo)
 #endif
 
+#ifndef HAVE_RB_STR_NEW_CSTR
+#  define rb_str_new_cstr(c_string) rb_str_new2(c_string)
+#endif
+
 #ifndef G_VALUE_INIT
 #  define G_VALUE_INIT { 0, { { 0 } } }
 #endif
