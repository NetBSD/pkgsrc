$NetBSD: patch-src_input.cc,v 1.1 2011/11/24 13:56:02 joerg Exp $

--- src/input.cc.orig	2011-11-24 00:53:58.000000000 +0000
+++ src/input.cc
@@ -3,6 +3,7 @@
 #include "input.h"
 #include <iostream>
 #include <fstream>
+#include <string.h>
 
 /* Input */
 
