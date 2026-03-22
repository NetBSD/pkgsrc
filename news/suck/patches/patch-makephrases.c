$NetBSD: patch-makephrases.c,v 1.1 2026/03/22 09:43:36 nia Exp $

Fix implicit declaration of exit.

--- makephrases.c.orig	2026-03-22 09:32:32.817078716 +0000
+++ makephrases.c
@@ -1,5 +1,6 @@
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include "suck_config.h"
