$NetBSD: patch-setupbase.py,v 1.1.1.1 2012/01/29 13:22:52 obache Exp $

* honor PKGMANDIR
* let not to install compressed man pages.

--- setupbase.py.orig	2010-10-12 07:13:29.000000000 +0000
+++ setupbase.py
@@ -188,10 +188,10 @@ def find_data_files():
     """
     
     docdirbase  = 'share/doc/ipython'
-    manpagebase = 'share/man/man1'
+    manpagebase = os.environ.get('PKGMANDIR') + '/man1'
 
     # Simple file lists can be made by hand
-    manpages  = filter(isfile, glob('docs/man/*.1.gz'))
+    manpages  = filter(isfile, glob('docs/man/*.1'))
     igridhelpfiles = filter(isfile, glob('IPython/Extensions/igrid_help.*'))
 
     # For nested structures, use the utility above
