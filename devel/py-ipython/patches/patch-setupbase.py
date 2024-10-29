$NetBSD: patch-setupbase.py,v 1.4 2024/10/29 20:11:49 adam Exp $

Honor PKGMANDIR

--- setupbase.py.orig	2024-10-25 08:39:51.000000000 +0000
+++ setupbase.py
@@ -93,10 +93,7 @@ def find_data_files():
     Just man pages at this point.
     """
 
-    if "freebsd" in sys.platform:
-        manpagebase = Path("man") / "man1"
-    else:
-        manpagebase = Path("share") / "man" / "man1"
+    manpagebase = Path(os.environ.get("PKGMANDIR")) / "man1"
 
     # Simple file lists can be made by hand
     manpages = [f for f in Path("docs/man").glob("*.1.gz") if f.is_file()]
