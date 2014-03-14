$NetBSD: patch-tool_rbinstall.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

* Don't install which has already ${RUBY_VER} suffix.

--- tool/rbinstall.rb.orig	2013-11-09 16:37:46.000000000 +0000
+++ tool/rbinstall.rb
@@ -222,7 +222,7 @@ def install_recursive(srcdir, dest, opti
       end
     end
   end
-  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core"
+  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core *210"
   prune = path_matcher(prune)
   skip = path_matcher(skip)
   File.directory?(srcdir) or return rescue return
