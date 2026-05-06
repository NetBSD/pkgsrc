$NetBSD: patch-lib_erb.rb,v 1.1 2026/05/06 05:15:35 taca Exp $

Update to erb 4.0.4.1 to fix CVE-2026-41316.

--- lib/erb.rb.orig	2026-03-11 09:51:47.000000000 +0000
+++ lib/erb.rb
@@ -463,6 +463,9 @@ class ERB
   #   erb.def_method(MyClass, 'render(arg1, arg2)', filename)
   #   print MyClass.new.render('foo', 123)
   def def_method(mod, methodname, fname='(ERB)')
+    unless @_init.equal?(self.class.singleton_class)
+      raise ArgumentError, "not initialized"
+    end
     src = self.src.sub(/^(?!#|$)/) {"def #{methodname}\n"} << "\nend\n"
     mod.module_eval do
       eval(src, binding, fname, -1)
