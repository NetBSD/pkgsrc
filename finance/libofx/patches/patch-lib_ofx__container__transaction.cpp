$NetBSD: patch-lib_ofx__container__transaction.cpp,v 1.1 2011/08/20 19:25:39 wiz Exp $

Fix build with gcc-4.5.

--- lib/ofx_container_transaction.cpp.orig	2007-11-09 23:13:21.000000000 +0000
+++ lib/ofx_container_transaction.cpp
@@ -22,6 +22,7 @@
 #endif
 
 #include <string>
+#include <stdlib.h>
 #include "messages.hh"
 #include "libofx.h"
 #include "ofx_containers.hh"
