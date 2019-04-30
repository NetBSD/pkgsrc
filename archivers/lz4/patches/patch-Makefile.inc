$NetBSD: patch-Makefile.inc,v 1.1 2019/04/30 09:17:38 adam Exp $

Unlock install target.

--- Makefile.inc.orig	2019-04-30 08:08:05.000000000 +0000
+++ Makefile.inc
@@ -51,11 +51,7 @@ VOID  := /dev/null
   endif
 endif
 
-ifneq (,$(filter Linux Darwin GNU/kFreeBSD GNU OpenBSD FreeBSD NetBSD DragonFly SunOS Haiku MidnightBSD MINGW% CYGWIN% MSYS%,$(shell uname)))
 POSIX_ENV = Yes
-else
-POSIX_ENV = No
-endif
 
 # Avoid symlinks when targetting Windows or building on a Windows host
 ifeq ($(WINBASED),yes)
