$NetBSD: patch-libaudiofile_CAF.cpp,v 1.1 2013/03/15 15:36:40 jperkin Exp $

Need strings.h for bzero()

--- libaudiofile/CAF.cpp.orig	2013-03-06 05:30:03.000000000 +0000
+++ libaudiofile/CAF.cpp
@@ -32,6 +32,7 @@
 
 #include <stdint.h>
 #include <string.h>
+#include <strings.h>
 #include <string>
 #include <vector>
 
