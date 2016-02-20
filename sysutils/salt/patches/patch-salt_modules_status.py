$NetBSD: patch-salt_modules_status.py,v 1.2.2.2 2016/02/20 21:24:10 spz Exp $

Avoid a crash in "status.diskusage" when not on Linux or FreeBSD

--- salt/modules/status.py.orig	2016-02-04 21:56:06.000000000 +0000
+++ salt/modules/status.py
@@ -443,6 +443,8 @@ def diskusage(*args):
             ifile = salt.utils.fopen(procf, 'r').readlines()
         elif __grains__['kernel'] == 'FreeBSD':
             ifile = __salt__['cmd.run']('mount -p').splitlines()
+        else:
+            ifile = []
 
         for line in ifile:
             comps = line.split()
