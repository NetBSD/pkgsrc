$NetBSD: patch-salt_grains_core.py,v 1.5 2018/06/20 11:50:56 tpaul Exp $

Prevent crash on NetBSD and OpenBSD when no swap is configured.
https://github.com/saltstack/salt/pull/47600
PR: pkg/53278

--- salt/grains/core.py.orig	2018-06-13 16:03:06.000000000 +0000
+++ salt/grains/core.py
@@ -451,7 +451,11 @@ def _bsd_memdata(osdata):
 
         if osdata['kernel'] in ['OpenBSD', 'NetBSD']:
             swapctl = salt.utils.path.which('swapctl')
-            swap_total = __salt__['cmd.run']('{0} -sk'.format(swapctl)).split(' ')[1]
+            swap_total = __salt__['cmd.run']('{0} -sk'.format(swapctl))
+            if swap_data == 'no swap devices configured':
+                swap_total = 0
+            else:
+                swap_total = swap_data.split(' ')[1]
         else:
             swap_total = __salt__['cmd.run']('{0} -n vm.swap_total'.format(sysctl))
         grains['swap_total'] = int(swap_total) // 1024 // 1024
