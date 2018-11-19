$NetBSD: patch-gajim_____init____.py,v 1.1 2018/11/19 14:50:24 nia Exp $

Do not run `git' to override __version__ and possible inconsistencies in PLIST
due a different ${EGG_INFODIR}.

--- gajim/__init__.py.orig	2018-11-06 20:12:20.000000000 +0000
+++ gajim/__init__.py
@@ -6,12 +6,3 @@ __version__ = "1.1.0"
 IS_FLATPAK = False
 if os.path.exists('/app/share/run-as-flatpak'):
     IS_FLATPAK = True
-
-try:
-    p = subprocess.Popen('git rev-parse --short=12 HEAD', shell=True,
-                         stdout=subprocess.PIPE, stderr=subprocess.DEVNULL)
-    node = p.communicate()[0]
-    if node:
-        __version__ += '+' + node.decode('utf-8').strip()
-except Exception:
-    pass
