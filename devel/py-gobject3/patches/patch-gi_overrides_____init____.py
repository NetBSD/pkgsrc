$NetBSD: patch-gi_overrides_____init____.py,v 1.1 2026/05/18 06:31:37 wiz Exp $

De-duplicate deprecations of module attributes

This allows generically deprecating a set of symbols (e.g., everything
in `GLibUnix` that's in `GLib`) and then providing a more-specific
deprecation for special symbols (e.g., `GLib.unix_signal_add_full`),
without triggering a deprecation from the first when making the second.

Backport of !545.

https://gitlab.gnome.org/GNOME/pygobject/-/commit/aa9dfd205e14d10d9e8850049853f079b272c54c

--- gi/overrides/__init__.py.orig	2026-05-08 20:10:32.000000000 +0000
+++ gi/overrides/__init__.py
@@ -14,7 +14,7 @@ __path__ = extend_path(__path__, __name__)
 __path__ = extend_path(__path__, __name__)
 
 
-# namespace -> (attr, replacement)
+# namespace -> {attr -> replacement}
 _deprecated_attrs = {}
 
 
@@ -154,7 +154,7 @@ def load_overrides(introspection_module):
 
     # Replace deprecated module level attributes with a descriptor
     # which emits a warning when accessed.
-    for attr, replacement in _deprecated_attrs.pop(namespace, []):
+    for attr, replacement in _deprecated_attrs.pop(namespace, {}).items():
         try:
             value = getattr(proxy, attr)
         except AttributeError:
@@ -252,7 +252,7 @@ def deprecated_attr(namespace, attr, replacement):
     :param str replacement:
         The replacement text which will be included in the warning.
     """
-    _deprecated_attrs.setdefault(namespace, []).append((attr, replacement))
+    _deprecated_attrs.setdefault(namespace, {})[attr] = replacement
 
 
 def deprecated_init(
