$NetBSD: patch-breezy_bzr_rio.py,v 1.1 2024/10/05 13:34:19 rhialto Exp $

Do NOT try to use Rust if a perfectly good Python implementation is available.

--- breezy/bzr/rio.py.orig	2024-10-03 15:34:05.073511063 +0000
+++ breezy/bzr/rio.py
@@ -341,7 +341,7 @@ def read_patch_stanza(line_iter):
 
 try:
     from ._rio_pyx import _read_stanza_utf8
-    from ._rio_rs import _valid_tag
+    from ._rio_py import _valid_tag
 except ImportError as e:
     osutils.failed_to_load_extension(e)
     from ._rio_py import _read_stanza_utf8, _valid_tag
