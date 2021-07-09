$NetBSD: patch-lib_symboldatabase.cpp,v 1.1 2021/07/09 10:50:37 markd Exp $

gcc11 build fix

--- lib/symboldatabase.cpp.orig	2020-06-13 16:08:37.000000000 +0000
+++ lib/symboldatabase.cpp
@@ -32,6 +32,7 @@
 #include <algorithm>
 #include <cassert>
 #include <climits>
+#include <limits>
 #include <iomanip>
 #include <iostream>
 //---------------------------------------------------------------------------
