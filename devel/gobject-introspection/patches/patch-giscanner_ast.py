$NetBSD: patch-giscanner_ast.py,v 1.1 2019/06/03 10:47:20 prlw1 Exp $

- add double underscore versions
- 32/64-bit time_t fix

--- giscanner/ast.py.orig	2019-01-06 10:32:10.000000000 +0000
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
@@ -344,7 +353,7 @@ type_names['FILE*'] = TYPE_ANY
 # integers it's easy enough to expand them.
 type_names['size_t'] = type_names['gsize']
 type_names['ssize_t'] = type_names['gssize']
-type_names['time_t'] = TYPE_LONG
+type_names['time_t'] = @TIMET_TYPENAME@
 type_names['off_t'] = type_names['gsize']
 type_names['pid_t'] = TYPE_INT
 type_names['uid_t'] = TYPE_UINT
