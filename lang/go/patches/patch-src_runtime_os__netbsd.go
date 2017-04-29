# $NetBSD: patch-src_runtime_os__netbsd.go,v 1.1.2.2 2017/04/29 19:32:54 bsiegert Exp $

--- src/runtime/os_netbsd.go.orig	2017-04-07 12:54:08.000000000 -0400
+++ src/runtime/os_netbsd.go	2017-04-19 17:08:10.806553689 -0400
@@ -167,13 +167,23 @@
 	var uc ucontextt
 	getcontext(unsafe.Pointer(&uc))
 
+	// XXX: _UC_SIGMASK does not seem to work here.
+	// It would be nice if _UC_SIGMASK and _UC_STACK
+	// worked so that we could do all the work setting
+	// the sigmask and the stack here, instead of setting
+	// the mask here and the stack in netbsdMstart
+	// For now do the blocking manually.
 	uc.uc_flags = _UC_SIGMASK | _UC_CPU
 	uc.uc_link = nil
 	uc.uc_sigmask = sigset_all
 
+	var oset sigset
+	sigprocmask(_SIG_SETMASK, &sigset_all, &oset)
+
 	lwp_mcontext_init(&uc.uc_mcontext, stk, mp, mp.g0, funcPC(netbsdMstart))
 
 	ret := lwp_create(unsafe.Pointer(&uc), 0, unsafe.Pointer(&mp.procid))
+	sigprocmask(_SIG_SETMASK, &oset, nil)
 	if ret < 0 {
 		print("runtime: failed to create new OS thread (have ", mcount()-1, " already; errno=", -ret, ")\n")
 		if ret == -_EAGAIN {
