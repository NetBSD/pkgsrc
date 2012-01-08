$NetBSD: patch-src_spell.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/spell.cpp.orig	2005-10-03 05:57:31.000000000 +0000
+++ src/spell.cpp
@@ -5,6 +5,7 @@
 #include "vc6.h" // Fixes things if you're using VC6, does nothing if otherwise
 
 #include "u4.h"
+#include <string.h>
 
 #include "spell.h"
 
