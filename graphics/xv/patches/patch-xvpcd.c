$NetBSD: patch-xvpcd.c,v 1.1 2019/02/21 14:32:32 tsutsui Exp $

- remove obsolete alloca check

--- xvpcd.c.orig	2007-05-14 01:02:13.000000000 +0000
+++ xvpcd.c
@@ -30,9 +30,6 @@
 #ifdef HAVE_PCD
 
 #include <memory.h>
-#ifndef alloca
-#  include <alloca.h> /* "not in POSIX or SUSv3" according to Linux man page */
-#endif                /* ...but required for Sun C compiler (alloca = macro) */
 
 #define  TRACE  0
 #if TRACE
