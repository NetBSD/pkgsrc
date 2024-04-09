$NetBSD: patch-giscanner_ast.py,v 1.3 2024/04/09 17:55:46 wiz Exp $

- add double underscore versions

--- giscanner/ast.py.orig	2022-09-17 18:52:38.000000000 +0000
+++ giscanner/ast.py
@@ -307,6 +307,16 @@ type_names['uint32_t'] = TYPE_UINT32
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
+type_names['__off_t'] = TYPE_OFF_T
+
 # A few additional GLib type aliases
 type_names['guchar'] = TYPE_UINT8
 type_names['gchararray'] = TYPE_STRING
