$NetBSD: patch-files_databuf.h,v 1.1 2020/03/22 18:09:10 tnn Exp $

include <cstddef> for ptrdiff_t

--- files/databuf.h.orig	2010-03-10 04:07:05.000000000 +0000
+++ files/databuf.h
@@ -20,6 +20,7 @@
 #include <cstdio>
 #include <cstring>
 #include <cassert>
+#include <cstddef>
 #include <fstream>
 #include <string>
 #include <iomanip>
