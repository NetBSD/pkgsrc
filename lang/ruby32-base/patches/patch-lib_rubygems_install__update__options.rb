$NetBSD: patch-lib_rubygems_install__update__options.rb,v 1.1 2023/01/21 13:51:23 taca Exp $

* Add install_root option for pkgsrc's rubygems support.
* Tweak build_info directory with destdir to store build_args.

--- lib/rubygems/install_update_options.rb.orig	2022-11-24 10:20:31.000000000 +0000
+++ lib/rubygems/install_update_options.rb
@@ -18,6 +18,12 @@ module Gem::InstallUpdateOptions
   # Add the install/update options to the option parser.
 
   def add_install_update_options
+    add_option(:"Install/Update", "-B", "--install-root DIR",
+               "Root directory for gem files on install") do |value, options|
+      options[:install_root] = File.expand_path(value)
+      Gem.ensure_gem_subdirectories File.join options[:install_root], Gem.dir
+    end
+
     add_option(:"Install/Update", "-i", "--install-dir DIR",
                "Gem repository directory to get installed",
                "gems") do |value, options|
