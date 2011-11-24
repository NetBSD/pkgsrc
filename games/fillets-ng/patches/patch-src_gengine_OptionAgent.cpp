$NetBSD: patch-src_gengine_OptionAgent.cpp,v 1.1 2011/11/24 14:08:48 joerg Exp $

--- src/gengine/OptionAgent.cpp.orig	2011-11-24 00:51:01.000000000 +0000
+++ src/gengine/OptionAgent.cpp
@@ -23,6 +23,7 @@
 #include "UnknownMsgException.h"
 #include "minmax.h"
 
+#include <stdlib.h>
 #include <string.h> //strlen
 #include <locale.h> //setlocale
 
