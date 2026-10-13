$NetBSD: patch-src__c_cython_pygame___sprite.pyx,v 1.1 2026/10/13 09:06:47 wiz Exp $

Python 3.15 support.
https://github.com/pygame/pygame/issues/4716

--- src_c/cython/pygame/_sprite.pyx.orig	2024-09-29 12:15:28.005112000 +0000
+++ src_c/cython/pygame/_sprite.pyx
@@ -145,7 +145,6 @@ cdef class Sprite:
     cdef dict __dict__
 
     def __cinit__(self):
-        self.__dict__ = {}
         self.__g = set() # The groups the sprite is in
 
     def __init__(self, *groups):
