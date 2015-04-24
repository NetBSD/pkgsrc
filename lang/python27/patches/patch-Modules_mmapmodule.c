$NetBSD: patch-Modules_mmapmodule.c,v 1.2 2015/04/24 03:01:36 rodent Exp $

--- Modules/mmapmodule.c.orig	2014-12-10 15:59:55.000000000 +0000
+++ Modules/mmapmodule.c
@@ -23,7 +23,7 @@
 
 #ifndef MS_WINDOWS
 #define UNIX
-# ifdef __APPLE__
+# if defined(__APPLE__) || defined(_SCO_DS)
 #  include <fcntl.h>
 # endif
 #endif
