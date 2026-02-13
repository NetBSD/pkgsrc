$NetBSD: patch-testing_support_public_random.hh,v 1.1 2026/02/13 02:55:05 ktnb Exp $

File uses size_t, include it.

--- testing/support/public/random.hh.orig	2026-02-07 20:14:53.000000000 +0000
+++ testing/support/public/random.hh
@@ -3,6 +3,7 @@
 
 #include <cstdint>
 #include <vector>
+#include <stdlib.h>
 
 #include "../../../toxcore/attributes.h"
 
