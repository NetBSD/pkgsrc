$NetBSD: patch-Makefile.inc,v 1.2 2022/08/16 13:02:56 adam Exp $

Unlock install target.

--- Makefile.inc.orig	2022-08-15 22:45:31.000000000 +0000
+++ Makefile.inc
@@ -79,11 +79,7 @@ VOID  := /dev/null
   endif
 endif
 
-ifneq (,$(filter Linux Darwin GNU/kFreeBSD GNU OpenBSD FreeBSD NetBSD DragonFly SunOS Haiku MidnightBSD MINGW% CYGWIN% MSYS%,$(shell $(UNAME))))
 POSIX_ENV = Yes
-else
-POSIX_ENV = No
-endif
 
 # Avoid symlinks when targeting Windows or building on a Windows host
 ifeq ($(WINBASED),yes)
