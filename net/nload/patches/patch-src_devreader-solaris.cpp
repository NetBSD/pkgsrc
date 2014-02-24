$NetBSD: patch-src_devreader-solaris.cpp,v 1.1 2014/02/24 12:45:44 wiedi Exp $

Need stdlib for free()
--- src/devreader-solaris.cpp.orig	2007-11-16 10:09:56.000000000 +0000
+++ src/devreader-solaris.cpp
@@ -16,6 +16,7 @@
 
 #include "devreader-solaris.h"
 
+#include <stdlib.h>
 #include <string.h>
 #include <kstat.h>
 #include <sys/socket.h>
