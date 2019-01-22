$NetBSD: patch-process.c,v 1.1 2019/01/22 22:07:33 christos Exp $

--- process.c.orig	2007-01-11 17:08:38.000000000 -0500
+++ process.c	2019-01-22 16:54:25.476690976 -0500
@@ -40,19 +40,22 @@
 #include "defs.h"
 
 #include <fcntl.h>
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/wait.h>
 #include <sys/resource.h>
 #include <sys/utsname.h>
+#ifndef NETBSD
 #include <sys/user.h>
+#endif
 #include <sys/syscall.h>
 #include <signal.h>
 #ifdef SUNOS4
 #include <machine/reg.h>
 #endif /* SUNOS4 */
 
-#ifdef FREEBSD
+#ifdef ALLBSD
 #include <sys/ptrace.h>
 #endif
 
@@ -305,7 +308,7 @@
 
 #endif /* HAVE_PRCTL */
 
-#if defined(FREEBSD) || defined(SUNOS4) || defined(SVR4)
+#if defined(ALLBSD) || defined(SUNOS4) || defined(SVR4)
 int
 sys_gethostid(tcp)
 struct tcb *tcp;
@@ -314,7 +317,7 @@
 		return RVAL_HEX;
 	return 0;
 }
-#endif /* FREEBSD || SUNOS4 || SVR4 */
+#endif /* ALLBSD || SUNOS4 || SVR4 */
 
 int
 sys_sethostname(tcp)
@@ -327,7 +330,7 @@
 	return 0;
 }
 
-#if defined(ALPHA) || defined(FREEBSD) || defined(SUNOS4) || defined(SVR4)
+#if defined(ALPHA) || defined(ALLBSD) || defined(SUNOS4) || defined(SVR4)
 int
 sys_gethostname(tcp)
 struct tcb *tcp;
@@ -341,7 +344,7 @@
 	}
 	return 0;
 }
-#endif /* ALPHA || FREEBSD || SUNOS4 || SVR4 */
+#endif /* ALPHA || ALLBSD || SUNOS4 || SVR4 */
 
 int
 sys_setdomainname(tcp)
@@ -1058,7 +1061,7 @@
 
 #endif /* !USE_PROCFS */
 
-#if defined(SUNOS4) || defined(LINUX) || defined(FREEBSD)
+#if defined(SUNOS4) || defined(LINUX) || defined(ALLBSD)
 
 int
 sys_vfork(tcp)
@@ -1069,7 +1072,7 @@
 	return 0;
 }
 
-#endif /* SUNOS4 || LINUX || FREEBSD */
+#endif /* SUNOS4 || LINUX || ALLBSD */
 
 #ifndef LINUX
 
@@ -2051,7 +2054,7 @@
 
 #endif /* SVR4 */
 
-#ifdef FREEBSD
+#ifdef ALLBSD
 int
 sys_wait(tcp)
 struct tcb *tcp;
@@ -2070,12 +2073,14 @@
 }
 #endif
 
+#ifndef NETBSD
 int
 sys_waitpid(tcp)
 struct tcb *tcp;
 {
 	return printwaitn(tcp, 3, 0);
 }
+#endif
 
 int
 sys_wait4(tcp)
@@ -2205,7 +2210,7 @@
 #ifndef SVR4
 
 static const struct xlat ptrace_cmds[] = {
-#ifndef FREEBSD
+#ifndef ALLBSD
 	{ PTRACE_TRACEME,	"PTRACE_TRACEME"	},
 	{ PTRACE_PEEKTEXT,	"PTRACE_PEEKTEXT",	},
 	{ PTRACE_PEEKDATA,	"PTRACE_PEEKDATA",	},
@@ -2271,7 +2276,7 @@
 #endif /* !I386 */
 	{ PTRACE_GETUCODE,	"PTRACE_GETUCODE"	},
 #endif /* SUNOS4 */
-#else /* FREEBSD */
+#else /* ALLBSD */
 	{ PT_TRACE_ME,		"PT_TRACE_ME"		},
 	{ PT_READ_I,		"PT_READ_I"		},
 	{ PT_READ_D,		"PT_READ_D"		},
@@ -2282,20 +2287,26 @@
 #endif
 	{ PT_CONTINUE,		"PT_CONTINUE"		},
 	{ PT_KILL,		"PT_KILL"		},
+#if !(defined(NETBSD) && (defined(ALPHA) || defined(SPARC) || defined(SPARC64)))
 	{ PT_STEP,		"PT_STEP"		},
+#endif
 	{ PT_ATTACH,		"PT_ATTACH"		},
 	{ PT_DETACH,		"PT_DETACH"		},
 	{ PT_GETREGS,		"PT_GETREGS"		},
 	{ PT_SETREGS,		"PT_SETREGS"		},
 	{ PT_GETFPREGS,		"PT_GETFPREGS"		},
 	{ PT_SETFPREGS,		"PT_SETFPREGS"		},
+#ifdef PT_GETDBREGS
 	{ PT_GETDBREGS,		"PT_GETDBREGS"		},
+#endif
+#ifdef PT_SETDBREGS
 	{ PT_SETDBREGS,		"PT_SETDBREGS"		},
-#endif /* FREEBSD */
+#endif
+#endif /* ALLBSD */
 	{ 0,			NULL			},
 };
 
-#ifndef FREEBSD
+#ifndef ALLBSD
 #ifndef SUNOS4_KERNEL_ARCH_KLUDGE
 static
 #endif /* !SUNOS4_KERNEL_ARCH_KLUDGE */
@@ -2982,12 +2993,14 @@
 sys_ptrace(tcp)
 struct tcb *tcp;
 {
+#ifndef NETBSD
 	const struct xlat *x;
+#endif
 	long addr;
 
 	if (entering(tcp)) {
 		printxval(ptrace_cmds, tcp->u_arg[0],
-#ifndef FREEBSD
+#ifndef ALLBSD
 			  "PTRACE_???"
 #else
 			  "PT_???"
@@ -2995,7 +3008,7 @@
 			);
 		tprintf(", %lu, ", tcp->u_arg[1]);
 		addr = tcp->u_arg[2];
-#ifndef FREEBSD
+#ifndef ALLBSD
 		if (tcp->u_arg[0] == PTRACE_PEEKUSER
 			|| tcp->u_arg[0] == PTRACE_POKEUSER) {
 			for (x = struct_user_offsets; x->str; x++) {
@@ -3057,10 +3070,10 @@
 		}
 	}
 #endif /* SUNOS4 */
-#ifdef FREEBSD
+#ifdef ALLBSD
 		tprintf("%lu", tcp->u_arg[3]);
 	}
-#endif /* FREEBSD */
+#endif /* ALLBSD */
 	return 0;
 }
 
