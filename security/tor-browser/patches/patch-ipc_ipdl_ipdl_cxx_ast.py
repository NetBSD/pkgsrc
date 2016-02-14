$NetBSD: patch-ipc_ipdl_ipdl_cxx_ast.py,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Part of https://bugzilla.mozilla.org/show_bug.cgi?id=1026499:
Make sure storage provided for attributes is properly aligned
in the generated C++ code.

--- ipc/ipdl/ipdl/cxx/ast.py.orig	2014-07-17 01:45:18.000000000 +0000
+++ ipc/ipdl/ipdl/cxx/ast.py
@@ -336,12 +336,13 @@ Type.VOID = Type('void')
 Type.VOIDPTR = Type('void', ptr=1)
 
 class TypeArray(Node):
-    def __init__(self, basetype, nmemb):
-        '''the type |basetype DECLNAME[nmemb]|.  |nmemb| is an Expr'''
+    def __init__(self, basetype, nmemb, alignType):
+        '''the type |basetype DECLNAME[nmemb]|.  |nmemb| is an Expr, |alignType| is a type'''
         self.basetype = basetype
         self.nmemb = nmemb
+        self.alignType = alignType
     def __deepcopy__(self, memo):
-        return TypeArray(deepcopy(self.basetype, memo), nmemb)
+        return TypeArray(deepcopy(self.basetype, memo), nmemb, alignType)
 
 class TypeEnum(Node):
     def __init__(self, name=None):
