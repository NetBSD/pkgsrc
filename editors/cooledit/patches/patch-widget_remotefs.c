$NetBSD: patch-widget_remotefs.c,v 1.1 2026/10/20 20:57:33 ktnb Exp $

Use sys/types.h and for NetBSD the ENOTRECOVERABLE is overloaded

--- widget/remotefs.c.orig	2026-10-20 19:20:39.192308607 +0000
+++ widget/remotefs.c
@@ -65,7 +65,7 @@
 #include <sys/signal.h>
 #include <signal.h>
 #include <sys/file.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 /* major()/minor() are macros in <sys/types.h> on FreeBSD */
 #elif defined(__sun) || defined(__sun__)
 #include <sys/mkdev.h>
@@ -1538,7 +1538,7 @@ static int translate_unix_errno (int err)
     case ENOTNAM:
         return RFSERR_ENOTNAM;
 #endif
-#ifdef ENOTRECOVERABLE
+#if defined(ENOTRECOVERABLE) && !defined(__NetBSD__)
     case ENOTRECOVERABLE:
         return RFSERR_ENOTRECOVERABLE;
 #endif
