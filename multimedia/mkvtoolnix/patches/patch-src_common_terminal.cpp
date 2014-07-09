$NetBSD: patch-src_common_terminal.cpp,v 1.1 2014/07/09 11:36:29 jperkin Exp $

Include unistd.h for ioctl()

--- src/common/terminal.cpp.orig	2011-10-09 09:48:12.000000000 +0000
+++ src/common/terminal.cpp
@@ -19,6 +19,7 @@
 #  include <sys/ioctl.h>
 # endif // HAVE_SYS_IOCTL_H || GWINSZ_IN_SYS_IOCTL
 #endif  // HAVE_TIOCGWINSZ
+#include <unistd.h>
 
 #include "common/terminal.h"
 
