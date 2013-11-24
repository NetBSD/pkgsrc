$NetBSD: patch-tool_rbinstall.rb,v 1.2 2013/11/24 14:22:03 taca Exp $

* Don't install which has already ${RUBY_VER} suffix.

--- tool/rbinstall.rb.orig	2013-11-12 14:35:13.000000000 +0000
+++ tool/rbinstall.rb
@@ -220,7 +220,7 @@ def install_recursive(srcdir, dest, opti
       end
     end
   end
-  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core"
+  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core *200"
   prune = path_matcher(prune)
   skip = path_matcher(skip)
   File.directory?(srcdir) or return rescue return
