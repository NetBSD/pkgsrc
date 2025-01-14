$NetBSD: patch-giscanner_ast.py,v 1.4 2025/01/14 14:40:52 ryoon Exp $

- add double underscore versions

--- giscanner/ast.py.orig	2024-09-13 13:08:54.000000000 +0000
+++ giscanner/ast.py
@@ -351,6 +351,20 @@ type_names['uint32_t'] = TYPE_UINT32
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
+type_names['__gid_t'] = TYPE_GID_T
+type_names['__uid_t'] = TYPE_UID_T
+type_names['__pid_t'] = TYPE_PID_T
+type_names['__socklen_t'] = TYPE_SOCKLEN_T
+
 # A few additional GLib type aliases
 type_names['guchar'] = TYPE_UINT8
 type_names['gchararray'] = TYPE_STRING
