$NetBSD: patch-src_lib_utils_read__cfg.cpp,v 1.1 2015/09/13 02:31:22 joerg Exp $

--- src/lib/utils/read_cfg.cpp.orig	2015-08-23 22:01:34.263572670 +0000
+++ src/lib/utils/read_cfg.cpp
@@ -6,6 +6,7 @@
 */
 
 #include <botan/parsing.h>
+#include <stdexcept>
 
 namespace Botan {
 
