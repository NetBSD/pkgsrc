$NetBSD: patch-salt_modules_status.py,v 1.3 2016/09/19 13:34:37 jperkin Exp $

Avoid a crash in "status.diskusage" when not on Linux or FreeBSD

--- salt/modules/status.py.orig	2016-08-26 18:55:37.000000000 +0000
+++ salt/modules/status.py
@@ -603,6 +603,8 @@ def diskusage(*args):
             ifile = __salt__['cmd.run']('mount -p').splitlines()
         elif __grains__['kernel'] == 'SunOS':
             ifile = __salt__['cmd.run']('mount -p').splitlines()
+        else:
+            ifile = []
 
         for line in ifile:
             comps = line.split()
