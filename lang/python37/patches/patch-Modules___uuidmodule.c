$NetBSD: patch-Modules___uuidmodule.c,v 1.1 2018/07/03 03:55:40 adam Exp $

Do not include uuid.h from both locations.

--- Modules/_uuidmodule.c.orig	2018-05-07 06:24:32.000000000 +0000
+++ Modules/_uuidmodule.c
@@ -3,8 +3,7 @@
 #include "Python.h"
 #ifdef HAVE_UUID_UUID_H
 #include <uuid/uuid.h>
-#endif
-#ifdef HAVE_UUID_H
+#elif defined(HAVE_UUID_H)
 #include <uuid.h>
 #endif
 
