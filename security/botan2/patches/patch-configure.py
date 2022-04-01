$NetBSD: patch-configure.py,v 1.1 2022/04/01 08:01:12 wiz Exp $

Leave pkgsrc to handle security features.

--- configure.py.orig	2019-07-01 10:23:16.000000000 +0000
+++ configure.py
@@ -1266,9 +1266,6 @@ class CompilerInfo(InfoObject): # pylint
         if options.msvc_runtime:
             abi_link.add("/" + options.msvc_runtime)
 
-        if options.with_stack_protector and self.stack_protector_flags != '':
-            abi_link.add(self.stack_protector_flags)
-
         if options.with_coverage_info:
             if self.coverage_flags == '':
                 raise UserError('No coverage handling for %s' % (self.basename))
