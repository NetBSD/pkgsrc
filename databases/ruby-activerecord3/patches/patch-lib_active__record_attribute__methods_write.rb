$NetBSD$

Fix for CVE-2013-0277.

--- lib/active_record/attribute_methods/write.rb.orig	2013-02-12 00:08:22.000000000 +0000
+++ lib/active_record/attribute_methods/write.rb
@@ -10,7 +10,14 @@ module ActiveRecord
       module ClassMethods
         protected
           def define_method_attribute=(attr_name)
-            if attr_name =~ /^[a-zA-Z_]\w*[!?=]?$/
+            if self.serialized_attributes[attr_name]
+              generated_attribute_methods.send(:define_method, "#{attr_name}=") do |new_value|
+                if new_value.is_a?(String) and new_value =~ /^---/
+                  raise ActiveRecordError, "You tried to assign already serialized content to #{attr_name}. This is disabled due to security issues."
+                end
+                write_attribute(attr_name, new_value)
+              end
+            elsif attr_name =~ /^[a-zA-Z_]\w*[!?=]?$/
               generated_attribute_methods.module_eval("def #{attr_name}=(new_value); write_attribute('#{attr_name}', new_value); end", __FILE__, __LINE__)
             else
               generated_attribute_methods.send(:define_method, "#{attr_name}=") do |new_value|
