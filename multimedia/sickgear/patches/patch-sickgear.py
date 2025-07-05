$NetBSD: patch-sickgear.py,v 1.4 2025/07/05 21:04:30 js Exp $

Patch out Python version check.

This regularly breaks if the Python version in pkgsrc gets updated. While newer
versions update the allowed range, it should still not break just because
Python was updated.

--- sickgear.py.orig	2025-07-05 20:57:15.678525004 +0000
+++ sickgear.py
@@ -36,16 +36,6 @@ warnings.filterwarnings('ignore', module
 warnings.filterwarnings('ignore', module=r'.*zoneinfo.*', message='.*file or directory.*')
 warnings.filterwarnings('ignore', message='.*deprecated in cryptography.*')
 
-# noinspection DuplicatedCode
-versions = [((3, 9, 0), (3, 9, 2)), ((3, 9, 4), (3, 9, 23)),
-            ((3, 10, 0), (3, 13, 5))]  # inclusive version ranges
-if not any(list(map(lambda v: v[0] <= sys.version_info[:3] <= v[1], versions))) and not int(os.environ.get('PYT', 0)):
-    major, minor, micro = sys.version_info[:3]
-    print(f'Python {major}.{minor}.{micro} detected.')
-    print('Sorry, SickGear requires a Python version %s' % ', '.join(map(
-        lambda r: '%s - %s' % tuple(map(lambda v: str(v).replace(', ', '.')[1:-1], r)), versions)))
-    sys.exit(1)
-
 sys.path.insert(1, os.path.abspath(os.path.join(os.path.dirname(__file__), 'lib')))
 is_win = 'win' == sys.platform[0:3]
 
