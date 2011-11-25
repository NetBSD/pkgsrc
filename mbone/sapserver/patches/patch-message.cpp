$NetBSD: patch-message.cpp,v 1.1 2011/11/25 22:05:36 joerg Exp $

--- message.cpp.orig	2011-11-25 19:56:38.000000000 +0000
+++ message.cpp
@@ -30,6 +30,7 @@
 #include <stdio.h>
 #include <string>
 #include <vector>
+#include <cstring>
 using namespace std;
 
 #include "sapserver.h"
