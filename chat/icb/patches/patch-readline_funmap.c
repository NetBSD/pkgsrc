$NetBSD: patch-readline_funmap.c,v 1.1 2013/01/11 13:24:32 joerg Exp $

--- readline/funmap.c.orig	2013-01-11 12:46:28.000000000 +0000
+++ readline/funmap.c
@@ -164,13 +164,14 @@ rl_initialize_funmap ()
   register int i;
 
   if (funmap_initialized)
-    return;
+    return 0;
 
   for (i = 0; default_funmap[i].name; i++)
     rl_add_funmap_entry (default_funmap[i].name, default_funmap[i].function);
 
   funmap_initialized = 1;
   funmap_program_specific_entry_start = i;
+  return 0;
 }
 
 /* Stupid comparison routine for qsort () ing strings. */
