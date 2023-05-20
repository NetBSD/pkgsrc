$NetBSD: patch-utility_src_utility_files.H,v 1.2 2023/05/20 11:27:27 bacon Exp $

# Portability

--- utility/src/utility/files.H.orig	2021-12-17 20:57:15 UTC
+++ utility/src/utility/files.H
@@ -22,7 +22,7 @@
 
 #include "types.H"
 #include <vector>
-
+#include <cmath>
 
 //  Provides a safe and reliable mechanism for reading / writing
 //  binary data.
