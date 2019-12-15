$NetBSD: patch-plugins_sudoers_starttime.c,v 1.2 2019/12/15 18:42:10 adam Exp $

Fix a typo.

--- plugins/sudoers/starttime.c.orig	2019-10-28 12:28:52.000000000 +0000
+++ plugins/sudoers/starttime.c
@@ -31,7 +31,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(HAVE_KINFO_PROC_44BSD) || defined (HAVE_KINFO_PROC_OPENBSD) || defined(HAVE_KINFO_PROC2_NETBSD2)
+#if defined(HAVE_KINFO_PROC_44BSD) || defined (HAVE_KINFO_PROC_OPENBSD) || defined(HAVE_KINFO_PROC2_NETBSD)
 # include <sys/sysctl.h>
 #elif defined(HAVE_KINFO_PROC_FREEBSD)
 # include <sys/param.h>
