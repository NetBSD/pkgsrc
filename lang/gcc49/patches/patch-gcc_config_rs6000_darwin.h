$NetBSD: patch-gcc_config_rs6000_darwin.h,v 1.1 2015/01/22 01:22:48 sevan Exp $

Bug #63703 in GCC Bugzilla

--- gcc/config/rs6000/darwin.h.orig	2015-01-22 01:07:46.000000000 +0000
+++ gcc/config/rs6000/darwin.h
@@ -206,7 +206,11 @@ extern int darwin_emit_branch_islands;
     "vrsave", "vscr",							\
     "spe_acc", "spefscr",                                               \
     "sfp",								\
-    "tfhar", "tfiar", "texasr"						\
+    "tfhar", "tfiar", "texasr",					\
+    "rh0",  "rh1",  "rh2",  "rh3",  "rh4",  "rh5",  "rh6",  "rh7",	\
+    "rh8",  "rh9",  "rh10", "rh11", "rh12", "rh13", "rh14", "rh15",	\
+    "rh16", "rh17", "rh18", "rh19", "rh20", "rh21", "rh22", "rh23",	\
+    "rh24", "rh25", "rh26", "rh27", "rh28", "rh29", "rh30", "rh31"	\
 }
 
 /* This outputs NAME to FILE.  */
