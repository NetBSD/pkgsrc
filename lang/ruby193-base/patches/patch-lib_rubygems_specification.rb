$NetBSD: patch-lib_rubygems_specification.rb,v 1.3.4.1 2013/07/16 17:00:50 tron Exp $

Changes for pkgsrc environment:

* Allow some attributes to nil.
* Relax date/time format.

And allow multiple conditions for requirement from Ruby 2.0.0 and
Rubygem 1.8.25.

--- lib/rubygems/specification.rb.orig	2012-04-19 22:43:16.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -118,6 +118,12 @@ class Gem::Specification
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
 
@@ -934,6 +940,32 @@ class Gem::Specification
   end
 
   ##
+  # Returns the build_args used to install the gem
+
+  def build_args
+    if File.exists? build_info_file
+      File.readlines(build_info_file).map { |x| x.strip }
+    else
+      []
+    end
+  end
+
+  ##
+  # Returns the full path to the build info directory
+
+  def build_info_dir
+    File.join base_dir, "build_info"
+  end
+
+  ##
+  # Returns the full path to the file containing the build
+  # information generated when the gem was installed
+
+  def build_info_file
+    File.join build_info_dir, "#{full_name}.info"
+  end
+
+  ##
   # Returns the full path to the cache directory containing this
   # spec's cached gem.
 
@@ -1000,7 +1032,7 @@ class Gem::Specification
     # way to do it.
     @date = case date
             when String then
-              if /\A(\d{4})-(\d{2})-(\d{2})\Z/ =~ date then
+              if /\A(\d{4})-(\d{2})-(\d{2})/ =~ date then
                 Time.utc($1.to_i, $2.to_i, $3.to_i)
 
               # Workaround for where the date format output from psych isn't
@@ -1720,7 +1752,9 @@ class Gem::Specification
     when Numeric           then obj.inspect
     when true, false, nil  then obj.inspect
     when Gem::Platform     then "Gem::Platform.new(#{obj.to_a.inspect})"
-    when Gem::Requirement  then "Gem::Requirement.new(#{obj.to_s.inspect})"
+    when Gem::Requirement  then
+      list = obj.as_list
+      "Gem::Requirement.new(#{ruby_code(list.size == 1 ? obj.to_s : list)})"
     else raise Gem::Exception, "ruby_code case not handled: #{obj.class}"
     end
   end
@@ -1946,6 +1980,7 @@ class Gem::Specification
       ast = builder.tree
 
       io = StringIO.new
+      io.set_encoding Encoding::UTF_8 if Object.const_defined? :Encoding
 
       Psych::Visitors::Emitter.new(io).accept(ast)
 
@@ -1987,7 +2022,24 @@ class Gem::Specification
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
@@ -2090,10 +2142,15 @@ class Gem::Specification
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
