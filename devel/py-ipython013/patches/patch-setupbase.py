$NetBSD: patch-setupbase.py,v 1.1 2012/12/17 11:57:44 drochner Exp $

--- setupbase.py.orig	2012-10-21 00:30:54.000000000 +0000
+++ setupbase.py
@@ -201,7 +201,7 @@ def find_data_files():
     """
 
     docdirbase  = pjoin('share', 'doc', 'ipython')
-    manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin(os.environ.get('PKGMANDIR'), 'man1')
 
     # Simple file lists can be made by hand
     manpages = [f for f in glob(pjoin('docs','man','*.1.gz')) if isfile(f)]
