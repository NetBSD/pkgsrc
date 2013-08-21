$NetBSD: patch-cpm.cpp,v 1.2 2013/08/21 10:23:41 shattered Exp $

--- cpm.cpp.orig	2005-05-16 20:19:55.000000000 +0000
+++ cpm.cpp
@@ -19,6 +19,7 @@
 #include <memory>
 
 #include <stdio.h>
+#include <string.h>
 #include <unistd.h>
 #include <errno.h>
 #include <ctype.h>
