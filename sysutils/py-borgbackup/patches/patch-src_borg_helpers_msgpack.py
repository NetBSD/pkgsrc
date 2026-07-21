$NetBSD: patch-src_borg_helpers_msgpack.py,v 1.7 2026/07/21 14:10:28 he Exp $

Bump acceptance of py-msgpack versions.

--- src/borg/helpers/msgpack.py.orig	2026-07-21 13:34:08.463330946 +0000
+++ src/borg/helpers/msgpack.py
@@ -145,7 +145,7 @@ def is_supported_msgpack():
     version_check = os.environ.get('BORG_MSGPACK_VERSION_CHECK', 'yes').strip().lower()
 
     return version_check == 'no' or (
-        (1, 0, 3) <= msgpack.version[:3] <= (1, 1, 2) and
+        (1, 0, 3) <= msgpack.version[:3] <= (1, 2, 1) and
         msgpack.version not in []
     )
 
