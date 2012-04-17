$NetBSD: patch-setupbase.py,v 1.1.1.1 2012/04/17 17:45:40 drochner Exp $

--- setupbase.py.orig	2011-12-19 01:25:33.000000000 +0000
+++ setupbase.py
@@ -197,7 +197,7 @@ def find_data_files():
     """
 
     docdirbase  = pjoin('share', 'doc', 'ipython')
-    manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin(os.environ.get('PKGMANDIR'), 'man1')
 
     # Simple file lists can be made by hand
     manpages  = filter(isfile, glob(pjoin('docs','man','*.1.gz')))
