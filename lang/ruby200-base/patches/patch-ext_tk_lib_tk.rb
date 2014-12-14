$NetBSD: patch-ext_tk_lib_tk.rb,v 1.1 2014/12/14 14:00:06 taca Exp $

* Add tcl/tk 8.6 support.

--- ext/tk/lib/tk.rb.orig	2011-05-26 23:36:33.000000000 +0000
+++ ext/tk/lib/tk.rb
@@ -1309,8 +1309,12 @@ EOS
           end
 
           unless interp.deleted?
-            #Thread.current[:status].value = TclTkLib.mainloop(false)
-            Thread.current[:status].value = interp.mainloop(false)
+            begin
+              #Thread.current[:status].value = TclTkLib.mainloop(false)
+              Thread.current[:status].value = interp.mainloop(false)
+            rescue Exception=>e
+              puts "ignore exception on interp: #{e.inspect}\n" if $DEBUG
+            end
           end
 
         ensure
@@ -1569,7 +1573,15 @@ EOS
   EOL
 =end
 
-  at_exit{ INTERP.remove_tk_procs(TclTkLib::FINALIZE_PROC_NAME) }
+  if !WITH_RUBY_VM || RUN_EVENTLOOP_ON_MAIN_THREAD ### check Ruby 1.9 !!!!!!!
+    at_exit{ INTERP.remove_tk_procs(TclTkLib::FINALIZE_PROC_NAME) }
+  else
+    at_exit{
+      Tk.root.destroy
+      INTERP.remove_tk_procs(TclTkLib::FINALIZE_PROC_NAME)
+      INTERP_THREAD.kill.join
+    }
+  end
 
   EventFlag = TclTkLib::EventFlag
 
@@ -5197,6 +5209,8 @@ class TkWindow<TkObject
     TkWinfo.exist?(self)
   end
 
+  alias subcommand tk_send
+
   def bind_class
     @db_class || self.class()
   end
@@ -5742,7 +5756,7 @@ TkWidget = TkWindow
 #Tk.freeze
 
 module Tk
-  RELEASE_DATE = '2010-06-03'.freeze
+  RELEASE_DATE = '2014-10-19'.freeze
 
   autoload :AUTO_PATH,        'tk/variable'
   autoload :TCL_PACKAGE_PATH, 'tk/variable'
