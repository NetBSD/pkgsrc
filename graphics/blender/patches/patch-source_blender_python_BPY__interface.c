$NetBSD: patch-source_blender_python_BPY__interface.c,v 1.1 2011/04/01 11:31:56 wiz Exp $

Fix http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2008-4863
using patch from James Vega via
http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=503632

--- source/blender/python/BPY_interface.c.orig	2009-09-01 15:21:12.000000000 +0000
+++ source/blender/python/BPY_interface.c
@@ -236,6 +236,12 @@ void BPY_start_python( int argc, char **
 	Py_Initialize(  );
 	
 	PySys_SetArgv( argc_copy, argv_copy );
+
+	/* Sanitize sys.path to prevent relative imports loading modules in
+	 * the current working directory
+	 */
+	PyRun_SimpleString("import sys; sys.path = filter(None, sys.path)");
+
 	/* Initialize thread support (also acquires lock) */
 	PyEval_InitThreads();
 	
