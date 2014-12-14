$NetBSD: patch-ext_tk_extconf.rb,v 1.3 2014/12/14 14:00:06 taca Exp $

* Add tcl/tk 8.6 support.

--- ext/tk/extconf.rb.orig	2014-02-02 12:51:14.000000000 +0000
+++ ext/tk/extconf.rb
@@ -9,10 +9,10 @@ TkLib_Config['search_versions'] =
   # %w[8.9 8.8 8.7 8.6 8.5 8.4 8.3 8.2 8.1 8.0 7.6 4.2]
   # %w[8.7 8.6 8.5 8.4 8.3 8.2 8.1 8.0]
   # %w[8.7 8.6 8.5 8.4 8.0] # to shorten search steps
-  %w[8.5 8.4] # At present, Tcl/Tk8.6 is not supported.
+  %w[8.6 8.5 8.4]
 
 TkLib_Config['unsupported_versions'] =
-  %w[8.8 8.7 8.6] # At present, Tcl/Tk8.6 is not supported.
+  %w[8.8 8.7]
 
 TkLib_Config['major_nums'] = '87'
 
