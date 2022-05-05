$NetBSD: patch-tool_runruby.rb,v 1.1 2022/05/05 10:25:05 jperkin Exp $

Do not LD_PRELOAD on macOS, breaks chroots.

--- tool/runruby.rb.orig	2022-04-12 11:11:15.000000000 +0000
+++ tool/runruby.rb
@@ -132,7 +132,7 @@ if File.file?(libruby_so)
       e = nil if e.empty?
       e ||= "LD_PRELOAD" if /linux/ =~ RUBY_PLATFORM
     end
-    if e
+    unless /darwin/ =~ RUBY_PLATFORM
       env[e] = [libruby_so, ENV[e]].compact.join(File::PATH_SEPARATOR)
     end
   end
