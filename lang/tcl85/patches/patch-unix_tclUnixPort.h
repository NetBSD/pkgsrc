$NetBSD: patch-unix_tclUnixPort.h,v 1.1 2014/03/10 14:20:44 taca Exp $

Always use <libmits.h> and <unistd.h>.

--- unix/tclUnixPort.h.orig	2013-08-30 15:58:40.000000000 +0000
+++ unix/tclUnixPort.h
@@ -131,19 +131,11 @@ typedef off_t		Tcl_SeekOffset;
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
 
