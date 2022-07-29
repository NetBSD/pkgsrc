$NetBSD: patch-extconf.rb,v 1.1 2022/07/29 06:00:31 rin Exp $

Switch to `pkg-config imlib2`.

--- extconf.rb.orig	2022-07-29 03:18:47.822900074 +0900
+++ extconf.rb	2022-07-29 03:20:08.407656008 +0900
@@ -1,13 +1,13 @@
 require 'mkmf'
 
-imlib2_config = with_config("imlib2-config", "imlib2-config")
+pkg_config = with_config("pkg-config", "pkg-config")
 
-$CFLAGS << ' -DX_DISPLAY_MISSING ' << `#{imlib2_config} --cflags`.chomp
-$LDFLAGS << ' ' << `#{imlib2_config} --libs`.chomp
+$CFLAGS << ' -DX_DISPLAY_MISSING ' << `#{pkg_config} imlib2 --cflags`.chomp
+$LDFLAGS << ' ' << `#{pkg_config} imlib2 --libs`.chomp
 
 if have_library("Imlib2", "imlib_create_image")
   # test for faulty versions of imlib2
-  ver = `imlib2-config --version`.chomp.split(/\./)
+  ver = `pkg-config imlib2 --modversion`.chomp.split(/\./)
   major, minor, revision = ver[0].to_i, ver[1].to_i, ver[2].to_i
   if ((major > 1)               ||
       (major == 1 && minor > 0) ||
