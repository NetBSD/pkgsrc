$NetBSD: patch-core_mui_cairo__inner__tl.rb,v 1.4 2012/03/02 06:34:35 obache Exp $

* use system bseach library instead of included one.

--- core/mui/cairo_inner_tl.rb.orig	2012-02-13 14:45:50.000000000 +0000
+++ core/mui/cairo_inner_tl.rb
@@ -1,7 +1,7 @@
 # -*- coding: utf-8 -*-
 
 miquire :mui, 'timeline'
-miquire :lib, 'ruby-bsearch-1.5/bsearch'
+miquire :lib, 'bsearch'
 miquire :lib, 'uithreadonly'
 require 'gtk2'
 
