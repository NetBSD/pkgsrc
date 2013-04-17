$NetBSD: patch-Include_node.h,v 1.1 2013/04/17 13:21:05 obache Exp $

* _PyNode_SizeOf is used by parsermodule

--- Include/node.h.orig	2013-04-06 14:02:25.000000000 +0000
+++ Include/node.h
@@ -21,7 +21,7 @@ PyAPI_FUNC(int) PyNode_AddChild(node *n,
                                       char *str, int lineno, int col_offset);
 PyAPI_FUNC(void) PyNode_Free(node *n);
 #ifndef Py_LIMITED_API
-Py_ssize_t _PyNode_SizeOf(node *n);
+PyAPI_FUNC(Py_ssize_t) _PyNode_SizeOf(node *n);
 #endif
 
 /* Node access functions */
