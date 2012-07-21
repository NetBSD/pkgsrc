$NetBSD: patch-libf95.a-0.92_io_atof.c,v 1.1 2012/07/21 22:01:18 dholland Exp $

Needs stdlib.h on netbsd to get alloca() declaration.

--- libf95.a-0.92/io/atof.c~	2009-04-22 17:44:56.000000000 +0000
+++ libf95.a-0.92/io/atof.c
@@ -2,6 +2,7 @@
 
 
 
+#include <stdlib.h>
 #include <string.h>
 #include "runtime.h"
 
