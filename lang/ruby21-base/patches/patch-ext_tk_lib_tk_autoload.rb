$NetBSD: patch-ext_tk_lib_tk_autoload.rb,v 1.1 2014/12/14 14:00:17 taca Exp $

* Add tcl/tk 8.6 support.

--- ext/tk/lib/tk/autoload.rb.orig	2011-05-15 11:55:52.000000000 +0000
+++ ext/tk/lib/tk/autoload.rb
@@ -94,6 +94,8 @@ module Tk
   autoload :Y_Scrollable,     'tk/scrollable'
   autoload :Scrollable,       'tk/scrollable'
 
+  autoload :Fontchooser,      'tk/fontchooser'
+
   autoload :Wm,               'tk/wm'
   autoload :Wm_for_General,   'tk/wm'
 
