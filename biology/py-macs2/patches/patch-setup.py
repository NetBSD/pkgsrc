$NetBSD: patch-setup.py,v 1.1 2023/01/22 23:30:11 bacon Exp $

# Remove lexical version check and pip requirement

--- setup.py.orig	2020-04-12 00:00:15.000000000 +0000
+++ setup.py
@@ -20,28 +20,8 @@ numpy_requires = '>=1.17'
 install_requires = [f"numpy>={numpy_requires}",]
 
 def main():
-    if float(sys.version[:3])<3.6:
-        sys.stderr.write("CRITICAL: Python version must >= 3.6!\n")
-        sys.exit(1)
-
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
         
