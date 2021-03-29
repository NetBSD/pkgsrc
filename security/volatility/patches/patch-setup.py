$NetBSD: patch-setup.py,v 1.1 2021/03/29 07:58:53 adam Exp $

Do not install extra files.

--- setup.py.orig	2021-03-29 07:52:47.000000000 +0000
+++ setup.py
@@ -72,7 +72,6 @@ opts['packages'] = ["volatility",
                     "volatility.plugins.registry",
                     "volatility.plugins.malware", 
                     "volatility.plugins.mac"]
-opts['data_files'] = find_files(['contrib'], py = True) + find_files(['tools'])
 
 if py2exe_available:
     py2exe_distdir = 'dist/py2exe'
