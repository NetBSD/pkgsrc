$NetBSD: patch-setup.py,v 1.1 2014/01/19 13:43:39 wiz Exp $

Code inexplicably fails to detect numpy; remove try/except and it
works.

--- setup.py.orig	2010-04-09 21:28:15.000000000 +0000
+++ setup.py
@@ -77,13 +77,10 @@ if sys.platform == "win32":
 	libplot_module_libs = ["plot.dll"]
 
 else:
-	try:
-		import numpy
-		numpy_inc_dir = numpy.get_include()
-		_biggles_module_inc_dirs.append( numpy_inc_dir )
-		libplot_module_inc_dirs.append( numpy_inc_dir )
-	except:
-		print "numpy module not found; add /path/to/numpy to PYTHONPATH"
+	import numpy
+	numpy_inc_dir = numpy.get_include()
+	_biggles_module_inc_dirs.append( numpy_inc_dir )
+	libplot_module_inc_dirs.append( numpy_inc_dir )
 
 	candidate_dirs = [
 		'/usr',
