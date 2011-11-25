$NetBSD: patch-usecode_compiler_ucfun.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/compiler/ucfun.cc.orig	2011-11-25 17:50:25.000000000 +0000
+++ usecode/compiler/ucfun.cc
@@ -28,6 +28,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #include <stdio.h>
 #include <cassert>
+#include <cstring>
 #include "ucfun.h"
 #include "ucstmt.h"
 #include "utils.h"
