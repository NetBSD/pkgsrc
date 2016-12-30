$NetBSD: patch-setup.py,v 1.1 2016/12/30 23:23:20 maya Exp $

Don't be so specific about py-cryptodome version dependency.

--- setup.py.orig	2016-12-17 00:41:21.000000000 +0000
+++ setup.py
@@ -38,7 +38,7 @@ else:
     deps.append("requests>=1.0,!=2.12.0,!=2.12.1,<3.0")
 
 # this version of pycryptodome is known to work and has a Windows wheel for py2.7, py3.3-3.5
-deps.append("pycryptodome==3.4.3")
+deps.append("pycryptodome>=3.4.3")
 
 # When we build an egg for the Win32 bootstrap we don't want dependency
 # information built into it.
