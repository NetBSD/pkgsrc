$NetBSD: patch-usecode_compiler_ucmain.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/compiler/ucmain.cc.orig	2011-11-25 17:49:32.000000000 +0000
+++ usecode/compiler/ucmain.cc
@@ -29,6 +29,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <fstream>
 #include <unistd.h>
 #include <stdio.h>
+#include <cstring>
 #include <string>
 #include <vector>
 #include "ucloc.h"
