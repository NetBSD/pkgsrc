$NetBSD: patch-test_addhtest.cpp,v 1.1 2020/05/02 15:05:30 wiedi Exp $

Need alloca.h on SunOS

--- test/addhtest.cpp.orig	2019-10-07 16:39:17.000000000 +0000
+++ test/addhtest.cpp
@@ -34,6 +34,10 @@ GNU General Public License for more deta
 #include <iostream>
 #include <fstream>
 
+#if defined(__sun)
+#include <alloca.h>
+#endif
+
 using namespace std;
 using namespace OpenBabel;
 
