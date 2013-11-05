$NetBSD: patch-setup.py,v 1.1 2013/11/05 17:37:48 joerg Exp $

--- setup.py.orig	2013-11-05 08:00:38.000000000 +0000
+++ setup.py
@@ -1,6 +1,7 @@
 #!/usr/bin/env python
 import os, subprocess, re
-from distutils.core import setup, Command
+from setuptools import setup
+from distutils.core import Command
 from distutils.command.sdist import sdist as _sdist
 from ecdsa.six import print_
 
