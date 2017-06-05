$NetBSD: patch-gdb_amd64bsd-nat.c,v 1.1 2017/06/05 10:41:28 maya Exp $

--- gdb/amd64bsd-nat.c.orig	2016-02-10 03:19:39.000000000 +0000
+++ gdb/amd64bsd-nat.c
@@ -167,6 +167,10 @@ amd64bsd_target (void)
 
 #ifdef HAVE_PT_GETDBREGS
 
+#ifndef DBREG_DRX
+#define	DBREG_DRX(d,x)	((d)->dr[(x)])
+#endif
+
 static unsigned long
 amd64bsd_dr_get (ptid_t ptid, int regnum)
 {
