$NetBSD: patch-tool_rbinstall.rb,v 1.1 2011/12/04 02:31:54 taca Exp $

Don't install which has already ${RUBY_VER} suffix.

--- tool/rbinstall.rb.orig	2011-07-30 14:19:11.000000000 +0000
+++ tool/rbinstall.rb
@@ -211,7 +211,7 @@ def install_recursive(srcdir, dest, opti
       end
     end
   end
-  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core"
+  skip |= %w"#*# *~ *.old *.bak *.orig *.rej *.diff *.patch *.core *193"
   prune = path_matcher(prune)
   skip = path_matcher(skip)
   File.directory?(srcdir) or return rescue return
