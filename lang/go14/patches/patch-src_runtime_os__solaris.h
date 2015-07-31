$NetBSD: patch-src_runtime_os__solaris.h,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/runtime/os_solaris.h.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/runtime/os_solaris.h
@@ -43,13 +43,13 @@ int32   runtime·getrlimit(int32, Rlimit
 
 // Call an external library function described by {fn, a0, ..., an}, with
 // SysV conventions, switching to os stack during the call, if necessary.
-uintptr	runtime·sysvicall0(uintptr fn);
-uintptr	runtime·sysvicall1(uintptr fn, uintptr a1);
-uintptr	runtime·sysvicall2(uintptr fn, uintptr a1, uintptr a2);
-uintptr	runtime·sysvicall3(uintptr fn, uintptr a1, uintptr a2, uintptr a3);
-uintptr	runtime·sysvicall4(uintptr fn, uintptr a1, uintptr a2, uintptr a3, uintptr a4);
-uintptr	runtime·sysvicall5(uintptr fn, uintptr a1, uintptr a2, uintptr a3, uintptr a4, uintptr a5);
-uintptr	runtime·sysvicall6(uintptr fn, uintptr a1, uintptr a2, uintptr a3, uintptr a4, uintptr a5, uintptr a6);
+uintptr	runtime·sysvicall0(uintptr (*fn)());
+uintptr	runtime·sysvicall1(uintptr (*fn)(), uintptr a1);
+uintptr	runtime·sysvicall2(uintptr (*fn)(), uintptr a1, uintptr a2);
+uintptr	runtime·sysvicall3(uintptr (*fn)(), uintptr a1, uintptr a2, uintptr a3);
+uintptr	runtime·sysvicall4(uintptr (*fn)(), uintptr a1, uintptr a2, uintptr a3, uintptr a4);
+uintptr	runtime·sysvicall5(uintptr (*fn)(), uintptr a1, uintptr a2, uintptr a3, uintptr a4, uintptr a5);
+uintptr	runtime·sysvicall6(uintptr (*fn)(), uintptr a1, uintptr a2, uintptr a3, uintptr a4, uintptr a5, uintptr a6);
 void	runtime·asmsysvicall6(void *c);
 
 void	runtime·miniterrno(void *fn);
