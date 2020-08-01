$NetBSD: patch-gajim___init__.py,v 1.1 2020/08/01 12:40:10 js Exp $

Make Gajim not pick up the pkgsrc revision when pkgsrc is checked out via Git.

--- gajim/__init__.py.orig	2020-08-01 12:32:50.000000000 +0000
+++ gajim/__init__.py
@@ -11,12 +11,3 @@ IS_PORTABLE = False
 portable_path = os.path.join(os.getcwd(), 'is_portable')
 if os.path.exists(portable_path):
     IS_PORTABLE = True
-
-try:
-    p = subprocess.Popen('git rev-parse --short=12 HEAD', shell=True,
-                         stdout=subprocess.PIPE, stderr=subprocess.DEVNULL)
-    node = p.communicate()[0]
-    if node:
-        __version__ += '+' + node.decode('utf-8').strip()
-except Exception:
-    pass
