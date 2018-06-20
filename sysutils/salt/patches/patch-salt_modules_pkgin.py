$NetBSD: patch-salt_modules_pkgin.py,v 1.1 2018/06/20 11:50:56 tpaul Exp $

Fixes 2 bugs in the pkgin module:
- pkg.latest_version doesn't return a version for an uninstalled package.
- pkg.file_dict crashes.
https://github.com/saltstack/salt/pull/47814
PR: pkg/53344

--- salt/modules/pkgin.py.orig	2018-04-02 16:35:12.000000000 +0000
+++ salt/modules/pkgin.py
@@ -181,7 +181,9 @@ def latest_version(*names, **kwargs):
 
         out = __salt__['cmd.run'](cmd, output_loglevel='trace')
         for line in out.splitlines():
-            p = line.split(',' if _supports_parsing() else None)
+            if line.startswith('No results found for'):
+                return pkglist 
+            p = line.split(';' if _supports_parsing() else None)
 
             if p and p[0] in ('=:', '<:', '>:', ''):
                 # These are explanation comments
@@ -190,7 +192,7 @@ def latest_version(*names, **kwargs):
                 s = _splitpkg(p[0])
                 if s:
                     if not s[0] in pkglist:
-                        if len(p) > 1 and p[1] == '<':
+                        if len(p) > 1 and p[1] in ('<', '', '='):
                             pkglist[s[0]] = s[1]
                         else:
                             pkglist[s[0]] = ''
@@ -681,7 +683,7 @@ def file_dict(*packages):
                 continue  # unexpected string
 
     ret = {'errors': errors, 'files': files}
-    for field in ret:
+    for field in list(ret):
         if not ret[field] or ret[field] == '':
             del ret[field]
     return ret
