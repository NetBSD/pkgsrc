$NetBSD: patch-ext_json_lib_json_common.rb,v 1.1 2013/02/12 13:03:09 taca Exp $

Fix for CVE-2013-0269.

--- ext/json/lib/json/common.rb.orig	2011-08-30 02:25:32.000000000 +0000
+++ ext/json/lib/json/common.rb
@@ -141,7 +141,7 @@ module JSON
   #   the default.
   # * *create_additions*: If set to false, the Parser doesn't create
   #   additions even if a matching class and create_id was found. This option
-  #   defaults to true.
+  #   defaults to false.
   # * *object_class*: Defaults to Hash
   # * *array_class*: Defaults to Array
   def parse(source, opts = {})
@@ -162,7 +162,7 @@ module JSON
   #   to true.
   # * *create_additions*: If set to false, the Parser doesn't create
   #   additions even if a matching class and create_id was found. This option
-  #   defaults to true.
+  #   defaults to false.
   def parse!(source, opts = {})
     opts = {
       :max_nesting  => false,
@@ -287,11 +287,18 @@ module JSON
   # Load a ruby data structure from a JSON _source_ and return it. A source can
   # either be a string-like object, an IO-like object, or an object responding
   # to the read method. If _proc_ was given, it will be called with any nested
-  # Ruby object as an argument recursively in depth first order.
+  # Ruby object as an argument recursively in depth first order. To modify the
+  # default options pass in the optional _options_ argument as well.
   #
   # This method is part of the implementation of the load/dump interface of
   # Marshal and YAML.
-  def load(source, proc = nil)
+  def load(source, proc = nil, options = {})
+    load_default_options = {
+      :max_nesting      => false,
+      :allow_nan        => true,
+      :create_additions => false
+    }
+    opts = load_default_options.merge options
     if source.respond_to? :to_str
       source = source.to_str
     elsif source.respond_to? :to_io
@@ -299,7 +306,7 @@ module JSON
     else
       source = source.read
     end
-    result = parse(source, :max_nesting => false, :allow_nan => true)
+    result = parse(source, opts)
     recurse_proc(result, &proc) if proc
     result
   end
