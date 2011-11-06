$NetBSD: patch-lib_addressable_template.rb,v 1.1 2011/11/06 07:44:28 obache Exp $

* Fixed variable shadowing (from upstream repo).

--- lib/addressable/template.rb.orig	2011-11-06 07:18:52.000000000 +0000
+++ lib/addressable/template.rb
@@ -931,7 +931,7 @@ module Addressable
       values.pop if values[-1] == ""
 
       if processor && processor.respond_to?(:restore)
-        values.map! { |value| processor.restore(variables.first, value) }
+        values.map! { |val| processor.restore(variables.first, val) }
       end
       values = values.first if values.size == 1
       if mapping[variables.first] == nil || mapping[variables.first] == values
@@ -965,7 +965,7 @@ module Addressable
       values = value.split(argument, -1)
       values.pop if values[-1] == ""
       if processor && processor.respond_to?(:restore)
-        values.map! { |value| processor.restore(variables.first, value) }
+        values.map! { |val| processor.restore(variables.first, val) }
       end
       values = values.first if values.size == 1
       if mapping[variables.first] == nil || mapping[variables.first] == values
@@ -1034,7 +1034,7 @@ module Addressable
       values = value.split(argument, -1)
       values.pop if values[-1] == ""
       if processor && processor.respond_to?(:restore)
-        values.map! { |value| processor.restore(variables.first, value) }
+        values.map! { |val| processor.restore(variables.first, val) }
       end
       if mapping[variables.first] == nil || mapping[variables.first] == values
         mapping[variables.first] = values
