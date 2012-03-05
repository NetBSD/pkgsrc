$NetBSD: patch-lib_active__support_core__ext_string_output__safety.rb,v 1.1.2.2 2012/03/05 23:28:40 tron Exp $

Fix for CVE-2012-1099.

--- lib/active_support/core_ext/string/output_safety.rb.orig	2012-03-03 03:54:59.000000000 +0000
+++ lib/active_support/core_ext/string/output_safety.rb
@@ -85,23 +85,41 @@ module ActiveSupport #:nodoc:
       end
     end
 
+    def [](*args)
+      return super if args.size < 2
+
+      if html_safe?
+        new_safe_buffer = super
+        new_safe_buffer.instance_eval { @html_safe = true }
+        new_safe_buffer
+      else
+        to_str[*args]
+      end
+    end
+
     def safe_concat(value)
-      raise SafeConcatError if dirty?
+      raise SafeConcatError unless html_safe?
       original_concat(value)
     end
 
     def initialize(*)
-      @dirty = false
+      @html_safe = true
       super
     end
 
     def initialize_copy(other)
       super
-      @dirty = other.dirty?
+      @html_safe = other.html_safe?
+    end
+
+    def clone_empty
+      new_safe_buffer = self[0, 0]
+      new_safe_buffer.instance_variable_set(:@dirty, @dirty)
+      new_safe_buffer
     end
 
     def concat(value)
-      if dirty? || value.html_safe?
+      if !html_safe? || value.html_safe?
         super(value)
       else
         super(ERB::Util.h(value))
@@ -114,7 +132,7 @@ module ActiveSupport #:nodoc:
     end
 
     def html_safe?
-      !dirty?
+      defined?(@html_safe) && @html_safe
     end
 
     def to_s
@@ -132,23 +150,17 @@ module ActiveSupport #:nodoc:
     for unsafe_method in UNSAFE_STRING_METHODS
       if 'String'.respond_to?(unsafe_method)
         class_eval <<-EOT, __FILE__, __LINE__ + 1
-          def #{unsafe_method}(*args)
-            super.to_str
-          end
-
-          def #{unsafe_method}!(*args)
-            @dirty = true
-            super
-          end
+          def #{unsafe_method}(*args, &block)       # def capitalize(*args, &block)
+            to_str.#{unsafe_method}(*args, &block)  #   to_str.capitalize(*args, &block)
+          end                                       # end
+
+          def #{unsafe_method}!(*args)              # def capitalize!(*args)
+            @html_safe = false                      #   @html_safe = false
+            super                                   #   super
+          end                                       # end
         EOT
       end
     end
-
-    protected
-
-    def dirty?
-      @dirty
-    end
   end
 end
 
