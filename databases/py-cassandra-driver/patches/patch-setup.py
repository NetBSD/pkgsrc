$NetBSD: patch-setup.py,v 1.3 2026/02/19 08:21:09 wiz Exp $

https://github.com/apache/cassandra-python-driver/pull/1268

--- setup.py.orig	2026-02-19 08:12:40.769479372 +0000
+++ setup.py
@@ -16,9 +16,6 @@ import warnings
 import sys
 import warnings
 
-import ez_setup
-ez_setup.use_setuptools()
-
 from setuptools import setup
 from distutils.command.build_ext import build_ext
 from distutils.core import Extension
