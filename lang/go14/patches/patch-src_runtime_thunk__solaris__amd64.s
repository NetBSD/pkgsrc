$NetBSD: patch-src_runtime_thunk__solaris__amd64.s,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/runtime/thunk_solaris_amd64.s.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/runtime/thunk_solaris_amd64.s
@@ -8,81 +8,81 @@
 #include "textflag.h"
 
 TEXT runtime·libc_chdir(SB),NOSPLIT,$0
-	MOVQ	libc·chdir(SB), AX
+	LEAQ	libc·chdir(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_chroot(SB),NOSPLIT,$0
-	MOVQ	libc·chroot(SB), AX
+	LEAQ	libc·chroot(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_close(SB),NOSPLIT,$0
-	MOVQ	libc·close(SB), AX
+	LEAQ	libc·close(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_dlopen(SB),NOSPLIT,$0
-	MOVQ	libc·dlopen(SB), AX
+	LEAQ	libc·dlopen(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_dlclose(SB),NOSPLIT,$0
-	MOVQ	libc·dlclose(SB), AX
+	LEAQ	libc·dlclose(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_dlsym(SB),NOSPLIT,$0
-	MOVQ	libc·dlsym(SB), AX
+	LEAQ	libc·dlsym(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_execve(SB),NOSPLIT,$0
-	MOVQ	libc·execve(SB), AX
+	LEAQ	libc·execve(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_exit(SB),NOSPLIT,$0
-	MOVQ	libc·exit(SB), AX
+	LEAQ	libc·exit(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_fcntl(SB),NOSPLIT,$0
-	MOVQ	libc·fcntl(SB), AX
+	LEAQ	libc·fcntl(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_forkx(SB),NOSPLIT,$0
-	MOVQ	libc·forkx(SB), AX
+	LEAQ	libc·forkx(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_gethostname(SB),NOSPLIT,$0
-	MOVQ	libc·gethostname(SB), AX
+	LEAQ	libc·gethostname(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_ioctl(SB),NOSPLIT,$0
-	MOVQ	libc·ioctl(SB), AX
+	LEAQ	libc·ioctl(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_setgid(SB),NOSPLIT,$0
-	MOVQ	libc·setgid(SB), AX
+	LEAQ	libc·setgid(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_setgroups(SB),NOSPLIT,$0
-	MOVQ	libc·setgroups(SB), AX
+	LEAQ	libc·setgroups(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_setsid(SB),NOSPLIT,$0
-	MOVQ	libc·setsid(SB), AX
+	LEAQ	libc·setsid(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_setuid(SB),NOSPLIT,$0
-	MOVQ	libc·setuid(SB), AX
+	LEAQ	libc·setuid(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_setpgid(SB),NOSPLIT,$0
-	MOVQ	libc·setpgid(SB), AX
+	LEAQ	libc·setpgid(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_syscall(SB),NOSPLIT,$0
-	MOVQ	libc·syscall(SB), AX
+	LEAQ	libc·syscall(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_wait4(SB),NOSPLIT,$0
-	MOVQ	libc·wait4(SB), AX
+	LEAQ	libc·wait4(SB), AX
 	JMP	AX
 
 TEXT runtime·libc_write(SB),NOSPLIT,$0
-	MOVQ	libc·write(SB), AX
+	LEAQ	libc·write(SB), AX
 	JMP	AX
