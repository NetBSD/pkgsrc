$NetBSD: patch-liboctave_util_quit.cc,v 1.3 2021/05/31 07:16:51 thor Exp $

Make sure exit() is defined.

--- liboctave/util/quit.cc.orig	2021-02-19 17:36:34.000000000 +0000
+++ liboctave/util/quit.cc
@@ -27,6 +27,7 @@
 #  include "config.h"
 #endif
 
+#include <cstdlib>
 #include <cstring>
 
 #include <ostream>
