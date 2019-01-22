$NetBSD: patch-signal.c,v 1.1 2019/01/22 22:07:33 christos Exp $

--- signal.c.orig	2007-01-11 17:08:38.000000000 -0500
+++ signal.c	2019-01-22 16:54:46.145801860 -0500
@@ -36,12 +36,29 @@
 #include "defs.h"
 
 #include <signal.h>
+#include <sys/param.h>
+#ifndef NETBSD
 #include <sys/user.h>
+#endif
 #include <fcntl.h>
 
-#ifdef SVR4
+#if defined(SVR4) || defined(NETBSD)
 #include <sys/ucontext.h>
 #endif /* SVR4 */
+#ifdef NETBSD
+#if !defined(UC_CPU) && defined(_UC_CPU)
+#define UC_CPU _UC_CPU
+#endif
+#if !defined(UC_SIGMASK) && defined(_UC_SIGMASK)
+#define UC_SIGMASK _UC_SIGMASK
+#endif
+#if !defined(UC_STACK) && defined(_UC_STACK)
+#define UC_STACK _UC_STACK
+#endif
+#if !defined(UC_FPU) && defined(_UC_FPU)
+#define UC_FPU _UC_FPU
+#endif
+#endif
 
 #ifdef HAVE_SYS_REG_H
 # include <sys/reg.h>
@@ -1056,14 +1073,14 @@
 	return 0;
 }
 
-#if defined(SUNOS4) || defined(FREEBSD)
+#if defined(SUNOS4) || defined(ALLBSD)
 int
 sys_sigblock(tcp)
 struct tcb *tcp;
 {
 	return sys_sigsetmask(tcp);
 }
-#endif /* SUNOS4 || FREEBSD */
+#endif /* SUNOS4 || ALLBSD */
 
 #endif /* !SVR4 */
 
@@ -1165,13 +1182,13 @@
 		printsignal(tcp->u_arg[0]);
 		tprintf(", ");
 		switch (tcp->u_arg[1]) {
-		case (int) SIG_ERR:
+		case (long) SIG_ERR:
 			tprintf("SIG_ERR");
 			break;
-		case (int) SIG_DFL:
+		case (long) SIG_DFL:
 			tprintf("SIG_DFL");
 			break;
-		case (int) SIG_IGN:
+		case (long) SIG_IGN:
 #ifndef USE_PROCFS
 			if (tcp->u_arg[0] == SIGTRAP) {
 				tcp->flags |= TCB_SIGTRAPPED;
@@ -1193,11 +1210,11 @@
 	}
 	else {
 		switch (tcp->u_rval) {
-		    case (int) SIG_ERR:
+		    case (long) SIG_ERR:
 			tcp->auxstr = "SIG_ERR"; break;
-		    case (int) SIG_DFL:
+		    case (long) SIG_DFL:
 			tcp->auxstr = "SIG_DFL"; break;
-		    case (int) SIG_IGN:
+		    case (long) SIG_IGN:
 			tcp->auxstr = "SIG_IGN"; break;
 		    default:
 			tcp->auxstr = NULL;
@@ -1489,7 +1506,7 @@
 
 #endif /* LINUX */
 
-#if defined(SVR4) || defined(FREEBSD)
+#if defined(SVR4) || defined(ALLBSD)
 
 int
 sys_sigsuspend(tcp)
@@ -1521,7 +1538,7 @@
 #endif /* !FREEBSD */
 #endif /* SVR4 || FREEBSD */
 
-#if defined SVR4 || defined LINUX || defined FREEBSD
+#if defined SVR4 || defined LINUX || defined ALLBSD
 #if defined LINUX && !defined SS_ONSTACK
 #define SS_ONSTACK      1
 #define SS_DISABLE      2
@@ -1613,7 +1630,7 @@
 
 #endif /* SVR4 */
 
-#if defined(LINUX) || defined(FREEBSD)
+#if defined(LINUX) || defined(ALLBSD)
 
 static int
 print_stack_t(tcp, addr)
@@ -1702,14 +1719,14 @@
 	return 0;
 }
 
-#if defined(FREEBSD) || defined(SUNOS4)
+#if defined(ALLBSD) || defined(SUNOS4)
 int
 sys_killpg(tcp)
 struct tcb *tcp;
 {
 	return sys_kill(tcp);
 }
-#endif /* FREEBSD || SUNOS4 */
+#endif /* ALLBSD || SUNOS4 */
 
 #ifdef LINUX
 int
