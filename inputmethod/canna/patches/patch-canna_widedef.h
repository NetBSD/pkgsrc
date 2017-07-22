$NetBSD: patch-canna_widedef.h,v 1.2 2017/07/22 17:53:16 maya Exp $

DragonFly wchar_t support.
apple and freebsd no longer have machine/ansi.h
freebsd probably needs sys/_types.h as it does on gcc which is the
source of this file.

--- canna/widedef.h.orig	2003-12-27 17:15:20.000000000 +0000
+++ canna/widedef.h
@@ -29,14 +29,17 @@
 
 #ifdef __FreeBSD__
 # include <osreldate.h>
+# include <sys/_types.h>
 #endif
 
-#if (defined(__FreeBSD__) && __FreeBSD_version < 500000) \
-    || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 # include <machine/ansi.h>
 #endif
 
-#if (defined(__FreeBSD__) && __FreeBSD_version < 500000) \
+#if defined(__DragonFly__)
+# include <wchar.h>
+# define _WCHAR_T
+#elif (defined(__FreeBSD__) && __FreeBSD_version < 500000) \
     || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
 # ifdef _BSD_WCHAR_T_
 #  undef _BSD_WCHAR_T_
