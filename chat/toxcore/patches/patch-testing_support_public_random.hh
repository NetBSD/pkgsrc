$NetBSD: patch-testing_support_public_random.hh,v 1.2 2026/06/05 12:15:14 ktnb Exp $

File uses size_t, include it.

--- testing/support/public/random.hh.orig	2026-06-03 18:11:07.000000000 +0000
+++ testing/support/public/random.hh
@@ -4,6 +4,7 @@
 #include <cstddef>
 #include <cstdint>
 #include <vector>
+#include <stdlib.h>
 
 #include "../../../toxcore/attributes.h"
 
