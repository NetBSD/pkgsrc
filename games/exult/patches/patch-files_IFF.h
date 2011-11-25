$NetBSD: patch-files_IFF.h,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- files/IFF.h.orig	2011-11-25 17:27:16.000000000 +0000
+++ files/IFF.h
@@ -21,6 +21,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #include <vector>
 #include <string>
+#include <cstring>
 #include "common_types.h"
 #include "U7file.h"
 
