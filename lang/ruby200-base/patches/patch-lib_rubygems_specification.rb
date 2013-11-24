$NetBSD: patch-lib_rubygems_specification.rb,v 1.2 2013/11/24 14:22:03 taca Exp $

* Changes for pkgsrc environment:

  -  Allow some attributes to nil.
  -  Relax date/time format.

And allow multiple conditions for requirement from Ruby 2.0.0 and
Rubygem 1.8.25.

--- lib/rubygems/specification.rb.orig	2013-11-13 02:59:08.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -162,6 +162,12 @@ class Gem::Specification
     @@default_value[k].nil?
   }
 
+  # under pkgsrc environment
+  @@pkgsrc_nil_attributes = {}
+  [:authors, :cert_chain, :executables, :extensions, :extra_rdoc_files, :licenses, :required_rubygems_version, :test_files].each do |k|
+    @@pkgsrc_nil_attributes[k] = true
+  end
+
   ######################################################################
   # :section: Required gemspec attributes
 
@@ -2334,7 +2340,24 @@ class Gem::Specification
     normalize
 
     nil_attributes = self.class.non_nil_attributes.find_all do |name|
-      instance_variable_get("@#{name}").nil?
+      val = instance_variable_get("@#{name}")
+      if val.nil?
+        if @@pkgsrc_nil_attributes.key?(name)
+          case name
+          when :required_rubygems_version
+            val = Gem::Requirement.default
+          else
+            val = []
+          end
+          instance_variable_set("@#{name}", val)
+          false
+        end
+      end
+      if name == :authors and val.empty?
+        val = ['not specified']
+        self.authors = val
+        false
+      end
     end
 
     unless nil_attributes.empty? then
@@ -2472,10 +2495,15 @@ class Gem::Specification
       raise Gem::InvalidSpecificationException, "#{lazy} is not a summary"
     end
 
-    if homepage and not homepage.empty? and
-       homepage !~ /\A[a-z][a-z\d+.-]*:/i then
-      raise Gem::InvalidSpecificationException,
-            "\"#{homepage}\" is not a URI"
+    if homepage and not homepage.empty?
+      if @homepage =~ /\A[a-z][a-z\d+.-]*/i and
+          @homepage !~ /\A[a-z][a-z\d+.-]*:/i
+        @homepage = "http://" + @homepage
+      end
+      if homepage !~ /\A[a-z][a-z\d+.-]*:/i then
+        raise Gem::InvalidSpecificationException,
+              "\"#{homepage}\" is not a URI"
+      end
     end
 
     # Warnings
