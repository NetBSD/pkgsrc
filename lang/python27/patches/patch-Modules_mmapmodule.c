$NetBSD: patch-Modules_mmapmodule.c,v 1.1 2014/07/17 15:26:49 ryoon Exp $

--- Modules/mmapmodule.c.orig	2014-06-30 02:05:43.000000000 +0000
+++ Modules/mmapmodule.c
@@ -23,7 +23,7 @@
 
 #ifndef MS_WINDOWS
 #define UNIX
-# ifdef __APPLE__
+# if defined(__APPLE__) || defined(_SCO_DS)
 #  include <fcntl.h>
 # endif
 #endif
