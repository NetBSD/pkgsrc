$NetBSD: patch-src_libs_zbxsysinfo_netbsd_proc.c,v 1.1 2019/11/16 10:57:22 he Exp $

Use P_ZOMBIE() macro instead of testing against LSDEAD, which is
gone in later versions.
Thanks to Yuuki Enomoto for the patch.

--- src/libs/zbxsysinfo/netbsd/proc.c.orig	2019-06-07 07:18:53.000000000 +0000
+++ src/libs/zbxsysinfo/netbsd/proc.c
@@ -298,7 +298,7 @@ int	PROC_NUM(AGENT_REQUEST *request, AGE
 						stat_ok = 1;
 					break;
 				case ZBX_PROC_STAT_ZOMB:
-					if (SZOMB == pproc->p_stat || LSDEAD == pproc->p_stat)
+					if (P_ZOMBIE(pproc))
 						stat_ok = 1;
 					break;
 				case ZBX_PROC_STAT_DISK:
