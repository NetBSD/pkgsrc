$NetBSD: patch-files_U7obj.h,v 1.1 2020/03/22 18:09:10 tnn Exp $

include <cstddef> for ptrdiff_t

--- files/U7obj.h.orig	2010-02-25 02:52:07.000000000 +0000
+++ files/U7obj.h
@@ -25,6 +25,7 @@
 
 #include <string>
 #include <vector>
+#include <cstddef>
 #include <cstring>
 #include "common_types.h"
 #include "utils.h"
