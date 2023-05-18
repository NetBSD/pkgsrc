$NetBSD: patch-setup.py,v 1.3 2023/05/18 14:01:58 bacon Exp $

# Unbundle numpy

--- setup.py.orig	2023-05-18 12:06:38.965674517 +0000
+++ setup.py
@@ -25,22 +25,6 @@ def main():
         sys.exit(1)
     cwd = os.path.abspath(os.path.dirname(__file__))
 
-    # install required numpy
-    p = subprocess.call([sys.executable, "-m", 'pip', 'install', f'numpy{numpy_requires}'],cwd=cwd)
-    if p != 0:
-        # Could be due to a too old pip version and build isolation, check that
-        try:
-            # Note, pip may not be installed or not have been used
-            import pip
-            if LooseVersion(pip.__version__) < LooseVersion('18.0.0'):
-                raise RuntimeError("Installing requirements failed. Possibly due "
-                                   "to `pip` being too old, found version {}, "
-                                   "needed is >= 18.0.0.".format(pip.__version__))
-            else:
-                raise RuntimeError("Installing requirements failed!")
-        except ImportError:
-            raise RuntimeError("Installing requirement failed! `pip` has to be installed!")
-        
     from numpy import get_include as numpy_get_include
     numpy_include_dir = [numpy_get_include()]
         
