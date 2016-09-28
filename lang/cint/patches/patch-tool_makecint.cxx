$NetBSD: patch-tool_makecint.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Include missing headers.

--- tool/makecint.cxx.orig	2007-03-16 11:32:07.000000000 +0000
+++ tool/makecint.cxx
@@ -30,7 +30,9 @@
 #define EXIT_SUCCESS 0
 #endif
 
+#include <cstdlib>
 #include <string>
+#include <cstring>
 #include <iostream>
 #include <fstream>
 #include <list>
