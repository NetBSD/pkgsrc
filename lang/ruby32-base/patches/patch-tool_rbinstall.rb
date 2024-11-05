$NetBSD: patch-tool_rbinstall.rb,v 1.1 2024/11/05 14:58:03 taca Exp $

* Prefer gemspec file for C ext gems first.

--- tool/rbinstall.rb.orig	2024-10-30 09:47:11.000000000 +0000
+++ tool/rbinstall.rb
@@ -1028,13 +1028,13 @@ install?(:ext, :comm, :gem, :'bundled-ge
     next unless /^(\S+)\s+(\S+).*/ =~ name
     gem = $1
     gem_name = "#$1-#$2"
-    # Try to find the original gemspec file
-    path = "#{srcdir}/.bundle/gems/#{gem_name}/#{gem}.gemspec"
+    # Try to find the gemspec file for C ext gems
+    # ex .bundle/gems/debug-1.7.1/debug-1.7.1.gemspec
+    # This gemspec keep the original dependencies
+    path = "#{srcdir}/.bundle/gems/#{gem_name}/#{gem_name}.gemspec"
     unless File.exist?(path)
-      # Try to find the gemspec file for C ext gems
-      # ex .bundle/gems/debug-1.7.1/debug-1.7.1.gemspec
-      # This gemspec keep the original dependencies
-      path = "#{srcdir}/.bundle/gems/#{gem_name}/#{gem_name}.gemspec"
+      # Try to find the original gemspec file
+      path = "#{srcdir}/.bundle/gems/#{gem_name}/#{gem}.gemspec"
       unless File.exist?(path)
         # Try to find the gemspec file for gems that hasn't own gemspec
         path = "#{srcdir}/.bundle/specifications/#{gem_name}.gemspec"
