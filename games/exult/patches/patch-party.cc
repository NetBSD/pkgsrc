$NetBSD: patch-party.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- party.cc.orig	2011-11-25 18:04:22.000000000 +0000
+++ party.cc
@@ -25,6 +25,7 @@
 #endif
 
 #include <iostream>
+#include <cstring>
 #include <string>
 #include "party.h"
 #include "actors.h"
