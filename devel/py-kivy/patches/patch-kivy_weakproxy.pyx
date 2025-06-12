$NetBSD: patch-kivy_weakproxy.pyx,v 1.1 2025/06/12 07:29:05 wiz Exp $

https://github.com/kivy/kivy/commit/5a1b27d7d3bdee6cedb55440bfae9c4e66fb3c68

--- kivy/weakproxy.pyx.orig	2024-12-26 16:04:18.000000000 +0000
+++ kivy/weakproxy.pyx
@@ -253,9 +253,6 @@ cdef class WeakProxy(object):
     def __int__(self):
         return int(self.__ref__())
 
-    def __long__(self):
-        return long(self.__ref__())
-
     def __float__(self):
         return float(self.__ref__())
 
