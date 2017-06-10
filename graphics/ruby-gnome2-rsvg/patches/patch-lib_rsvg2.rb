$NetBSD: patch-lib_rsvg2.rb,v 1.1 2017/06/10 11:10:42 tsutsui Exp $

- pull dependency fix from upstream
  https://github.com/ruby-gnome2/ruby-gnome2/commit/9ddac28ccf948a4db7d49ea87fda034f9411e3e5

--- lib/rsvg2.rb.orig	2017-06-10 11:04:23.000000000 +0000
+++ lib/rsvg2.rb
@@ -18,6 +18,7 @@ require "gobject-introspection"
 require "glib2"
 require "gio2"
 require "gdk_pixbuf2"
+require "cairo-gobject"
 require "cairo"
 
 base_dir = Pathname.new(__FILE__).dirname.dirname.expand_path
