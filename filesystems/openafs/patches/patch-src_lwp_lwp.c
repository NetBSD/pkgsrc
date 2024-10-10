$NetBSD: patch-src_lwp_lwp.c,v 1.3 2024/10/10 15:19:04 jakllsch Exp $

- Like Linux & Darwin, exclude *BSD on 32-bit ARM from the bespoke LWP handling mechanism.

--- src/lwp/lwp.c.orig	2022-12-15 20:10:23.000000000 +0000
+++ src/lwp/lwp.c
@@ -365,7 +365,7 @@ LWP_CreateProcess(void *(*ep) (void *),
 	Initialize_PCB(temp, priority, stackmemory, stacksize, ep, parm, name);
 	insert(temp, &runnable[priority]);
 	temp2 = lwp_cpptr;
-#if !defined(AFS_ARM_LINUX_ENV) && !defined(AFS_ARM_DARWIN_ENV)
+#if !defined(AFS_ARM_LINUX_ENV) && !defined(AFS_ARM_DARWIN_ENV) && !defined(AFS_ARM32_XBSD_ENV)
 	if (PRE_Block != 0)
 	    Abort_LWP("PRE_Block not 0");
 
@@ -456,7 +456,7 @@ LWP_CreateProcess2(void *(*ep) (void *),
 	Initialize_PCB(temp, priority, stackptr, stacksize, ep, parm, name);
 	insert(temp, &runnable[priority]);
 	temp2 = lwp_cpptr;
-#if !defined(AFS_ARM_LINUX_ENV) && !defined(AFS_ARM_DARWIN_ENV)
+#if !defined(AFS_ARM_LINUX_ENV) && !defined(AFS_ARM_DARWIN_ENV) && !defined(AFS_ARM32_XBSD_ENV)
 	if (PRE_Block != 0)
 	    Abort_LWP("PRE_Block not 0");
 
@@ -956,7 +956,7 @@ Dispatcher(void)
 	printf("Dispatch %d [PCB at 0x%x] \"%s\"\n", ++dispatch_count,
 	       runnable[i].head, runnable[i].head->name);
 #endif
-#if !defined(AFS_ARM_LINUX_ENV) && !defined(AFS_ARM_DARWIN_ENV)
+#if !defined(AFS_ARM_LINUX_ENV) && !defined(AFS_ARM_DARWIN_ENV) && !defined(AFS_ARM32_XBSD_ENV)
     if (PRE_Block != 1)
 	Abort_LWP("PRE_Block not 1");
 #endif
