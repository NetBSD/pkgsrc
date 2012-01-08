$NetBSD: patch-src_savegame.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/savegame.cpp.orig	2005-01-14 08:24:55.000000000 +0000
+++ src/savegame.cpp
@@ -5,6 +5,7 @@
 #include "vc6.h" // Fixes things if you're using VC6, does nothing if otherwise
 
 #include "savegame.h"
+#include <string.h>
 
 #include "io.h"
 #include "object.h"
