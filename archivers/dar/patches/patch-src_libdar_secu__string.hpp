$NetBSD: patch-src_libdar_secu__string.hpp,v 1.3 2014/05/14 04:35:20 rodent Exp $

--- src/libdar/secu_string.hpp.orig	2014-04-21 10:02:16.000000000 +0000
+++ src/libdar/secu_string.hpp
@@ -35,6 +35,7 @@
 #include "../my_config.h"
 
 #include <string>
+#include <unistd.h>
 #include "integers.hpp"
 #include "special_alloc.hpp"
 
