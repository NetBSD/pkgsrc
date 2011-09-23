$NetBSD: patch-dxflib_src_dl__writer.h,v 1.1 2011/09/23 03:26:57 ryoon Exp $

--- dxflib/src/dl_writer.h.orig	2005-11-22 11:46:56.000000000 +0000
+++ dxflib/src/dl_writer.h
@@ -37,6 +37,7 @@
 #endif
 
 #include <iostream>
+#include <cstring>
 
 #include "dl_attributes.h"
 #include "dl_codes.h"
