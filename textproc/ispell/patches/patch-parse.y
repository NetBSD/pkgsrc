$NetBSD: patch-parse.y,v 1.1 2025/10/26 19:16:53 vins Exp $

Prevent implicit declaration of bcopy.

--- parse.y.orig	2025-10-26 19:10:34.789087124 +0000
+++ parse.y
@@ -133,6 +133,7 @@ static char Rcs_Id[] =
  */
 
 #include <ctype.h>
+#include <strings.h>
 #include "config.h"
 #include "ispell.h"
 #include "proto.h"
