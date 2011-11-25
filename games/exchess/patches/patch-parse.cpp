$NetBSD: patch-parse.cpp,v 1.1 2011/11/25 21:52:33 joerg Exp $

--- parse.cpp.orig	2011-11-25 17:25:09.000000000 +0000
+++ parse.cpp
@@ -7,7 +7,7 @@
 #include "chess.h"
 #include "funct.h"
 #include "const.h"
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <string.h>
 
