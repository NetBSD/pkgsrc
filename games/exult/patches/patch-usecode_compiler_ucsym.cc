$NetBSD: patch-usecode_compiler_ucsym.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/compiler/ucsym.cc.orig	2011-11-25 17:51:14.000000000 +0000
+++ usecode/compiler/ucsym.cc
@@ -27,6 +27,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #endif
 
 
+#include <cstring>
 #include <stdio.h>
 #include "ucsym.h"
 #include "opcodes.h"
