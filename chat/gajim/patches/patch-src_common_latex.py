$NetBSD: patch-src_common_latex.py,v 1.1 2012/04/17 20:57:09 gls Exp $

CVE-2012-2093: improve temp file search when using latex to prevent overwriting files
Taken from upstream repository: https://trac.gajim.org/changeset/13759/src/common/latex.py

--- src/common/latex.py.orig	2012-03-18 11:25:56.000000000 +0000
+++ src/common/latex.py
@@ -59,8 +59,19 @@ def check_blacklist(str_):
 
 def get_tmpfile_name():
     random.seed()
-    int_ = random.randint(0, 100)
-    return os.path.join(gettempdir(), 'gajimtex_' + int_.__str__())
+    while(nb < 100):
+        int_ = random.randint(0, 10000)
+        filename = os.path.join(gettempdir(), 'gajimtex_' + int_.__str__())
+        # Check if a file to not overwrite it
+        ok = True
+        extensions = ['.tex', '.log', '.aux', '.dvi']
+        for ext in extensions:
+            if os.path.exists(filename + ext):
+                ok = False
+                break
+        if ok:
+            return filename
+    return filename
 
 def write_latex(filename, str_):
     texstr = '\\documentclass[12pt]{article}\\usepackage[dvips]{graphicx}'
