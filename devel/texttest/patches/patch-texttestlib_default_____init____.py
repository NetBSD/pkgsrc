$NetBSD: patch-texttestlib_default_____init____.py,v 1.1 2020/04/18 19:42:18 schmonz Exp $

Find pkgsrc-provided diff tools.

--- texttestlib/default/__init__.py.orig	2020-03-23 09:09:04.000000000 +0000
+++ texttestlib/default/__init__.py
@@ -1422,7 +1422,7 @@ class Config:
     def defaultDiffProgram(self):
         if os.name == "posix":
             for diff in ('tkdiff', 'kdiff3', 'meld'):
-                for prefix in ("/usr/bin", "/usr/local/bin"):
+                for prefix in ("/usr/bin", "@PREFIX@/bin", "/usr/local/bin"):
                     path = os.path.join(prefix, diff)
                     if os.path.exists(path):
                         return path
