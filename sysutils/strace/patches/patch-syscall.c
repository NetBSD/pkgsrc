$NetBSD: patch-syscall.c,v 1.1 2019/01/22 22:07:33 christos Exp $

--- syscall.c.orig	2006-12-21 17:13:33.000000000 -0500
+++ syscall.c	2019-01-22 16:53:51.213106690 -0500
@@ -38,9 +38,11 @@
 #include <signal.h>
 #include <time.h>
 #include <errno.h>
+#include <sys/param.h>
+#ifndef NETBSD
 #include <sys/user.h>
+#endif
 #include <sys/syscall.h>
-#include <sys/param.h>
 
 #if HAVE_ASM_REG_H
 #if defined (SPARC) || defined (SPARC64)
@@ -56,6 +58,10 @@
 #endif
 #endif
 
+#ifdef NETBSD
+#include <machine/reg.h>
+#include <machine/psl.h>
+#endif
 #ifdef HAVE_SYS_REG_H
 #include <sys/reg.h>
 #ifndef PTRACE_PEEKUSR
@@ -467,16 +473,19 @@
 	for (p = strtok(s, ","); p; p = strtok(NULL, ",")) {
 		if (opt->bitflag == QUAL_TRACE && (n = lookup_class(p)) > 0) {
 			for (i = 0; i < MAX_QUALS; i++) {
-				if (sysent0[i].sys_flags & n)
+				if (i < __arraycount(sysent0) 
+				    && (sysent0[i].sys_flags & n))
 					qualify_one(i, opt, not, 0);
 
 #if SUPPORTED_PERSONALITIES >= 2
-				if (sysent1[i].sys_flags & n)
+				if (i < __arraycount(sysent1) 
+				    && (sysent1[i].sys_flags & n))
 					qualify_one(i, opt, not, 1);
 #endif /* SUPPORTED_PERSONALITIES >= 2 */
 
 #if SUPPORTED_PERSONALITIES >= 3
-				if (sysent2[i].sys_flags & n)
+				if (i < __arraycount(sysent2) 
+				    && (sysent2[i].sys_flags & n))
 					qualify_one(i, opt, not, 2);
 #endif /* SUPPORTED_PERSONALITIES >= 3 */
 			}
@@ -580,6 +589,7 @@
 
 #if !(defined(LINUX) && ( defined(ALPHA) || defined(MIPS) ))
 
+#if defined (SPARC) || defined (SPARC64)
 static const int socket_map [] = {
 	       /* SYS_SOCKET      */ 97,
 	       /* SYS_BIND        */ 104,
@@ -600,7 +610,6 @@
 	       /* SYS_RECVMSG     */ 113
 };
 
-#if defined (SPARC) || defined (SPARC64)
 static void
 sparc_socket_decode (tcp)
 struct tcb *tcp;
@@ -624,6 +633,7 @@
 }
 #endif
 
+#ifndef NETBSD
 static void
 decode_subcall(tcp, subcall, nsubcalls, style)
 struct tcb *tcp;
@@ -709,6 +719,7 @@
 #endif /* FREEBSD */
 	}
 }
+#endif /* !NETBSD */
 #endif
 
 struct tcb *tcp_last = NULL;
@@ -747,7 +758,7 @@
 #endif
 
 	if (   sys_execve == func
-#if defined(SPARC) || defined(SPARC64) || defined(SUNOS4)
+#if !defined(NETBSD) && (defined(SPARC) || defined(SPARC64) || defined(SUNOS4))
 	    || sys_execv == func
 #endif
 #if UNIXWARE > 2
@@ -756,11 +767,14 @@
 	   )
 		return internal_exec(tcp);
 
-	if (   sys_waitpid == func
-	    || sys_wait4 == func
-#if defined(SVR4) || defined(FREEBSD) || defined(SUNOS4)
+	if (
+	    sys_wait4 == func
+#ifndef NETBSD
+	    || sys_waitpid == func
+#if defined(SVR4) || defined(ALLBSD) || defined(SUNOS4)
 	    || sys_wait == func
 #endif
+#endif
 #ifdef ALPHA
 	    || sys_osf_wait4 == func
 #endif
@@ -811,9 +825,9 @@
        static long rax;
 #endif
 #endif /* LINUX */
-#ifdef FREEBSD
-	struct reg regs;
-#endif /* FREEBSD */
+#ifdef ALLBSD
+	static struct reg regs;
+#endif /* ALLBSD */
 
 int
 get_scno(tcp)
@@ -1283,9 +1297,9 @@
 #ifdef HAVE_PR_SYSCALL
 	scno = tcp->status.PR_SYSCALL;
 #else /* !HAVE_PR_SYSCALL */
-#ifndef FREEBSD
+#ifndef ALLBSD
 	scno = tcp->status.PR_WHAT;
-#else /* FREEBSD */
+#else /* ALLBSD */
 	if (pread(tcp->pfd_reg, &regs, sizeof(regs), 0) < 0) {
 	        perror("pread");
                 return -1;
@@ -1299,8 +1313,41 @@
 	        scno = regs.r_eax;
 	        break;
 	}
-#endif /* FREEBSD */
+#endif /* ALLBSD */
 #endif /* !HAVE_PR_SYSCALL */
+#else /* !USE_PROCFS */
+#ifdef NETBSD
+	if (ptrace(PTRACE_GETREGS,pid,(char *)&regs, 0) < 0) {
+	        perror("GETREGS");
+		return -1;
+	}
+#ifdef __i386__
+	switch (regs.r_eax) {
+	case SYS_syscall:
+	case SYS___syscall:
+    	        if ((scno = ptrace(PTRACE_PEEKUSER, pid,
+		    (char *)regs.r_esp + sizeof(int), sizeof(int))) == -1) {
+			perror("PEEKUSER __syscall");
+			return -1;
+		}
+	        break;
+	default:
+	        scno = regs.r_eax;
+	        break;
+        }
+#endif
+#ifdef __x86_64__
+	switch (regs.regs[_REG_RAX]) {
+	case SYS_syscall:
+	case SYS___syscall:
+		scno = regs.regs[_REG_RDI];
+	        break;
+	default:
+	        scno = regs.regs[_REG_RAX];
+	        break;
+        }
+#endif
+#endif /* NETBSD */
 #endif /* USE_PROCFS */
 	if (!(tcp->flags & TCB_INSYSCALL))
 		tcp->scno = scno;
@@ -1325,7 +1372,9 @@
 struct tcb *tcp;
 {
 #ifndef USE_PROCFS
+#ifndef NETBSD
 	int pid = tcp->pid;
+#endif
 #else /* USE_PROCFS */
 	int scno = known_scno(tcp);
 
@@ -1698,17 +1747,36 @@
 		}
 #endif /* MIPS */
 #endif /* SVR4 */
-#ifdef FREEBSD
+#ifdef ALLBSD
+#ifdef __i386__
 		if (regs.r_eflags & PSL_C) {
  		        tcp->u_rval = -1;
 		        u_error = regs.r_eax;
 		} else {
 		        tcp->u_rval = regs.r_eax;
+#if 0
+			/* XXX Linux only */
 			tcp->u_lrval =
 			  ((unsigned long long) regs.r_edx << 32) +  regs.r_eax;
+#endif
 		        u_error = 0;
 		}
-#endif /* FREEBSD */
+#endif
+#ifdef __x86_64__
+		if (regs.regs[_REG_RFL] & PSL_C) {
+ 		        tcp->u_rval = -1;
+		        u_error = regs.regs[_REG_RAX];
+		} else {
+		        tcp->u_rval = regs.regs[_REG_RAX];
+#if 0
+			/* XXX Linux only */
+			tcp->u_lrval =
+			  ((unsigned long long) regs.regs[_REG_RDX] << 64) +  regs.regs[_REG_RAX];
+#endif
+		        u_error = 0;
+		}
+#endif
+#endif /* ALLBSD */
 	tcp->u_error = u_error;
 	return 1;
 }
@@ -1891,6 +1959,32 @@
                 return -1;
         }
 #endif /* FREEBSD */
+#ifdef NETBSD
+	if (ptrace(PTRACE_GETREGS, tcp->pid, (char *)&regs, 0) < 0)
+		return -1;
+#ifdef __i386__
+	if (error) {
+		regs.r_eflags |= PSL_C;
+		regs.r_eax = error;
+	}
+	else {
+		regs.r_eflags &= ~PSL_C;
+		regs.r_eax = rval;
+	}
+#endif
+#ifdef __x86_64__
+	if (error) {
+		regs.regs[_REG_RFL] |= PSL_C;
+		regs.regs[_REG_RAX] = error;
+	}
+	else {
+		regs.regs[_REG_RFL] &= ~PSL_C;
+		regs.regs[_REG_RAX] = rval;
+	}
+#endif
+	if (ptrace(PTRACE_SETREGS, tcp->pid, (char *)&regs, 0) < 0)
+		return -1;
+#endif /* NETBSD */
 
 	/* All branches reach here on success (only).  */
 	tcp->u_error = error;
@@ -1903,7 +1997,9 @@
 struct tcb *tcp;
 {
 #ifndef USE_PROCFS
+#ifndef NETBSD
 	int pid = tcp->pid;
+#endif
 #endif /* !USE_PROCFS */
 #ifdef LINUX
 #if defined(S390) || defined(S390X)
@@ -2201,6 +2297,58 @@
 	I DONT KNOW WHAT TO DO
 #endif /* !HAVE_PR_SYSCALL */
 #endif /* SVR4 */
+#ifdef NETBSD
+	if (tcp->scno >= 0 && tcp->scno < nsyscalls && sysent[tcp->scno].nargs != -1)
+		tcp->u_nargs = sysent[tcp->scno].nargs;
+	else
+		tcp->u_nargs = 5;
+#ifdef __i386__
+	switch(regs.r_eax) {
+	case SYS___syscall:
+		umoven(tcp, regs.r_esp + sizeof(int) + sizeof(quad_t),
+		    tcp->u_nargs * sizeof(unsigned long),
+		    (char *) tcp->u_arg);
+		break;
+        case SYS_syscall:
+		umoven(tcp, regs.r_esp + 2 * sizeof(int),
+		    tcp->u_nargs * sizeof(unsigned long),
+		    (char *) tcp->u_arg);
+		break;
+        default:
+		umoven(tcp, regs.r_esp + sizeof(int),
+		    tcp->u_nargs * sizeof(unsigned long),
+		    (char *) tcp->u_arg);
+		break;
+	}
+#endif
+#ifdef __x86_64__
+{
+	int bias, i;
+	static int ar[2][6] = {
+	    { _REG_RDI, _REG_RSI, _REG_RDX,
+	      _REG_R10, _REG_R8, _REG_R9 },	/* x86-64 ABI */
+	    { _REG_RBX, _REG_RCX, _REG_RDX,
+	      _REG_RSI, _REG_RDI, _REG_RBP }	/* i386 ABI */
+	};
+	switch(regs.regs[_REG_RAX]) {
+	case SYS___syscall:
+        case SYS_syscall:
+		bias = 1;
+		break;
+        default:
+		bias = 0;
+		break;
+	}
+	for (i = 0; i < tcp->u_nargs; i++) {
+		tcp->u_arg[i] = regs.regs[ar[0][i + bias]];
+#if 0
+		if (upeek(tcp->pid, ar[0][i + bias] * 8, &tcp->u_arg[i]) < 0)
+			return -1;
+#endif
+	}
+}
+#endif
+#endif /* NETBSD */
 #ifdef FREEBSD
 	if (tcp->scno >= 0 && tcp->scno < nsyscalls &&
 	    sysent[tcp->scno].nargs > tcp->status.val)
@@ -2570,6 +2718,19 @@
 	pread(tcp->pfd_reg, &regs, sizeof(regs), 0);
 	val = regs.r_edx;
 #endif
+#ifdef NETBSD
+	struct reg regs;
+	if (ptrace(PTRACE_GETREGS, tcp->pid, (char *)&regs, sizeof(regs)) < 0) {
+		perror("PTRACE_GETREGS get edx");
+		return -1;
+	}
+#ifdef __i386__
+	val = regs.r_edx;
+#endif
+#ifdef __x86_64__
+	val = regs.regs[_REG_RDX];
+#endif
+#endif /* NETBSD */
 	return val;
 }
 
