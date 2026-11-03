$NetBSD: patch-src_borg_helpers_msgpack.py,v 1.9 2026/11/03 20:22:01 bsiegert Exp $

Support newer msgpack.
https://github.com/borgbackup/borg/commit/144a83ba8e30ad7edb2fb9512ccc276008c67074
--- src/borg/helpers/msgpack.py.orig	2026-11-03 20:14:48.773039630 +0000
+++ src/borg/helpers/msgpack.py
@@ -145,7 +145,7 @@ def is_supported_msgpack():
     version_check = os.environ.get('BORG_MSGPACK_VERSION_CHECK', 'yes').strip().lower()
 
     return version_check == 'no' or (
-        (1, 0, 3) <= msgpack.version[:3] <= (1, 2, 1) and
+        (1, 0, 3) <= msgpack.version[:3] <= (1, 2, 4) and
         msgpack.version not in []
     )
 
