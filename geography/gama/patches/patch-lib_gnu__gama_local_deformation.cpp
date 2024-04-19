$NetBSD: patch-lib_gnu__gama_local_deformation.cpp,v 1.1 2024/04/19 00:09:04 gdt Exp $

Use of std::ostringstream requires sstream.

Reported upstream by email 20240413.

--- lib/gnu_gama/local/deformation.cpp.orig	2024-03-12 10:55:34.000000000 +0000
+++ lib/gnu_gama/local/deformation.cpp
@@ -21,6 +21,7 @@
 
 #include <iostream>
 #include <map>
+#include <sstream>
 #include <vector>
 
 #include <gnu_gama/local/deformation.h>
