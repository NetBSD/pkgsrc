$NetBSD: patch-ipc_ipdl_ipdl_lower.py,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Part of https://bugzilla.mozilla.org/show_bug.cgi?id=1026499:
Make sure storage provided for attributes is properly aligned
in the generated C++ code.

--- ipc/ipdl/ipdl/lower.py.orig	2014-07-17 01:45:18.000000000 +0000
+++ ipc/ipdl/ipdl/lower.py
@@ -768,7 +768,7 @@ IPDL union type."""
         if self.recursive:
             return self.ptrToType()
         else:
-            return TypeArray(Type('char'), ExprSizeof(self.internalType()))
+            return TypeArray(Type('char'), ExprSizeof(self.internalType()), self.internalType())
 
     def unionValue(self):
         # NB: knows that Union's storage C union is named |mValue|
