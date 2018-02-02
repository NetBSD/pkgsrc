$NetBSD: patch-configure.py,v 1.1 2018/02/02 13:56:35 jperkin Exp $

Leave pkgsrc to handle security features.

--- configure.py.orig	2017-04-05 01:09:22.000000000 +0000
+++ configure.py
@@ -1060,7 +1060,7 @@ class CompilerInfo(InfoObject): # pylint
             if flag != None and flag != '' and flag not in abi_link:
                 abi_link.append(flag)
 
-        if options.with_stack_protector and self.stack_protector_flags != '':
+        if options.with_stack_protector and self.stack_protector_flags != '' and False:
             abi_link.append(self.stack_protector_flags)
 
         if options.with_coverage_info:
