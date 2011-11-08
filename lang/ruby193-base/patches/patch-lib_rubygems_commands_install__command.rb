$NetBSD: patch-lib_rubygems_commands_install__command.rb,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Prevent access to HOME when --install-root is used.

--- lib/rubygems/commands/install_command.rb.orig	2011-07-27 02:04:03.000000000 +0000
+++ lib/rubygems/commands/install_command.rb
@@ -148,7 +148,7 @@ to write the specification by hand.  For
           Gem::DocManager.new(gem, options[:rdoc_args]).generate_ri
         end
 
-        Gem::DocManager.update_ri_cache
+        Gem::DocManager.update_ri_cache(options[:install_root])
       end
 
       if options[:generate_rdoc] then
