$NetBSD: patch-plug-ins_icc__examin_icc__examin_icc__modell__beobachter.cpp,v 1.1 2014/04/19 15:00:09 joerg Exp $

--- plug-ins/icc_examin/icc_examin/icc_modell_beobachter.cpp.orig	2014-04-19 12:18:53.000000000 +0000
+++ plug-ins/icc_examin/icc_examin/icc_modell_beobachter.cpp
@@ -30,6 +30,7 @@
 
 #include "icc_utils.h"
 
+#include <inttypes.h>
 #include <list>
 #include <string>
 
