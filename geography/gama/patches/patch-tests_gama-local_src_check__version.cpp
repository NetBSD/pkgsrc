$NetBSD: patch-tests_gama-local_src_check__version.cpp,v 1.1 2024/04/19 00:09:04 gdt Exp $

Use of std::ostringstream requires sstream.

Not yet reported upstream.

--- tests/gama-local/src/check_version.cpp.orig	2024-04-14 23:02:47.223962253 +0000
+++ tests/gama-local/src/check_version.cpp
@@ -20,6 +20,7 @@
 
 #include <iostream>
 #include <fstream>
+#include <sstream>
 #include <regex>
 #include <gnu_gama/version.h>
 
