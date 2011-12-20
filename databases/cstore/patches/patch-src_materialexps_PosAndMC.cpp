$NetBSD: patch-src_materialexps_PosAndMC.cpp,v 1.1 2011/12/20 13:42:48 wiz Exp $

Add missing header.

--- src/materialexps/PosAndMC.cpp.orig	2006-05-31 05:17:53.000000000 +0000
+++ src/materialexps/PosAndMC.cpp
@@ -1,4 +1,5 @@
 #include "PosAndMC.h"
+#include <stdlib.h>
 
 PosAndMC::PosAndMC()
 {
