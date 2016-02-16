$NetBSD: patch-salt_modules_status.py,v 1.2 2016/02/16 01:52:34 khorben Exp $

Avoid a crash in "status.diskusage" when not on Linux or FreeBSD

--- salt/modules/status.py.orig	2016-02-01 19:40:31.000000000 +0000
+++ salt/modules/status.py
@@ -457,6 +457,8 @@ def diskusage(*args):
             ifile = salt.utils.fopen(procf, 'r').readlines()
         elif __grains__['kernel'] == 'FreeBSD':
             ifile = __salt__['cmd.run']('mount -p').splitlines()
+        else:
+            ifile = []
 
         for line in ifile:
             comps = line.split()
