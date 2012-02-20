$NetBSD: patch-src-tapenoise.c,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/tapenoise.c.orig	2010-10-25 13:53:16.000000000 +0000
+++ src/tapenoise.c
@@ -2,6 +2,7 @@
   Tape noise (not very good)*/
 
 #include <stdio.h>
+#include <math.h>
 #include <allegro.h>
 #include "b-em.h"
 
