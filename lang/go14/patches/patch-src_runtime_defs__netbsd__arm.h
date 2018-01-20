$NetBSD: patch-src_runtime_defs__netbsd__arm.h,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Change to EABI in netbsd/arm  the aliment is changed when 64bit value.

--- src/runtime/defs_netbsd_arm.h.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/defs_netbsd_arm.h
@@ -119,10 +119,12 @@ struct StackT {
 struct Timespec {
 	int64	tv_sec;
 	int32	tv_nsec;
+	byte	Pad_cgo_0[4];
 };
 struct Timeval {
 	int64	tv_sec;
 	int32	tv_usec;
+	byte	Pad_cgo_0[4];
 };
 struct Itimerval {
 	Timeval	it_interval;
@@ -131,18 +133,18 @@ struct Itimerval {
 
 struct McontextT {
 	uint32	__gregs[17];
-#ifdef __ARM_EABI__
-	byte	__fpu[4+8*32+4];
-#else
-	byte	__fpu[4+4*33+4];
-#endif
+	byte	Pad_cgo_0[4];
+	// For EABI, fpscr[4]+pad[4]+fstmx[8*32]+fpsid[4]+pad[4]
+	byte	__fpu[272];
 	uint32	_mc_tlsbase;
+	byte	Pad_cgo_1[4];
 };
 struct UcontextT {
 	uint32	uc_flags;
 	UcontextT	*uc_link;
 	Sigset	uc_sigmask;
 	StackT	uc_stack;
+	byte	Pad_cgo_0[4];
 	McontextT	uc_mcontext;
 	int32	__uc_pad[2];
 };
@@ -154,6 +156,7 @@ struct KeventT {
 	uint32	fflags;
 	int64	data;
 	byte	*udata;
+	byte	Pad_cgo_0[4];
 };
 
 
