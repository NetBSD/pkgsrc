$NetBSD: patch-unix_tclUnixPort.h,v 1.5 2018/02/03 17:51:19 adam Exp $

--- unix/tclUnixPort.h.orig	2017-10-13 13:41:43.000000000 +0000
+++ unix/tclUnixPort.h
@@ -145,11 +145,7 @@ typedef off_t		Tcl_SeekOffset;
 #ifdef HAVE_STDINT_H
 #   include <stdint.h>
 #endif
-#ifdef HAVE_UNISTD_H
-#   include <unistd.h>
-#else
-#   include "../compat/unistd.h"
-#endif
+#include <unistd.h>
 
 extern int TclUnixSetBlockingMode(int fd, int mode);
 
