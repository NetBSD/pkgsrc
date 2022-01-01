$NetBSD: patch-editor_src_Rechord.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Use standard headers.
Use ctype functions correctly.

--- editor/src/Rechord.c~	2001-06-29 16:31:01.000000000 +0000
+++ editor/src/Rechord.c
@@ -2,6 +2,8 @@
 /* Mild attempt at chord naming */
 /* G. Laurent, 09/96 */
 
+#include <ctype.h>
+
 #include "Rechord.h"
 
 #ifdef DEBUG
@@ -824,7 +826,7 @@ char* Rechord(Chord chord) {
   }
   else {
     /* There's only one note in the chord, use lower case to name it */
-    holdShortest[0] = (char)tolower((int)holdShortest[0]);
+    holdShortest[0] = tolower((unsigned char)holdShortest[0]);
   }
 
   chordName = malloc(strlen(holdShortest) + 1);
