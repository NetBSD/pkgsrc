$NetBSD: patch-bhmusers.cpp,v 1.1 2013/05/23 14:59:13 joerg Exp $

--- bhmusers.cpp.orig	2013-05-23 13:33:38.000000000 +0000
+++ bhmusers.cpp
@@ -1,6 +1,7 @@
 #include "bhmusers.h"
 #include <stdio.h>
 #include <cstring>
+#include <cstdlib>
 #include "expand.h"
 
 BHMUsers::BHMUsers(const char *userListFile)
