$NetBSD: patch-option.cpp,v 1.1 2011/11/22 18:11:14 joerg Exp $

--- option.cpp.orig	2011-11-22 17:06:36.000000000 +0000
+++ option.cpp
@@ -4,6 +4,8 @@
 #include <dirent.h>
 #include <unistd.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #include "general.h"
 #include "option.h"
