$NetBSD: patch-regex-0.12_regex.c,v 1.1 2012/12/24 01:50:58 dholland Exp $

Use the right config.h. This package misuses autoconf fairly
extensively, and has its own config.h with its own config in it where
where autoconf packages would normally put autoconf's output config.h.

Also patch up some integer/pointer casts.

--- regex-0.12/regex.c.orig	2000-12-16 09:49:55.000000000 +0000
+++ regex-0.12/regex.c
@@ -30,7 +30,7 @@
 #include <sys/types.h>
 
 #ifdef HAVE_CONFIG_H
-#include "config.h"
+#include "bibtool/config.h"
 #endif
 
 /* The `emacs' switch turns on certain matching commands
@@ -65,9 +65,12 @@
 
 #ifdef STDC_HEADERS
 #include <stdlib.h>
+#include <stdint.h>
 #else
 char *malloc ();
 char *realloc ();
+typedef long intptr_t;
+typedef unsigned long uintptr_t;
 #endif
 
 
@@ -2404,10 +2407,10 @@ typedef struct
       }									\
 									\
     DEBUG_PRINT2 ("  Pushing  low active reg: %d\n", lowest_active_reg);\
-    PUSH_FAILURE_ITEM (lowest_active_reg);				\
+    PUSH_FAILURE_ITEM ((uintptr_t)lowest_active_reg);			\
 									\
     DEBUG_PRINT2 ("  Pushing high active reg: %d\n", highest_active_reg);\
-    PUSH_FAILURE_ITEM (highest_active_reg);				\
+    PUSH_FAILURE_ITEM ((uintptr_t)highest_active_reg);			\
 									\
     DEBUG_PRINT2 ("  Pushing pattern 0x%x: ", pattern_place);		\
     DEBUG_PRINT_COMPILED_PATTERN (bufp, pattern_place, pend);		\
@@ -2492,10 +2495,10 @@ typedef struct
   DEBUG_PRINT_COMPILED_PATTERN (bufp, pat, pend);			\
 									\
   /* Restore register info.  */						\
-  high_reg = (unsigned) POP_FAILURE_ITEM ();				\
+  high_reg = (unsigned)(uintptr_t) POP_FAILURE_ITEM ();			\
   DEBUG_PRINT2 ("  Popping high active reg: %d\n", high_reg);		\
 									\
-  low_reg = (unsigned) POP_FAILURE_ITEM ();				\
+  low_reg = (unsigned)(uintptr_t) POP_FAILURE_ITEM ();			\
   DEBUG_PRINT2 ("  Popping  low active reg: %d\n", low_reg);		\
 									\
   for (this_reg = high_reg; this_reg >= low_reg; this_reg--)		\
@@ -3762,7 +3765,7 @@ re_match_2 (bufp, string1, size1, string
                           regstart[r] = old_regstart[r];
 
                           /* xx why this test?  */
-                          if ((int) old_regend[r] >= (int) regstart[r])
+                          if ((intptr_t) old_regend[r] >= (intptr_t) regstart[r])
                             regend[r] = old_regend[r];
                         }     
                     }
