$NetBSD: patch-setupbase.py,v 1.3 2019/08/03 12:31:47 adam Exp $

Honor PKGMANDIR

--- setupbase.py.orig	2019-07-26 21:57:01.000000000 +0000
+++ setupbase.py
@@ -162,10 +162,7 @@ def find_data_files():
     Just man pages at this point.
     """
 
-    if "freebsd" in sys.platform:
-        manpagebase = pjoin('man', 'man1')
-    else:
-        manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin(os.environ.get('PKGMANDIR'), 'man1')
 
     # Simple file lists can be made by hand
     manpages = [f for f in glob(pjoin('docs','man','*.1.gz')) if isfile(f)]
