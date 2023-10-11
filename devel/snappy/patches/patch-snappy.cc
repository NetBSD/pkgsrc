$NetBSD: patch-snappy.cc,v 1.5 2023/10/11 16:09:07 pho Exp $

Fix build on Darwin: Don't try to use std::less_equal<T> without
#include'ing <functional>.

--- snappy.cc.orig	2023-10-11 16:06:33.000000000 +0000
+++ snappy.cc
@@ -76,6 +76,7 @@
 
 #include <algorithm>
 #include <array>
+#include <functional>
 #include <cstddef>
 #include <cstdint>
 #include <cstdio>
