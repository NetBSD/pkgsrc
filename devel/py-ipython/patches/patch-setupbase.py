$NetBSD: patch-setupbase.py,v 1.2 2014/04/20 10:06:22 imil Exp $

Honor PKGMANDIR

--- setupbase.py.orig	2014-04-02 05:31:02.000000000 +0000
+++ setupbase.py
@@ -272,7 +272,7 @@ def find_data_files():
     Just man pages at this point.
     """
 
-    manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin(os.environ.get('PKGMANDIR'), 'man1')
 
     # Simple file lists can be made by hand
     manpages = [f for f in glob(pjoin('docs','man','*.1.gz')) if isfile(f)]
