$NetBSD: patch-setup.py,v 1.1 2021/05/15 09:50:08 nia Exp $

Install desktop files on all operating systems.

--- setup.py.orig	2000-11-11 11:11:11.000000000 +0000
+++ setup.py
@@ -32,7 +32,7 @@ version_spec.loader.exec_module(version_
 
 data_files = []
 
-if platform.system() in ['Linux', 'FreeBSD', 'DragonFly']:
+if True:
     parser = argparse.ArgumentParser()
     parser.add_argument('--root=', dest='root_path', metavar='dir', default='/')
     opts, _ = parser.parse_known_args(sys.argv[1:])
