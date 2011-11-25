$NetBSD: patch-server.cc,v 1.1 2011/11/25 22:14:17 joerg Exp $

--- server.cc.orig	2011-11-25 19:21:32.000000000 +0000
+++ server.cc
@@ -34,6 +34,7 @@
 #include <ctype.h>
 #include <regex.h>
 #include <stdlib.h>
+#include <limits.h>
 #include <utmp.h>
 #include <grp.h>
 #include <signal.h>
@@ -44,7 +45,7 @@
 #include <queue>
 #include <map>
 #include <string>
-#include <algo.h>
+#include <algorithm>
 #include <iterator>
 #include <strstream>
 #include <iomanip>
@@ -1740,7 +1741,7 @@ bool LATServer::show_characteristics(boo
     }
 
     // NUL-terminate it.
-    output << std::endl << ends;
+    output << std::endl << std::ends;
 
     return true;
 }
