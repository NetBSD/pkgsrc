$NetBSD: patch-plugins_sudoers_starttime.c,v 1.1 2018/08/14 13:18:38 adam Exp $

Fix typo.

--- plugins/sudoers/starttime.c.orig	2018-08-14 13:09:35.389271668 +0000
+++ plugins/sudoers/starttime.c
@@ -24,7 +24,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(HAVE_KINFO_PROC_44BSD) || defined (HAVE_KINFO_PROC_OPENBSD) || defined(HAVE_KINFO_PROC2_NETBSD2)
+#if defined(HAVE_KINFO_PROC_44BSD) || defined (HAVE_KINFO_PROC_OPENBSD) || defined(HAVE_KINFO_PROC2_NETBSD)
 # include <sys/sysctl.h>
 #elif defined(HAVE_KINFO_PROC_FREEBSD)
 # include <sys/sysctl.h>
