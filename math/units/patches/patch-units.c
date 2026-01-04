$NetBSD: patch-units.c,v 1.1 2026/01/04 11:38:25 wiz Exp $

--- units.c.orig	2026-01-04 11:37:04.829730432 +0000
+++ units.c
@@ -4104,7 +4104,7 @@ main(int argc, char **argv)
 #endif
 
 #ifdef READLINE
-#  if RL_READLINE_VERSION > 0x0402 
+#  if 1
       rl_completion_entry_function = (rl_compentry_func_t *)completeunits;
 #  else
       rl_completion_entry_function = (Function *)completeunits;
