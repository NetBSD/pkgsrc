$NetBSD: patch-third__party_python_voluptuous_voluptuous_schema__builder.py,v 1.1 2022/12/27 20:08:45 abs Exp $

Adjust for python 3.10

--- third_party/python/voluptuous/voluptuous/schema_builder.py.orig	2021-07-12 13:35:05.000000000 +0000
+++ third_party/python/voluptuous/voluptuous/schema_builder.py
@@ -280,7 +280,7 @@ class Schema(object):
             return schema.__voluptuous_compile__(self)
         if isinstance(schema, Object):
             return self._compile_object(schema)
-        if isinstance(schema, collections.Mapping):
+        if isinstance(schema, collections.abc.Mapping):
             return self._compile_dict(schema)
         elif isinstance(schema, list):
             return self._compile_list(schema)
