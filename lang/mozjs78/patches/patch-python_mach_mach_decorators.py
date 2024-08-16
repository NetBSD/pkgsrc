$NetBSD: patch-python_mach_mach_decorators.py,v 1.1 2024/08/16 10:20:40 nia Exp $

These python libraries were moved out of "collections" and their
original locations were deprecated.

--- python/mach/mach/decorators.py.orig	2024-08-16 10:13:24.175350287 +0000
+++ python/mach/mach/decorators.py
@@ -140,7 +140,7 @@ def CommandProvider(cls):
               'Conditions argument must take a list ' + \
               'of functions. Found %s instead.'
 
-        if not isinstance(command.conditions, collections.Iterable):
+        if not isinstance(command.conditions, collections.abc.Iterable):
             msg = msg % (command.name, type(command.conditions))
             raise MachError(msg)
 
