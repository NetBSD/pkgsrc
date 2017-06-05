$NetBSD: patch-gdb_x86-bsd-nat.c,v 1.1 2017/06/05 11:38:51 maya Exp $

Provide a more recent definition of DBREG_DRX.
(This was meant to be a fallback definition for freebsd < 5
 needed as a definition for netbsd)

--- gdb/x86-bsd-nat.c.orig	2017-06-04 15:51:27.000000000 +0000
+++ gdb/x86-bsd-nat.c
@@ -51,10 +51,8 @@ x86bsd_mourn_inferior (struct target_ops
   super_mourn_inferior (ops);
 }
 
-/* Not all versions of FreeBSD/i386 that support the debug registers
-   have this macro.  */
 #ifndef DBREG_DRX
-#define DBREG_DRX(d, x) ((&d->dr0)[x])
+#define	DBREG_DRX(d,x)	((d)->dr[(x)])
 #endif
 
 static unsigned long
