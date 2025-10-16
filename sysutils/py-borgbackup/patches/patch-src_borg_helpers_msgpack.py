$NetBSD: patch-src_borg_helpers_msgpack.py,v 1.5 2025/10/16 21:30:21 he Exp $

Permit newer versions of msgpack than what's originally
declared by upstream.

--- src/borg/helpers/msgpack.py.orig	2024-03-12 09:32:37.673913724 +0000
+++ src/borg/helpers/msgpack.py
@@ -137,7 +137,7 @@ def is_slow_msgpack():
 def is_supported_msgpack():
     # DO NOT CHANGE OR REMOVE! See also requirements and comments in pyproject.toml.
     import msgpack
-    return (1, 0, 3) <= msgpack.version <= (1, 1, 0) and \
+    return (1, 0, 3) <= msgpack.version <= (1, 1, 2) and \
            msgpack.version not in []  # < add bad releases here to deny list
 
 
