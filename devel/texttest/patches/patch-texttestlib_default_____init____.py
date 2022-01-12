$NetBSD: patch-texttestlib_default_____init____.py,v 1.2 2022/01/12 09:47:24 schmonz Exp $

Find pkgsrc-provided diff tools.

--- texttestlib/default/__init__.py.orig	2021-11-26 07:53:10.000000000 +0000
+++ texttestlib/default/__init__.py
@@ -1425,7 +1425,7 @@ class Config:
     def defaultDiffProgram(self):
         if os.name == "posix":
             for diff in ('tkdiff', 'kdiff3', 'meld'):
-                for prefix in ("/usr/bin", "/usr/local/bin"):
+                for prefix in ("/usr/bin", "@PREFIX@/bin", "/usr/local/bin"):
                     path = os.path.join(prefix, diff)
                     if os.path.exists(path):
                         return path
