$NetBSD: patch-ext_glib2_rbgprivate.h,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/glib2/rbgprivate.h.orig	2018-04-29 15:03:30.000000000 +0000
+++ ext/glib2/rbgprivate.h
@@ -1,6 +1,6 @@
 /* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
 /*
- *  Copyright (C) 2007-2017  Ruby-GNOME2 Project Team
+ *  Copyright (C) 2007-2018  Ruby-GNOME2 Project Team
  *
  *  This library is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU Lesser General Public
@@ -42,6 +42,7 @@ typedef struct {
     GObject* gobj;
     const RGObjClassInfo* cinfo;
     gboolean destroyed;
+    GHashTable *rb_relatives;
 } gobj_holder;
 
 typedef struct {
