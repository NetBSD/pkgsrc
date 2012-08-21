$NetBSD: patch-unix_tclUnixPort.h,v 1.1 2012/08/21 21:31:47 marino Exp $

--- unix/tclUnixPort.h.orig	2012-07-16 11:57:06.000000000 +0000
+++ unix/tclUnixPort.h
@@ -45,15 +45,7 @@
 #   include <sys/param.h>
 #endif
 #include <sys/types.h>
-#ifdef USE_DIRENT2_H
-#   include "../compat/dirent2.h"
-#else
-#ifdef NO_DIRENT_H
-#   include "../compat/dirent.h"
-#else
-#   include <dirent.h>
-#endif
-#endif
+#include <dirent.h>
 
 /*
  *---------------------------------------------------------------------------
@@ -135,19 +127,11 @@ typedef off_t		Tcl_SeekOffset;
 #if HAVE_INTTYPES_H
 #   include <inttypes.h>
 #endif
-#ifdef NO_LIMITS_H
-#   include "../compat/limits.h"
-#else
-#   include <limits.h>
-#endif
+#include <limits.h>
 #if HAVE_STDINT_H
 #   include <stdint.h>
 #endif
-#ifdef HAVE_UNISTD_H
-#   include <unistd.h>
-#else
-#   include "../compat/unistd.h"
-#endif
+#include <unistd.h>
 
 MODULE_SCOPE int TclUnixSetBlockingMode(int fd, int mode);
 
