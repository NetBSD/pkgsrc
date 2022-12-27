$NetBSD: patch-third__party_python_pyyaml_lib3_yaml_constructor.py,v 1.1 2022/12/27 20:08:45 abs Exp $

Adjust for python 3.10

--- third_party/python/pyyaml/lib3/yaml/constructor.py.orig	2021-07-12 13:35:05.000000000 +0000
+++ third_party/python/pyyaml/lib3/yaml/constructor.py
@@ -123,7 +123,7 @@ class BaseConstructor:
         mapping = {}
         for key_node, value_node in node.value:
             key = self.construct_object(key_node, deep=deep)
-            if not isinstance(key, collections.Hashable):
+            if not isinstance(key, collections.abc.Hashable):
                 raise ConstructorError("while constructing a mapping", node.start_mark,
                         "found unhashable key", key_node.start_mark)
             value = self.construct_object(value_node, deep=deep)
