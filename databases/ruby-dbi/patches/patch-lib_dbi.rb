$NetBSD: patch-lib_dbi.rb,v 1.1 2011/08/12 15:58:36 taca Exp $

* Don't use Deprecate since it would be conflict with newer rubygems.

--- lib/dbi.rb.orig	2011-08-09 05:56:50.000000000 +0000
+++ lib/dbi.rb
@@ -69,7 +69,7 @@ class Class
     end
 end
 
-Deprecate.set_action(
+Deprecated.set_action(
     proc do |call|
         klass, meth = call.split(/[#.]/)
         klass = klass.split(/::/).inject(Module) { |a,x| a.const_get(x) }
@@ -83,7 +83,7 @@ Deprecate.set_action(
             warn "ColumnInfo methods that do not match a component are deprecated and will eventually be removed"
         end
 
-        warn "You may change the result of calling deprecated code via Deprecate.set_action; Trace follows:"
+        warn "You may change the result of calling deprecated code via Deprecated.set_action; Trace follows:"
         warn caller[2..-1].join("\n")
     end
 )
