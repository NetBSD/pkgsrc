$NetBSD: patch-src_support_os__unix.cpp,v 1.1 2015/01/10 18:13:22 rumko Exp $

Fix cases when LC_ALL & co. are undefined.

--- src/support/os_unix.cpp.orig	2014-11-15 18:11:26.000000000 +0000
+++ src/support/os_unix.cpp
@@ -23,6 +23,7 @@
 #include "support/lassert.h"
 
 #include <limits.h>
+#include <locale.h>
 #include <stdlib.h>
 
 #ifdef __APPLE__
