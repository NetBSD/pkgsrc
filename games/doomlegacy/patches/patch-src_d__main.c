$NetBSD: patch-src_d__main.c,v 1.1 2019/06/17 13:53:22 micha Exp $

Without command line arguments the launcher menu is displayed by default.
This is not desired because we have already prepared the shareware Episode 1
for pkgsrc.

--- src/d_main.c.orig	2018-07-25 10:14:34.000000000 +0000
+++ src/d_main.c
@@ -2507,9 +2507,10 @@ restart_command:
    
     EOUT_flags = EOUT_text | EOUT_log | EOUT_con;
 
-
-#ifdef LAUNCHER   
-    if ( fatal_error || init_sequence == 1 || (init_sequence == 0 && myargc < 2 ))
+#ifdef LAUNCHER
+    // Disable argc check for pkgsrc (shareware episode already prepared)
+    // if ( fatal_error || init_sequence == 1 || (init_sequence == 0 && myargc < 2 ))
+    if ( fatal_error || init_sequence == 1 )
     {
         // [WDJ] Invoke built-in launcher command line
 #if 0
