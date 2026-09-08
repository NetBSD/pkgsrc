$NetBSD: patch-libsanitizer_sanitizer__common_sanitizer__platform__limits__posix.cpp,v 1.1 2026/09/08 13:20:45 sjmulder Exp $

Account for linux/scc.h removal (Linux 7.1)

--- libsanitizer/sanitizer_common/sanitizer_platform_limits_posix.cpp.orig	2026-09-07 16:20:54.744292218 +0000
+++ libsanitizer/sanitizer_common/sanitizer_platform_limits_posix.cpp
@@ -150,7 +150,6 @@ typedef struct user_fpregs elf_fpregset_
 #include <linux/lp.h>
 #include <linux/mroute.h>
 #include <linux/mroute6.h>
-#include <linux/scc.h>
 #include <linux/serial.h>
 #include <sys/msg.h>
 #include <sys/ipc.h>
@@ -478,8 +477,6 @@ unsigned struct_ElfW_Phdr_sz = sizeof(El
   unsigned struct_kbsentry_sz = sizeof(struct kbsentry);
   unsigned struct_mtconfiginfo_sz = sizeof(struct mtconfiginfo);
   unsigned struct_nr_parms_struct_sz = sizeof(struct nr_parms_struct);
-  unsigned struct_scc_modem_sz = sizeof(struct scc_modem);
-  unsigned struct_scc_stat_sz = sizeof(struct scc_stat);
   unsigned struct_serial_multiport_struct_sz
       = sizeof(struct serial_multiport_struct);
   unsigned struct_serial_struct_sz = sizeof(struct serial_struct);
