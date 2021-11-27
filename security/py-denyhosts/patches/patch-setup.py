$NetBSD: patch-setup.py,v 1.1 2021/11/27 14:28:10 he Exp $

Adapt for pkgsrc.

--- setup.py.orig	2015-06-27 16:22:43.000000000 +0000
+++ setup.py
@@ -10,9 +10,9 @@ from distutils.core import setup
 from DenyHosts.util import normalize_whitespace
 from DenyHosts.version import VERSION
 
-etcpath = "/etc"
-manpath = "/usr/share/man/man8"
-libpath = "/usr/share/denyhosts"
+etcpath = "@PKG_SYSCONFDIR@"
+manpath = "@PREFIX@/@PKGMANDIR@/man8"
+libpath = "@PREFIX@/share/denyhosts"
 scriptspath = ospj("scripts", libpath)
 pluginspath = ospj("plugins", libpath)
 
