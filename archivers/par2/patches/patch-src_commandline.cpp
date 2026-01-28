$NetBSD: patch-src_commandline.cpp,v 1.2 2026/01/28 17:36:46 rhialto Exp $

include <unistd.h> for sysconf(3)

--- src/commandline.cpp.orig	2026-01-28 17:30:32.345381083 +0000
+++ src/commandline.cpp
@@ -21,6 +21,7 @@
 // iostream is included here, so that cout and cerr are not used elsewhere.
 #include<iostream>
 #include<algorithm>
+#include <unistd.h>
 #include "commandline.h"
 
 
