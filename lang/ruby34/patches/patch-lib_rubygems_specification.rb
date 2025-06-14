$NetBSD: patch-lib_rubygems_specification.rb,v 1.1 2025/06/14 06:54:47 taca Exp $

Do not sort @extensions in Gem::Specification#normlize since there is
a gem (google-protobuf) depends on its order to build extensions.

--- lib/rubygems/specification.rb.orig	2025-05-14 03:11:06.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -2145,7 +2145,7 @@ class Gem::Specification < Gem::BasicSpe
     end
 
     @files            = @files.uniq.sort if @files
-    @extensions       = @extensions.uniq.sort if @extensions
+    @extensions       = @extensions.uniq if @extensions
     @test_files       = @test_files.uniq.sort if @test_files
     @executables      = @executables.uniq.sort if @executables
     @extra_rdoc_files = @extra_rdoc_files.uniq.sort if @extra_rdoc_files
