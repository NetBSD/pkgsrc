$NetBSD: patch-terminalcontroller.cc,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- terminalcontroller.cc.orig	2011-11-27 02:51:21.000000000 +0000
+++ terminalcontroller.cc
@@ -21,6 +21,7 @@ with VMIPS; if not, write to the Free So
 #include "error.h"
 #include "terminalcontroller.h"
 #include <cassert>
+#include <cstring>
 #include <errno.h>
 #include <sys/time.h>
 #include <unistd.h>
