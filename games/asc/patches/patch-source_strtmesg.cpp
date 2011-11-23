$NetBSD: patch-source_strtmesg.cpp,v 1.1 2011/11/23 23:29:45 joerg Exp $

--- source/strtmesg.cpp.orig	2011-11-23 16:19:17.000000000 +0000
+++ source/strtmesg.cpp
@@ -25,6 +25,8 @@
 const char* asc_release="ASC1.16.4.0";
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "strtmesg.h"
 #include "stringtokenizer.h"
 #include "misc.h"
