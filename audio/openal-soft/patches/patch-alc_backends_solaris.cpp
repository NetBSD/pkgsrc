$NetBSD: patch-alc_backends_solaris.cpp,v 1.1 2020/04/09 13:35:21 jperkin Exp $

Fix SunOS build.

--- alc/backends/solaris.cpp.orig	2020-01-24 07:28:45.000000000 +0000
+++ alc/backends/solaris.cpp
@@ -29,6 +29,7 @@
 #include <fcntl.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <memory.h>
 #include <unistd.h>
 #include <errno.h>
