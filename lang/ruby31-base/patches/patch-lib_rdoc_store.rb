$NetBSD: patch-lib_rdoc_store.rb,v 1.1 2024/03/23 14:28:48 taca Exp $

Update rdoc to 6.4.1.1 to fix for CVE-2024-27281.

--- lib/rdoc/store.rb.orig	2023-03-30 10:53:51.000000000 +0000
+++ lib/rdoc/store.rb
@@ -556,9 +556,7 @@ class RDoc::Store
   def load_cache
     #orig_enc = @encoding
 
-    File.open cache_path, 'rb' do |io|
-      @cache = Marshal.load io.read
-    end
+    @cache = marshal_load(cache_path)
 
     load_enc = @cache[:encoding]
 
@@ -615,9 +613,7 @@ class RDoc::Store
   def load_class_data klass_name
     file = class_file klass_name
 
-    File.open file, 'rb' do |io|
-      Marshal.load io.read
-    end
+    marshal_load(file)
   rescue Errno::ENOENT => e
     error = MissingFileError.new(self, file, klass_name)
     error.set_backtrace e.backtrace
@@ -630,14 +626,10 @@ class RDoc::Store
   def load_method klass_name, method_name
     file = method_file klass_name, method_name
 
-    File.open file, 'rb' do |io|
-      obj = Marshal.load io.read
-      obj.store = self
-      obj.parent =
-        find_class_or_module(klass_name) || load_class(klass_name) unless
-          obj.parent
-      obj
-    end
+    obj = marshal_load(file)
+    obj.store = self
+    obj.parent ||= find_class_or_module(klass_name) || load_class(klass_name)
+    obj
   rescue Errno::ENOENT => e
     error = MissingFileError.new(self, file, klass_name + method_name)
     error.set_backtrace e.backtrace
@@ -650,11 +642,9 @@ class RDoc::Store
   def load_page page_name
     file = page_file page_name
 
-    File.open file, 'rb' do |io|
-      obj = Marshal.load io.read
-      obj.store = self
-      obj
-    end
+    obj = marshal.load(file)
+    obj.store = self
+    obj
   rescue Errno::ENOENT => e
     error = MissingFileError.new(self, file, page_name)
     error.set_backtrace e.backtrace
@@ -976,4 +966,21 @@ class RDoc::Store
     @unique_modules
   end
 
+  private
+  def marshal_load(file)
+    File.open(file, 'rb') {|io| Marshal.load(io, MarshalFilter)}
+  end
+
+  MarshalFilter = proc do |obj|
+    case obj
+    when true, false, nil, Array, Class, Encoding, Hash, Integer, String, Symbol, RDoc::Text
+    else
+      unless obj.class.name.start_with?("RDoc::")
+        raise TypeError, "not permitted class: #{obj.class.name}"
+      end
+    end
+    obj
+  end
+  private_constant :MarshalFilter
+
 end
