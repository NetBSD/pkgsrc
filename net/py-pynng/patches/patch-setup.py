$NetBSD: patch-setup.py,v 1.1 2021/05/13 19:35:54 khorben Exp $

Fix build on NetBSD

--- setup.py.orig	2021-03-27 21:43:27.000000000 +0000
+++ setup.py
@@ -44,6 +44,7 @@ def build_mbedtls(cmake_args):
     cmake_cmd = ['cmake'] + cmake_args
     cmake_cmd += [
         '-DENABLE_PROGRAMS=OFF',
+        '-DENABLE_TESTING=OFF',
         '-DCMAKE_BUILD_TYPE=Release',
         '-DCMAKE_INSTALL_PREFIX=../prefix',
         '..'
