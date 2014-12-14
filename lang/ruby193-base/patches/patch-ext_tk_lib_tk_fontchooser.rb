$NetBSD: patch-ext_tk_lib_tk_fontchooser.rb,v 1.1 2014/12/14 13:59:53 taca Exp $

* Add tcl/tk 8.6 support.

--- ext/tk/lib/tk/fontchooser.rb.orig	2011-05-15 11:55:52.000000000 +0000
+++ ext/tk/lib/tk/fontchooser.rb
@@ -8,6 +8,10 @@ module TkFont::Chooser
   extend TkCore
 end
 
+module Tk
+  Fontchooser = TkFont::Chooser
+end
+
 class << TkFont::Chooser
   def method_missing(id, *args)
     name = id.id2name
