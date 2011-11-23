$NetBSD: patch-plug-ins_icc__examin_icc__examin_icc__oyranos__extern.cpp,v 1.1 2011/11/23 23:30:30 joerg Exp $

--- plug-ins/icc_examin/icc_examin/icc_oyranos_extern.cpp.orig	2011-11-23 17:11:56.000000000 +0000
+++ plug-ins/icc_examin/icc_examin/icc_oyranos_extern.cpp
@@ -29,6 +29,7 @@
 
 #include "icc_utils.h"
 #include "icc_fenster.h"
+#include <cstdlib>
 
 using namespace icc_examin_ns;
 
