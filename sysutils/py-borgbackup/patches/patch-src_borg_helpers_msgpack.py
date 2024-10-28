$NetBSD: patch-src_borg_helpers_msgpack.py,v 1.3 2024/10/28 09:59:34 he Exp $

Permit newer versions of msgpack.

--- src/borg/helpers/msgpack.py.orig	2024-03-12 09:32:37.673913724 +0000
+++ src/borg/helpers/msgpack.py
@@ -182,7 +182,7 @@ def is_slow_msgpack():
 def is_supported_msgpack():
     # DO NOT CHANGE OR REMOVE! See also requirements and comments in setup.py.
     import msgpack
-    return (0, 5, 6) <= msgpack.version <= (1, 0, 8) and \
+    return (0, 5, 6) <= msgpack.version <= (1, 1, 0) and \
            msgpack.version not in [(1, 0, 1), ]  # < add bad releases here to deny list
 
 
