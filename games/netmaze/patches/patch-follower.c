$NetBSD: patch-follower.c,v 1.1 2013/03/25 01:59:03 dholland Exp $

--- follower.c~	1994-04-09 14:54:48.000000000 +0000
+++ follower.c
@@ -5,6 +5,9 @@
 
 #include "netmaze.h"
 #include <math.h>
+#include <stdio.h>
+#include <string.h>
+#include <stdlib.h>
 
 #define PI 3.141592
 
