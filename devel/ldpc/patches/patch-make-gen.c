$NetBSD: patch-make-gen.c,v 1.1 2026/03/17 14:25:32 nia Exp $

Fix implicit declaration of strcmp(3).

--- make-gen.c.orig	2026-03-17 14:14:59.772104189 +0000
+++ make-gen.c
@@ -15,6 +15,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <math.h>
 
 #include "alloc.h"
