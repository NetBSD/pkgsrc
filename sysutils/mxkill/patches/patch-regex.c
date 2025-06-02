$NetBSD: patch-regex.c,v 1.1 2025/06/02 11:16:24 vins Exp $

* Include stdio.h for putchar().
* Silence size mismatch warnings.

--- regex.c.orig	1997-03-02 19:06:34.000000000 +0000
+++ regex.c
@@ -19,6 +19,9 @@
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
+#include <stdio.h>
+#include <stdint.h>
+
 /* AIX requires this to be the first thing in the file. */
 #if defined (_AIX) && !defined (REGEX_MALLOC)
   #pragma alloca
@@ -2492,10 +2494,10 @@ typedef struct
   DEBUG_PRINT_COMPILED_PATTERN (bufp, pat, pend);			\
 									\
   /* Restore register info.  */						\
-  high_reg = (unsigned) POP_FAILURE_ITEM ();				\
+  high_reg = (uintptr_t) POP_FAILURE_ITEM ();				\
   DEBUG_PRINT2 ("  Popping high active reg: %d\n", high_reg);		\
 									\
-  low_reg = (unsigned) POP_FAILURE_ITEM ();				\
+  low_reg = (uintptr_t) POP_FAILURE_ITEM ();				\
   DEBUG_PRINT2 ("  Popping  low active reg: %d\n", low_reg);		\
 									\
   for (this_reg = high_reg; this_reg >= low_reg; this_reg--)		\
@@ -3762,7 +3764,7 @@ re_match_2 (bufp, string1, size1, string
                           regstart[r] = old_regstart[r];
 
                           /* xx why this test?  */
-                          if ((int) old_regend[r] >= (int) regstart[r])
+                          if ((intptr_t) old_regend[r] >= (intptr_t) regstart[r])
                             regend[r] = old_regend[r];
                         }     
                     }
