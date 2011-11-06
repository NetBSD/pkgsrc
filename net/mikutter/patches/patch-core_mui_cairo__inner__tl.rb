$NetBSD: patch-core_mui_cairo__inner__tl.rb,v 1.3 2011/11/06 07:49:38 obache Exp $

* use system bseach library instead of included one.

--- core/mui/cairo_inner_tl.rb.orig	2011-09-03 16:58:10.000000000 +0000
+++ core/mui/cairo_inner_tl.rb
@@ -1,7 +1,7 @@
 # -*- coding: utf-8 -*-
 
 miquire :mui, 'timeline'
-miquire :lib, 'ruby-bsearch-1.5/bsearch'
+miquire :lib, 'bsearch'
 miquire :lib, 'uithreadonly'
 
 class Gtk::TimeLine::InnerTL < Gtk::CRUD
