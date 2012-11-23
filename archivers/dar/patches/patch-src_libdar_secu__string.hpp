$NetBSD: patch-src_libdar_secu__string.hpp,v 1.1 2012/11/23 19:08:20 marino Exp $

--- src/libdar/secu_string.hpp.orig	2011-01-09 17:25:58.000000000 +0000
+++ src/libdar/secu_string.hpp
@@ -39,6 +39,7 @@
 #include "../my_config.h"
 
 #include <string>
+#include <unistd.h>
 #include "integers.hpp"
 
 
