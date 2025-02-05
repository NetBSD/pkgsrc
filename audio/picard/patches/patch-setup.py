$NetBSD: patch-setup.py,v 1.2 2025/02/05 09:12:00 adam Exp $

Don't selectively install app store data.

--- setup.py.orig	2025-02-04 16:09:45.000000000 +0000
+++ setup.py
@@ -313,7 +313,7 @@ class picard_build(build):
                 'publisher': os.environ.get('PICARD_APPX_PUBLISHER', default_publisher),
                 'version': '.'.join(str(v) for v in store_version),
             })
-        elif sys.platform not in {'darwin', 'haiku1', 'win32'}:
+        elif False: #sys.platform not in {'darwin', 'haiku1', 'win32'}:
             self.run_command('build_appdata')
             self.run_command('build_desktop_file')
         super().run()
@@ -835,7 +835,7 @@ def find_file_in_path(filename):
             return file_path
 
 
-if sys.platform not in {'darwin', 'haiku1', 'win32'}:
+if False: #sys.platform not in {'darwin', 'haiku1', 'win32'}:
     args['data_files'].append(('share/applications', [PICARD_DESKTOP_NAME]))
     args['data_files'].append(('share/icons/hicolor/scalable/apps', ['resources/%s.svg' % PICARD_APP_ID]))
     for size in (16, 24, 32, 48, 128, 256):
