$NetBSD: patch-files_U7file.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- files/U7file.cc.orig	2011-11-25 17:28:14.000000000 +0000
+++ files/U7file.cc
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #  include <cstdio>
 #endif
 #include <iostream>
+#include <cstdlib>
 
 #include "U7file.h"
 #include "Flex.h"
