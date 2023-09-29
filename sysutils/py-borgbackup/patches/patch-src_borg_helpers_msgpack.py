$NetBSD: patch-src_borg_helpers_msgpack.py,v 1.1 2023/09/29 08:10:33 wiz Exp $

Allow msgpack up to 1.0.7.
Loosely based on
https://github.com/borgbackup/borg/commit/cdcab4df6851b5d3da6ac5435bcaeb8aa1d632b5

--- src/borg/helpers/msgpack.py.orig	2023-08-31 21:08:57.000000000 +0000
+++ src/borg/helpers/msgpack.py
@@ -182,7 +182,7 @@ def is_slow_msgpack():
 def is_supported_msgpack():
     # DO NOT CHANGE OR REMOVE! See also requirements and comments in setup.py.
     import msgpack
-    return (0, 5, 6) <= msgpack.version <= (1, 0, 5) and \
+    return (0, 5, 6) <= msgpack.version <= (1, 0, 7) and \
            msgpack.version not in [(1, 0, 1), ]  # < add bad releases here to deny list
 
 
