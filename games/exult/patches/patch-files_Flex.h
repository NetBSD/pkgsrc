$NetBSD: patch-files_Flex.h,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- files/Flex.h.orig	2011-11-25 17:26:18.000000000 +0000
+++ files/Flex.h
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <vector>
 #include <string>
 #include <iosfwd>
+#include <cstring>
 #include "common_types.h"
 #include "U7file.h"
 
