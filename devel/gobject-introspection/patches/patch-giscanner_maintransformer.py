$NetBSD: patch-giscanner_maintransformer.py,v 1.1 2026/01/05 14:49:02 ryoon Exp $

* For building GioUnix too.

--- giscanner/maintransformer.py.orig	2025-12-07 09:37:11.904841636 +0000
+++ giscanner/maintransformer.py
@@ -1215,7 +1215,7 @@ the ones that failed to resolve removed.
             short = short[:-len('_quark')]
             if full == "g_io_error":
                 # Special case; GIOError was already taken forcing GIOErrorEnum
-                assert self._namespace.name == 'Gio'
+                #assert self._namespace.name == 'Gio'
                 enum = self._namespace.get('IOErrorEnum')
             else:
                 enum = self._uscore_type_names.get(short)
