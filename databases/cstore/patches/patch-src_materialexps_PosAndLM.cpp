$NetBSD: patch-src_materialexps_PosAndLM.cpp,v 1.1 2011/12/20 13:42:48 wiz Exp $

Add missing header.

--- src/materialexps/PosAndLM.cpp.orig	2006-05-24 22:00:22.000000000 +0000
+++ src/materialexps/PosAndLM.cpp
@@ -31,6 +31,7 @@
  /**
  */
 #include "PosAndLM.h"
+#include <stdlib.h>
 
 PosAndLM::PosAndLM() {
 }
