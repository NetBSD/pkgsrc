$NetBSD: patch-src_ime.cpp,v 1.1 2014/03/26 12:13:17 obache Exp $

* require string.h for strcpy(3) and strcat(3)

--- src/ime.cpp.orig	2005-05-21 15:21:48.000000000 +0000
+++ src/ime.cpp
@@ -3,6 +3,7 @@
 #define Uses_SCIM_CONFIG_BASE
 #define Uses_SCIM_CONFIG_PATH
 #include <ctype.h>
+#include <string.h>
 
 #include <scim.h>
 #include "scim_fcitx_imengine.h"
