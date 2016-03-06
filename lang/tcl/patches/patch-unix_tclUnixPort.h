$NetBSD: patch-unix_tclUnixPort.h,v 1.4 2016/03/06 11:47:49 adam Exp $

--- unix/tclUnixPort.h.orig	2016-02-25 20:12:38.000000000 +0000
+++ unix/tclUnixPort.h
@@ -145,11 +145,7 @@ typedef off_t		Tcl_SeekOffset;
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
 
