$NetBSD: patch-src_includes_util.h,v 1.1 2011/12/06 19:52:57 joerg Exp $

--- src/includes/util.h.orig	2011-12-06 16:26:03.000000000 +0000
+++ src/includes/util.h
@@ -42,6 +42,8 @@
 #include <cassert>
 #include <iostream>
 #include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #include "Ptr.h"
 #include "Ref.h"
 
