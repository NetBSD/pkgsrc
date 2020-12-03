$NetBSD: patch-erts_emulator_sys_common_erl__poll.c,v 1.5 2020/12/03 16:57:05 adam Exp $

Fix for systems where max_fds is a large number (e.g. Darwin).

--- erts/emulator/sys/common/erl_poll.c.orig	2020-12-03 15:45:53.000000000 +0000
+++ erts/emulator/sys/common/erl_poll.c
@@ -312,7 +312,7 @@ struct ERTS_POLL_EXPORT(erts_pollset) {
 void erts_silence_warn_unused_result(long unused);
 static void fatal_error(char *format, ...);
 
-static int max_fds = -1;
+static long max_fds = -1;
 
 #if ERTS_POLL_USE_POLL
 
