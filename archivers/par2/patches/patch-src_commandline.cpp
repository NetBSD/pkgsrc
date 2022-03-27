$NetBSD: patch-src_commandline.cpp,v 1.1 2022/03/27 14:08:33 tnn Exp $

include <unistd.h> for sysconf(3)

--- src/commandline.cpp.orig	2020-02-09 14:29:09.000000000 +0000
+++ src/commandline.cpp
@@ -21,6 +21,7 @@
 // This is included here, so that cout and cerr are not used elsewhere.
 #include<iostream>
 #include<algorithm>
+#include <unistd.h>
 #include "commandline.h"
 using namespace std;
 
