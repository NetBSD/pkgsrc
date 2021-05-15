$NetBSD: patch-setup.py,v 1.1 2021/05/15 11:45:52 nia Exp $

Don't selectively install app store data.

--- setup.py.orig	2020-05-06 09:36:12.000000000 +0000
+++ setup.py
@@ -289,8 +289,6 @@ class picard_build(build):
                 'publisher': os.environ.get('PICARD_APPX_PUBLISHER', default_publisher),
                 'version': '.'.join([str(v) for v in store_version]),
             })
-        elif sys.platform == 'linux':
-            self.run_command('build_appdata')
         build.run(self)
 
 
@@ -815,7 +813,4 @@ args['data_files'] = [
 args['data_files'].append(('share/icons/hicolor/scalable/apps', ['resources/%s.svg' % PICARD_APP_ID]))
 args['data_files'].append(('share/applications', [PICARD_DESKTOP_NAME]))
 
-if sys.platform == 'linux':
-    args['data_files'].append(('share/metainfo', [APPDATA_FILE]))
-
 setup(**args)
