$NetBSD: patch-aiai.cc,v 1.1 2011/11/24 14:08:05 joerg Exp $

--- aiai.cc.orig	2011-11-24 01:17:40.000000000 +0000
+++ aiai.cc
@@ -29,6 +29,7 @@
 #include <sys/wait.h>
 #include <unistd.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include <exception>
 #include <stdexcept>
