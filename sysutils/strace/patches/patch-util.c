$NetBSD: patch-util.c,v 1.1 2019/01/22 22:07:33 christos Exp $

--- util.c.orig	2007-01-11 17:08:38.000000000 -0500
+++ util.c	2019-01-22 16:54:09.288699797 -0500
@@ -36,9 +36,11 @@
 #include "defs.h"
 
 #include <signal.h>
+#include <sys/param.h>
 #include <sys/syscall.h>
+#ifndef NETBSD
 #include <sys/user.h>
-#include <sys/param.h>
+#endif
 #include <fcntl.h>
 #if HAVE_SYS_UIO_H
 #include <sys/uio.h>
@@ -58,6 +60,9 @@
 # include <asm/rse.h>
 #endif
 
+#ifdef NETBSD
+#include <machine/reg.h>
+#endif
 #ifdef HAVE_SYS_REG_H
 #include <sys/reg.h>
 # define PTRACE_PEEKUSR PTRACE_PEEKUSER
@@ -96,6 +101,7 @@
 # define PTRACE_SETREGS PTRACE_SETREGS64
 #endif /* SPARC64 */
 
+
 #if !defined(__GLIBC__)
 
 #include <linux/unistd.h>
@@ -777,6 +783,20 @@
 		return -1;
 #endif /* USE_PROCFS */
 
+#ifdef NETBSD
+	struct ptrace_io_desc piod;
+
+	piod.piod_op = PIOD_READ_D;
+	piod.piod_offs = (void *)addr;
+	piod.piod_addr = laddr;
+	piod.piod_len = len;
+
+	if (ptrace(PT_IO, tcp->pid, (char *)&piod, sizeof(piod)) < 0) {
+		perror("PT_IO");
+		return -1;
+	}
+#endif
+
 	return 0;
 }
 
@@ -1097,6 +1117,14 @@
 	pread(tcp->pfd_reg, &regs, sizeof(regs), 0);
 	return regs.r_eip;
 #endif /* FREEBSD */
+#ifdef NETBSD
+	struct reg regs;
+	if (ptrace(PTRACE_GETREGS, tcp->pid, (char *) &regs, 0) < 0) {
+		perror("getpc: ptrace(PTRACE_GETREGS, ...)");
+		return -1;
+	}
+	return regs.r_eip;
+#endif /* NETBSD */
 }
 #endif
 
