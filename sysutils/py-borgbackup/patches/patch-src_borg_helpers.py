$NetBSD: patch-src_borg_helpers.py,v 1.1 2020/01/01 18:21:49 bsiegert Exp $

Do not use the bundled msgpack.

--- src/borg/helpers.py.orig	2019-05-16 02:58:15.000000000 +0000
+++ src/borg/helpers.py
@@ -55,7 +55,7 @@ from shutil import get_terminal_size
 #   any feedback related to issues caused by this will be ignored.
 # - especially, it is known that msgpack 0.6.x does NOT work for borg 1.1.x.
 
-prefer_system_msgpack = False
+prefer_system_msgpack = True
 
 try:
     if prefer_system_msgpack:
