$NetBSD: patch-libgfortran_intrinsics_execute_command_line.c,v 1.1 2024/04/01 14:33:57 js Exp $

--- libgfortran/intrinsics/execute_command_line.c.orig	2023-07-07 07:08:21.000000000 +0000
+++ libgfortran/intrinsics/execute_command_line.c
@@ -45,6 +45,10 @@ extern char **environ;
 #include <signal.h>
 #endif
 
+#ifndef SA_RESTART
+#define SA_RESTART 0
+#endif
+
 enum { EXEC_SYNCHRONOUS = -2, EXEC_NOERROR = 0, EXEC_SYSTEMFAILED,
        EXEC_CHILDFAILED, EXEC_INVALIDCOMMAND };
 static const char *cmdmsg_values[] =
