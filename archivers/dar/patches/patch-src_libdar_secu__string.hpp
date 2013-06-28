$NetBSD: patch-src_libdar_secu__string.hpp,v 1.2 2013/06/28 15:03:55 ryoon Exp $

--- src/libdar/secu_string.hpp.orig	2012-11-30 20:51:11.000000000 +0000
+++ src/libdar/secu_string.hpp
@@ -35,6 +35,7 @@
 #include "../my_config.h"
 
 #include <string>
+#include <unistd.h>
 #include "integers.hpp"
 #include "special_alloc.hpp"
 
