$NetBSD: patch-bcrypt_____init____.py,v 1.2 2015/04/25 13:49:49 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- bcrypt/__init__.py.orig	2015-03-14 02:18:59.000000000 +0000
+++ bcrypt/__init__.py
@@ -50,7 +50,8 @@ def _create_modulename(cdef_sources, sou
     k1 = k1.lstrip('0x').rstrip('L')
     k2 = hex(binascii.crc32(key[1::2]) & 0xffffffff)
     k2 = k2.lstrip('0').rstrip('L')
-    return '_bcrypt_cffi_{0}{1}'.format(k1, k2)
+    #return '_bcrypt_cffi_{0}{1}'.format(k1, k2)
+    return '_bcrypt_cffi'
 
 
 def _compile_module(*args, **kwargs):
