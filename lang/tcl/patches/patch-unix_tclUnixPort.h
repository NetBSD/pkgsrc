$NetBSD: patch-unix_tclUnixPort.h,v 1.3 2014/01/11 14:41:05 adam Exp $

--- unix/tclUnixPort.h.orig	2013-05-31 19:30:55.000000000 +0000
+++ unix/tclUnixPort.h
@@ -141,19 +141,11 @@ typedef off_t		Tcl_SeekOffset;
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
 
 extern int TclUnixSetBlockingMode(int fd, int mode);
 
