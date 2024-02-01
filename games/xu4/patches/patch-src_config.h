$NetBSD: patch-src_config.h,v 1.1 2024/02/01 09:33:08 wiz Exp $

--- src/config.h.orig	2024-02-01 09:31:34.669422918 +0000
+++ src/config.h
@@ -8,6 +8,7 @@
 #include "vc6.h" // Fixes things if you're using VC6, does nothing if otherwise
 #include <string>
 #include <vector>
+#include <libxml/tree.h>
 #include <libxml/xmlmemory.h>
 
 class ConfigElement;
