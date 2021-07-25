$NetBSD: patch-sickgear.py,v 1.1 2021/07/25 18:02:50 js Exp $

--- sickgear.py.orig	2021-03-10 02:49:59.000000000 +0000
+++ sickgear.py
@@ -40,13 +40,6 @@ warnings.filterwarnings('ignore', module
 warnings.filterwarnings('ignore', module=r'.*zoneinfo.*', message='.*file or directory.*')
 warnings.filterwarnings('ignore', message='.*deprecated in cryptography.*')
 
-versions = [((2, 7, 9), (2, 7, 18)), ((3, 7, 1), (3, 8, 8)), ((3, 9, 0), (3, 9, 2))]  # inclusive version ranges
-if not any(list(map(lambda v: v[0] <= sys.version_info[:3] <= v[1], versions))) and not int(os.environ.get('PYT', 0)):
-    print('Python %s.%s.%s detected.' % sys.version_info[:3])
-    print('Sorry, SickGear requires a Python version %s' % ', '.join(map(
-        lambda r: '%s - %s' % tuple(map(lambda v: str(v).replace(',', '.')[1:-1], r)), versions)))
-    sys.exit(1)
-
 try:
     try:
         py_cache_path = os.path.normpath(os.path.join(os.path.dirname(__file__), '__pycache__'))
