$NetBSD: patch-libgo_go_runtime_signal__gccgo.go,v 1.1 2020/04/20 14:25:52 bsiegert Exp $

si_code is a macro on NetBSD, add a C trampoline function.

--- libgo/go/runtime/signal_gccgo.go.orig	2020-04-18 16:53:50.092569597 +0000
+++ libgo/go/runtime/signal_gccgo.go
@@ -65,7 +65,7 @@ func (c *sigctxt) sigcode() uint64 {
 		// code, just avoid a misleading value.
 		return _SI_USER + 1
 	}
-	return uint64(c.info.si_code)
+	return uint64(getSiginfoCode(c.info))
 }
 
 //go:nosplit
