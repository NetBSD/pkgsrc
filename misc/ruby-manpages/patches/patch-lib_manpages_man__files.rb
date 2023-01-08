$NetBSD: patch-lib_manpages_man__files.rb,v 1.1.2.2 2023/01/08 15:57:24 bsiegert Exp $

* Install manual page with RUBY_VER style.

--- lib/manpages/man_files.rb.orig	2022-12-30 09:50:10.725925400 +0000
+++ lib/manpages/man_files.rb
@@ -1,7 +1,9 @@
 require "pathname"
+require "rbconfig"
 
 module Manpages
   class ManFiles
+    RUBY_VER = RbConfig::CONFIG["MAJOR"] + RbConfig::CONFIG["MINOR"]
     attr_reader :man_dir
 
     def initialize(gem_dir, target_dir = "")
@@ -23,7 +25,9 @@ module Manpages
 
     def man_file_path(file)
       man_section = file.extname.match(/\.(\d*)/)
-      @target_dir.join("man#{man_section[1]}", file.basename)
+      suffix = ".#{man_section[1]}"
+      name = file.basename(suffix).to_s + RUBY_VER + suffix
+      @target_dir.join("man#{man_section[1]}", name)
     end
   end
 end
