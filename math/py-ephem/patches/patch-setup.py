$NetBSD: patch-setup.py,v 1.1 2020/05/31 20:49:33 joerg Exp $

Python 3.6 doesn't default to UTF-8, but still tries to convert to Unicode.

--- setup.py.orig	2020-05-31 17:37:01.440042910 +0000
+++ setup.py
@@ -24,7 +24,7 @@ libastro_files = glob('libastro-%s/*.c' 
 libastro_data = glob('extensions/data/*.c')
 
 def read(*filenames):
-    return open(os.path.join(os.path.dirname(__file__), *filenames)).read()
+    return open(os.path.join(os.path.dirname(__file__), *filenames), **({'encoding': 'UTF-8'} if sys.version_info.major >= 3 else {})).read()
 
 extensions = [
     Extension('ephem._libastro',
