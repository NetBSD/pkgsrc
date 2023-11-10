$NetBSD: patch-Modules_posixmodule.c,v 1.3 2023/11/10 09:48:40 nia Exp $

posix.copyfile does not exist on Tiger. 

Python 3.8's posix._fcopyfile implementation unconditionally uses <copyfile.h>, 
which only exists on Leopard ane newer. This patch removes posix._fcopyfile 
on Tiger - this is okay because the rest of the stdlib uses posix._fcopyfile 
only conditionally after checking that the function exists 
(non-Apple systems don't have posix._fcopyfile either).


thanks to @dgelessus
https://github.com/macports/macports-ports/pull/5987

--- Modules/posixmodule.c.orig	2023-08-24 17:59:28.000000000 +0000
+++ Modules/posixmodule.c
@@ -57,6 +57,8 @@
  */
 #if defined(__APPLE__)
 
+#include <AvailabilityMacros.h>
+
 #if defined(__has_builtin)
 #if __has_builtin(__builtin_available)
 #define HAVE_BUILTIN_AVAILABLE 1
@@ -229,7 +231,7 @@ corresponding Unix manual entries for mo
 #  include <sys/sendfile.h>
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) && MAC_OS_X_VERSION_MAX_ALLOWED >= 1050
 #  include <copyfile.h>
 #endif
 
@@ -10000,7 +10002,7 @@ done:
 #endif /* HAVE_SENDFILE */
 
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED >= 1050
 /*[clinic input]
 os._fcopyfile
 
@@ -15246,7 +15248,7 @@ all_ins(PyObject *m)
 #endif
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED >= 1050
     if (PyModule_AddIntConstant(m, "_COPYFILE_DATA", COPYFILE_DATA)) return -1;
 #endif
 
