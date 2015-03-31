$NetBSD: patch-src_texcmp_squish_squish.cpp,v 1.1 2015/03/31 15:41:14 joerg Exp $

--- src/texcmp/squish/squish.cpp.orig	2015-03-27 17:03:21.000000000 +0000
+++ src/texcmp/squish/squish.cpp
@@ -23,6 +23,7 @@
 	
    -------------------------------------------------------------------------- */
    
+#include <stdlib.h>
 #include <squish.h>
 #include "colourset.h"
 #include "maths.h"
