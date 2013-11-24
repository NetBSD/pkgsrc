$NetBSD: patch-ext_tk_lib_tkextlib_tktable_tktable.rb,v 1.1 2013/11/24 15:26:30 taca Exp $

Fix wrong parameter from [ruby-list:49643].

--- ext/tk/lib/tkextlib/tktable/tktable.rb.orig	2009-10-02 10:45:39.000000000 +0000
+++ ext/tk/lib/tkextlib/tktable/tktable.rb
@@ -70,7 +70,7 @@ module Tk::TkTable::ConfigMethod
   private :__item_strval_optkeys
 
   def __item_val2ruby_optkeys(id)  # { key=>method, ... }
-    super(id).update('window'=>proc{|v| window(v)})
+    super(id).update('window'=>proc{|k, v| window(v)})
   end
   private :__item_val2ruby_optkeys
 
