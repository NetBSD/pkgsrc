$NetBSD: patch-salt_grains_core.py,v 1.3 2018/05/12 11:29:35 maya Exp $

Prevent crash on NetBSD and OpenBSD when no swap is configured.
https://github.com/saltstack/salt/pull/47600

--- salt/grains/core.py.orig   2018-05-11 13:12:38.000000000 +0000
+++ salt/grains/core.py
@@ -450,11 +450,13 @@ def _bsd_memdata(osdata):
             mem = __salt__['cmd.run']('{0} -n hw.physmem64'.format(sysctl))
         grains['mem_total'] = int(mem) // 1024 // 1024

-        if osdata['kernel'] == 'OpenBSD':
+        if osdata['kernel'] in ['OpenBSD', 'NetBSD']:
             swapctl = salt.utils.path.which('swapctl')
-            swap_total = __salt__['cmd.run']('{0} -sk'.format(swapctl)).split(' ')[1]
-        else:
-            swap_total = __salt__['cmd.run']('{0} -n vm.swap_total'.format(sysctl))
+            swap_data = __salt__['cmd.run']('{0} -sk'.format(swapctl))
+            if swap_data == 'no swap devices configured':
+                swap_total = 0
+            else:
+                swap_total = swap_data.split(' ')[1]
         grains['swap_total'] = int(swap_total) // 1024 // 1024
     return grains

