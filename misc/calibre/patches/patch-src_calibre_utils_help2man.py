$NetBSD: patch-src_calibre_utils_help2man.py,v 1.1 2011/05/21 15:07:48 wiz Exp $

--- src/calibre/utils/help2man.py.orig	2011-04-08 17:20:30.000000000 +0000
+++ src/calibre/utils/help2man.py
@@ -4,7 +4,7 @@ __copyright__ = '2009, Kovid Goyal <kovi
 __docformat__ = 'restructuredtext en'
 
 import time, bz2
-from calibre.constants import isfreebsd
+from calibre.constants import isbsd
 
 from calibre.constants import __version__, __appname__, __author__
 
@@ -58,7 +58,7 @@ def create_man_page(prog, parser):
     lines = [x if isinstance(x, unicode) else unicode(x, 'utf-8', 'replace') for
             x in lines]
 
-    if not isfreebsd:
+    if not isbsd:
         return  bz2.compress((u'\n'.join(lines)).encode('utf-8'))
     else:
         return  (u'\n'.join(lines)).encode('utf-8')
