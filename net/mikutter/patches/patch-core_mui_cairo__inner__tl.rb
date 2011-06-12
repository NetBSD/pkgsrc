$NetBSD: patch-core_mui_cairo__inner__tl.rb,v 1.1 2011/06/12 12:41:15 obache Exp $

* use system bseach library instead of included one.

--- core/mui/cairo_inner_tl.rb.orig	2011-06-05 13:30:21.000000000 +0000
+++ core/mui/cairo_inner_tl.rb
@@ -1,7 +1,7 @@
 # -*- coding: utf-8 -*-
 
 miquire :mui, 'timeline'
-miquire :lib, 'ruby-bsearch-1.5/bsearch'
+miquire :lib, 'bsearch'
 
 class Gtk::TimeLine::InnerTL < Gtk::CRUD
   attr_accessor :postbox
