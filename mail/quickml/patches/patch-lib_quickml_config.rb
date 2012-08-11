$NetBSD: patch-lib_quickml_config.rb,v 1.1 2012/08/11 13:51:20 obache Exp $

* for ruby-1.9

--- lib/quickml/config.rb.orig	2004-06-07 08:50:59.000000000 +0000
+++ lib/quickml/config.rb
@@ -62,7 +62,7 @@ module QuickML
       @confirm_ml_creation = (config[:confirm_ml_creation] or false)
 
       instance_variables.each {|name|
-	self.class.class_eval { attr_reader name.delete('@') }
+	self.class.class_eval { attr_reader name.to_s.delete('@') }
       }
     end
 
