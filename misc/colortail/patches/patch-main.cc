$NetBSD: patch-main.cc,v 1.1 2011/11/26 17:16:53 joerg Exp $

--- main.cc.orig	2011-11-26 15:17:12.000000000 +0000
+++ main.cc
@@ -18,6 +18,7 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <signal.h>
 
 #include "main.h"
