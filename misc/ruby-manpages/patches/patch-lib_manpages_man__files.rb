$NetBSD: patch-lib_manpages_man__files.rb,v 1.2 2026/05/31 06:01:00 taca Exp $

* Install manual page with RUBY_VER style.

--- lib/manpages/man_files.rb.orig	2026-05-24 01:59:08.965762417 +0000
+++ lib/manpages/man_files.rb
@@ -1,9 +1,11 @@
 # frozen_string_literal: true
 
 require "pathname"
+require "rbconfig"
 
 module Manpages
   class ManFiles
+    RUBY_VER = RbConfig::CONFIG["MAJOR"] + RbConfig::CONFIG["MINOR"]
     attr_reader :man_dir
 
     def initialize(gem_dir, target_dir = "")
@@ -25,7 +27,9 @@ module Manpages
 
     def man_file_path(file)
       man_section = file.extname.match(/\.(\d*)/)
-      @target_dir.join("man#{man_section[1]}", file.basename)
+      suffix = ".#{man_section[1]}"
+      name = file.basename(suffix).to_s + RUBY_VER + suffix
+      @target_dir.join("man#{man_section[1]}", name)
     end
   end
 end
