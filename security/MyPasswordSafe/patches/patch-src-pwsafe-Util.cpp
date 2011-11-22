$NetBSD: patch-src-pwsafe-Util.cpp,v 1.1 2011/11/22 20:05:25 joerg Exp $

--- src/pwsafe/Util.cpp.orig	2011-11-22 19:15:04.000000000 +0000
+++ src/pwsafe/Util.cpp
@@ -5,7 +5,10 @@
 #include "PW_BlowFish.h"
 //#include "PwsPlatform.h"
 
+#include <limits.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <iostream>
 using std::cout;
 using std::endl;
