$NetBSD: patch-tool_rbinstall.rb,v 1.1 2015/12/30 14:59:42 taca Exp $

* Don't install which has already ${RUBY_VER} suffix.

--- tool/rbinstall.rb.orig	2015-11-16 06:33:17.000000000 +0000
+++ tool/rbinstall.rb
@@ -220,7 +220,7 @@ def install_recursive(srcdir, dest, opti
       end
     end
   end
-  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core"
+  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core *220"
   prune = path_matcher(prune)
   skip = path_matcher(skip)
   File.directory?(srcdir) or return rescue return
