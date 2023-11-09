$NetBSD: patch-src_apputils_argparse.cpp,v 1.1 2023/11/09 12:30:44 nros Exp $

Use standard malloc and free instead of non-standard alloca,
alloca headers and compiler options differentiates on
different systems.

--- src/apputils/argparse.cpp.orig	2023-11-09 12:01:20.477069989 +0000
+++ src/apputils/argparse.cpp
@@ -266,10 +266,12 @@ ArgOption::invoke_callback () const
         return 0;
 
     // Convert the argv's to char*[]
-    const char **myargv = (const char **) alloca (argc * sizeof(const char *));
+    const char **myargv = (const char **) malloc (argc * sizeof(const char *));
     for (int i = 0;  i < argc;  ++i)
         myargv[i] = m_argv[i].c_str();
-    return invoke_callback (argc, myargv);
+    int retval = invoke_callback (argc, myargv);
+    free(myargv);
+    return retval;
 }
 
 
