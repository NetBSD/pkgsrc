$NetBSD: patch-glib2_lib_mkmf-gnome2.rb,v 1.3 2012/01/11 14:10:11 obache Exp $

* Segmentation fault with gcc-4.1.3 on NetBSD-5.1.

--- glib2/lib/mkmf-gnome2.rb.orig	2012-01-05 11:23:51.000000000 +0000
+++ glib2/lib/mkmf-gnome2.rb
@@ -41,7 +41,7 @@ try_compiler_option '-Winit-self'
 try_compiler_option '-Wlarger-than-65500'
 try_compiler_option '-Wmissing-declarations'
 try_compiler_option '-Wmissing-format-attribute'
-try_compiler_option '-Wmissing-include-dirs'
+#try_compiler_option '-Wmissing-include-dirs'
 try_compiler_option '-Wmissing-noreturn'
 try_compiler_option '-Wmissing-prototypes'
 try_compiler_option '-Wnested-externs'
