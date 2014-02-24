$NetBSD: patch-frontends_beats_main.c,v 1.1 2014/02/24 16:19:39 joerg Exp $

--- frontends/beats/main.c.orig	2014-02-24 12:58:20.000000000 +0000
+++ frontends/beats/main.c
@@ -22,6 +22,7 @@
 */
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <time.h>
 #include "beats.h"
 
