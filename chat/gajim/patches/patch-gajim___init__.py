$NetBSD: patch-gajim___init__.py,v 1.2 2021/08/10 12:03:37 nia Exp $

Make Gajim not pick up the pkgsrc revision when pkgsrc is checked out via Git.

--- gajim/__init__.py.orig	2021-04-24 11:27:40.000000000 +0000
+++ gajim/__init__.py
@@ -8,12 +8,3 @@ IS_FLATPAK = Path('/app/share/run-as-fla
 
 portable_path = Path(sys.executable).parent / 'is_portable'
 IS_PORTABLE = portable_path.exists()
-
-try:
-    p = subprocess.Popen('git rev-parse --short=12 HEAD', shell=True,
-                         stdout=subprocess.PIPE, stderr=subprocess.DEVNULL)
-    node = p.communicate()[0]
-    if node:
-        __version__ += '+' + node.decode('utf-8').strip()
-except Exception:
-    pass
