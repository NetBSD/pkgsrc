$NetBSD: patch-src_startup.c,v 1.1 2018/09/21 14:27:37 wiz Exp $

Added variable for Cancel-Lock hash algorithm.

--- src/startup.c.orig	2016-10-23 22:34:16.000000000 +0000
+++ src/startup.c
@@ -731,8 +731,10 @@ Slrn_Str_Var_Type Slrn_Str_Variables [] 
 #endif
 #if SLRN_HAS_CANLOCK
      {"cansecret_file", &Slrn_User_Info.cancelsecret, NULL},
+     {"canlock_algo", &Slrn_User_Info.canlock_algo, NULL},
 #else
      {"cansecret_file", NULL, NULL},
+     {"canlock_algo", NULL, NULL},
 #endif
      {"art_help_line", &Slrn_Art_Help_Line, NULL},
      {"art_status_line", &Slrn_Art_Status_Line, NULL},
