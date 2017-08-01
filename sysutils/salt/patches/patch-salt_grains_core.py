$NetBSD: patch-salt_grains_core.py,v 1.1 2017/08/01 12:09:57 sborrill Exp $

Disable ZFS grains on NetBSD.
https://github.com/saltstack/salt/pull/42654

--- salt/grains/core.py	2017-07-29 21:46:25.000000000 +0000
+++ salt/grains/core.py	2017-07-31 18:49:59.000000000 +0000
@@ -2359,6 +2359,10 @@
     if salt.utils.is_windows() or 'proxyminion' in __opts__:
         return {}
 
+    # quickly return if NetBSD (ZFS still under development)
+    if salt.utils.is_netbsd():
+        return {}
+
     # quickly return if no zpool and zfs command
     if not salt.utils.which('zpool'):
         return {}
