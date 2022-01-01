$NetBSD: patch-echosrv.c,v 1.2 2014/11/28 10:45:28 bsiegert Exp 

Provide allow_severity and deny_severity for libwrap.

--- echosrv.c.orig	2022-01-01 16:38:28.450058726 +0000
+++ echosrv.c
@@ -41,6 +41,10 @@
 #define SA_NOCLDWAIT 0
 #endif
 
+#ifdef LIBWRAP
+int allow_severity =0, deny_severity = 0;
+#endif
+
 struct echocfg_item cfg;
 
 void check_res_dump(int res, struct addrinfo *addr, char* syscall)
