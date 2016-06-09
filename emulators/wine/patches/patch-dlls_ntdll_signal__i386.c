$NetBSD: patch-dlls_ntdll_signal__i386.c,v 1.1 2016/06/09 15:26:35 fhajny Exp $

SunOS needs sys/regset.h for registers too.

--- dlls/ntdll/signal_i386.c.orig	2014-01-10 20:37:29.000000000 +0000
+++ dlls/ntdll/signal_i386.c
@@ -269,7 +269,7 @@ typedef struct sigcontext SIGCONTEXT;
 
 #elif defined(__svr4__) || defined(_SCO_DS) || defined(__sun)
 
-#ifdef _SCO_DS
+#if defined(_SCO_DS) || defined(__sun)
 #include <sys/regset.h>
 #endif
 #include <sys/ucontext.h>
