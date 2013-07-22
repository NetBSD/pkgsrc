$NetBSD: patch-ext_tk_extconf.rb,v 1.1.2.2 2013/07/22 09:45:19 tron Exp $

* Fix trivial bug fix.

--- ext/tk/extconf.rb.orig	2013-06-26 07:57:49.000000000 +0000
+++ ext/tk/extconf.rb
@@ -315,7 +315,7 @@ def find_macosx_framework
   paths.map{|dir| dir.strip.chomp('/')}.each{|dir|
     next unless File.exist?(File.join(dir, "Tcl.framework", "Headers"))
     next unless File.directory?(tcldir = File.join(dir, "Tcl.framework"))
-    next unless File.exist?(File.join(dir, "Tk.framework"), "Headers")
+    next unless File.exist?(File.join(dir, "Tk.framework", "Headers"))
     next unless File.directory?(tkdir  = File.join(dir, "Tk.framework"))
     TkLib_Config["tcltk-framework"] = dir
     return [tcldir, tkdir]
