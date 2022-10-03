$NetBSD: patch-src_libdar_secu__string.hpp,v 1.4 2022/10/03 13:59:05 nros Exp $

* Fix out-of-scope errors on gcc 4.7.x

--- src/libdar/secu_string.hpp.orig	2022-10-03 09:18:55.832326503 +0000
+++ src/libdar/secu_string.hpp
@@ -35,6 +35,7 @@
 #include "../my_config.h"
 
 #include <string>
+#include <unistd.h>
 #include "integers.hpp"
 #include "erreurs.hpp"
 
