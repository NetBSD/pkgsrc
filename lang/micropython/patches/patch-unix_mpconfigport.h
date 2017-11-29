$NetBSD: patch-unix_mpconfigport.h,v 1.2 2017/11/29 15:13:32 hauke Exp $

Modern *BSDs heclare  alloca() in <stdlib.h>

--- unix/mpconfigport.h.orig	2017-08-23 01:50:11.000000000 +0000
+++ unix/mpconfigport.h
@@ -291,7 +291,8 @@ void mp_unix_mark_exec(void);
 // We need to provide a declaration/definition of alloca()
 // unless support for it is disabled.
 #if !defined(MICROPY_NO_ALLOCA) || MICROPY_NO_ALLOCA == 0
-#ifdef __FreeBSD__
+#include <sys/param.h>
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #include <stdlib.h>
 #else
 #include <alloca.h>
