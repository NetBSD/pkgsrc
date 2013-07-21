$NetBSD: patch-tool_rbinstall.rb,v 1.1 2013/07/21 02:32:58 taca Exp $

* Don't install which has already ${RUBY_VER} suffix.

--- tool/rbinstall.rb.orig	2013-02-07 08:02:31.000000000 +0000
+++ tool/rbinstall.rb
@@ -213,7 +213,7 @@ def install_recursive(srcdir, dest, opti
       end
     end
   end
-  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core"
+  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core *200"
   prune = path_matcher(prune)
   skip = path_matcher(skip)
   File.directory?(srcdir) or return rescue return
