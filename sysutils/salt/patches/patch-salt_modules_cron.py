$NetBSD: patch-salt_modules_cron.py,v 1.1 2016/02/09 14:23:04 wiz Exp $

Fix for cron on Solaris.
https://github.com/saltstack/salt/pull/29777

--- salt/modules/cron.py.orig	2016-02-01 19:40:31.000000000 +0000
+++ salt/modules/cron.py
@@ -155,7 +155,7 @@ def _get_cron_cmdstr(path, user=None):
     '''
     cmd = 'crontab'
 
-    if user:
+    if user and __grains__.get('os_family') not in ('Solaris', 'AIX'):
         cmd += ' -u {0}'.format(user)
 
     return '{0} {1}'.format(cmd, path)
