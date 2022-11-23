$NetBSD: patch-giscanner_ast.py,v 1.2 2022/11/23 10:56:40 adam Exp $

- add double underscore versions
- 32/64-bit time_t fix

--- giscanner/ast.py.orig	2022-09-17 18:52:38.000000000 +0000
+++ giscanner/ast.py
@@ -307,6 +307,15 @@ type_names['uint32_t'] = TYPE_UINT32
 type_names['int64_t'] = TYPE_INT64
 type_names['uint64_t'] = TYPE_UINT64
 
+type_names['__int8_t'] = TYPE_INT8
+type_names['__uint8_t'] = TYPE_UINT8
+type_names['__int16_t'] = TYPE_INT16
+type_names['__uint16_t'] = TYPE_UINT16
+type_names['__int32_t'] = TYPE_INT32
+type_names['__uint32_t'] = TYPE_UINT32
+type_names['__int64_t'] = TYPE_INT64
+type_names['__uint64_t'] = TYPE_UINT64
+
 # A few additional GLib type aliases
 type_names['guchar'] = TYPE_UINT8
 type_names['gchararray'] = TYPE_STRING
@@ -346,7 +355,7 @@ type_names['size_t'] = type_names['gsize
 type_names['ssize_t'] = type_names['gssize']
 type_names['uintptr_t'] = type_names['guintptr']
 type_names['intptr_t'] = type_names['gintptr']
-type_names['time_t'] = TYPE_LONG
+type_names['time_t'] = @TIMET_TYPENAME@
 type_names['off_t'] = type_names['gsize']
 type_names['pid_t'] = TYPE_INT
 type_names['uid_t'] = TYPE_UINT
