$NetBSD: patch-include_private_gcconfig.h,v 1.7 2023/05/28 06:12:21 dholland Exp $

Recognize riscv on netbsd. https://github.com/ivmai/bdwgc/issues/556

--- include/private/gcconfig.h~	2022-08-26 18:44:49.000000000 +0000
+++ include/private/gcconfig.h
@@ -676,7 +676,7 @@ EXTERN_C_BEGIN
 #   define mach_type_known
 # endif
 # if defined(__riscv) && (defined(FREEBSD) || defined(LINUX) \
-                          || defined(OPENBSD))
+                          || defined(NETBSD) || defined(OPENBSD))
 #   define RISCV
 #   define mach_type_known
 # endif
