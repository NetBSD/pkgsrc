$NetBSD: patch-utility_src_utility_logging.H,v 1.2 2023/05/20 11:27:27 bacon Exp $

# Portability

--- utility/src/utility/logging.H.orig	2023-05-18 15:39:08.832210910 +0000
+++ utility/src/utility/logging.H
@@ -20,6 +20,8 @@
 #ifndef LOGGING_H
 #define LOGGING_H
 
+#include <stdarg.h>
+
 #include "types.H"
 #include "files.H"
 
