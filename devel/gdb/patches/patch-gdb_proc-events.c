$NetBSD: patch-gdb_proc-events.c,v 1.1 2019/10/11 09:23:42 maya Exp $

Check if SYS_uuidsys is defined before using it. (solaris)

--- gdb/proc-events.c.orig	2018-01-05 04:07:23.000000000 +0000
+++ gdb/proc-events.c
@@ -493,7 +493,9 @@ init_syscall_table (void)
   syscall_table[SYS_utssys] = "utssys";
   syscall_table[SYS_uucopy] = "uucopy";
   syscall_table[SYS_uucopystr] = "uucopystr";
+#ifdef SYS_uuidsys
   syscall_table[SYS_uuidsys] = "uuidsys";
+#endif
 #ifdef SYS_va_mask
   syscall_table[SYS_va_mask] = "va_mask";
 #endif
