$NetBSD: patch-glib2_lib_mkmf-gnome2.rb,v 1.1 2011/02/11 13:50:08 obache Exp $

* Failed to detect non-gem rcairo
  https://sourceforge.net/tracker/?func=detail&aid=3178228&group_id=53614&atid=470969

--- glib2/lib/mkmf-gnome2.rb.orig	2011-02-02 11:40:57.000000000 +0000
+++ glib2/lib/mkmf-gnome2.rb
@@ -364,7 +364,7 @@ def check_cairo(options={})
     rescue LoadError
     end
   end
-  return false if rcairo_source_dir.nil?
+  if !rcairo_source_dir.nil?
 
   if /mingw|cygwin|mswin32/ =~ RUBY_PLATFORM
     options = {}
@@ -377,6 +377,7 @@ def check_cairo(options={})
   end
 
   $CFLAGS += " -I#{rcairo_source_dir}/ext/cairo"
+  end
   PKGConfig.have_package('cairo') and have_header('rb_cairo.h')
 end
 
