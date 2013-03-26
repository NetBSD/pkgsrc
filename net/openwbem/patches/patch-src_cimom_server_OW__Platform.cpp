$NetBSD: patch-src_cimom_server_OW__Platform.cpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/cimom/server/OW_Platform.cpp.orig	2013-03-25 15:28:45.000000000 +0000
+++ src/cimom/server/OW_Platform.cpp
@@ -34,6 +34,7 @@
  * @author Bart Whiteley
  */
 
+#include <cstdlib>
 #include "OW_config.h"
 #include "OW_Platform.hpp"
 #include "OW_ConfigOpts.hpp"
