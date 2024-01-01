$NetBSD: patch-passlib_handlers_bcrypt.py,v 1.1 2024/01/01 16:19:57 leot Exp $

Version is available under __version__, __about__ field no longer
exists.

--- passlib/handlers/bcrypt.py.orig	2024-01-01 16:12:38.252193463 +0000
+++ passlib/handlers/bcrypt.py
@@ -617,7 +617,7 @@ class _BcryptBackend(_BcryptCommon):
         except ImportError: # pragma: no cover
             return False
         try:
-            version = _bcrypt.__about__.__version__
+            version = _bcrypt.__version__
         except:
             log.warning("(trapped) error reading bcrypt version", exc_info=True)
             version = '<unknown>'
