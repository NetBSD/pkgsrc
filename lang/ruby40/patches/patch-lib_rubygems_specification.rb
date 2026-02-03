$NetBSD: patch-lib_rubygems_specification.rb,v 1.1 2026/02/03 16:00:34 taca Exp $

* keep has_rdoc related methods since there are many gems contain it now.
* Do not sort @extensions in Gem::Specification#normlize since there
  is a gem (google-protobuf) depends on its order to build extensions.
* Revive support for 'has_rdoc" when environment RUBY_ALLOW_HAS_RDOC is
  defined.
                                                             
--- lib/rubygems/specification.rb.orig	2026-01-13 02:02:40.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -1884,16 +1884,41 @@ class Gem::Specification < Gem::BasicSpe
     @gems_dir ||= File.join(base_dir, "gems")
   end
 
-  ##
-  # True if this gem has files in test_files
+  if ENV.has_key? 'RUBY_ALLOW_HAS_RDOC'
+    ##
+    # Deprecated and ignored, defaults to true.
+    #
+    # Formerly used to indicate this gem was RDoc-capable.
 
-  def has_unit_tests? # :nodoc:
-    !test_files.empty?
-  end
+    def has_rdoc # :nodoc:
+      true
+    end
+    rubygems_deprecate :has_rdoc
+
+    ##
+    # Deprecated and ignored.
+    #
+    # Formerly used to indicate this gem was RDoc-capable.
+
+    def has_rdoc=(ignored) # :nodoc:
+      @has_rdoc = true
+    end
+    rubygems_deprecate :has_rdoc=
 
-  # :stopdoc:
-  alias_method :has_test_suite?, :has_unit_tests?
-  # :startdoc:
+    alias_method :has_rdoc?, :has_rdoc # :nodoc:
+    rubygems_deprecate :has_rdoc?
+
+    ##
+    # True if this gem has files in test_files
+
+    def has_unit_tests? # :nodoc:
+      !test_files.empty?
+    end
+
+    # :stopdoc:
+    alias_method :has_test_suite?, :has_unit_tests?
+    # :startdoc:
+  end
 
   def hash # :nodoc:
     name.hash ^ version.hash
@@ -2074,7 +2099,7 @@ class Gem::Specification < Gem::BasicSpe
     end
 
     @files            = @files.uniq.sort if @files
-    @extensions       = @extensions.uniq.sort if @extensions
+    @extensions       = @extensions.uniq if @extensions
     @test_files       = @test_files.uniq.sort if @test_files
     @executables      = @executables.uniq.sort if @executables
     @extra_rdoc_files = @extra_rdoc_files.uniq.sort if @extra_rdoc_files
