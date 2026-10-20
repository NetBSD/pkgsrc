$NetBSD: patch-widget_cterminal.c,v 1.1 2026/10/20 20:57:33 ktnb Exp $

Fixed stuff that doesn't work on NetBSD

--- widget/cterminal.c.orig	2026-10-20 19:23:46.183486896 +0000
+++ widget/cterminal.c
@@ -77,7 +77,7 @@
 #ifdef TTY_GID_SUPPORT
 #include <grp.h>
 #endif
-#if defined(PTYS_ARE_PTMX) && !defined(__FreeBSD__) && !defined(__DragonFly__)
+#if defined(PTYS_ARE_PTMX) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 #include <sys/resource.h>       /* for struct rlimit */
 #include <sys/stropts.h>        /* for I_PUSH */
 #endif
@@ -118,7 +118,7 @@
 
 #define UTMP_SUPPORT
 
-#if defined(__FreeBSD__) || defined(__sun)
+#if defined(__FreeBSD__) || defined(__sun) || defined(__NetBSD__)
 #define HAVE_STRUCT_UTMPX
 #define RXVT_UTMP_AS_UTMPX
 #define HAVE_UTMPX_HOST
@@ -345,7 +345,7 @@ static int cterminal_get_tty (struct cterminal *o, cha
         snprintf (errmsg, CTERMINAL_ERR_MSG_LEN, "can't open slave tty %s [%s]", o->ttydev, strerror (errno));
         return -1;
     }
-#if defined(PTYS_ARE_PTMX) && !defined(__FreeBSD__) && !defined(__DragonFly__)
+#if defined(PTYS_ARE_PTMX) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 /*
  * Push STREAMS modules:
  *    ptem: pseudo-terminal hardware emulation module.
@@ -726,7 +726,7 @@ int cterminal_get_pty (struct cterminal *o, char *errm
         o->ttydev = 0;
     }
 
-#if defined(__FreeBSD__) || defined(__sun)
+#if defined(__FreeBSD__) || defined(__sun) || defined(__NetBSD__)
     fd = posix_openpt (O_RDWR);
     if (fd >= 0) {
         if (grantpt (fd) == 0   /* change slave permissions */
@@ -1413,7 +1413,7 @@ static void cterminal_makeutent_ (struct wtmp_command 
 
 /* set up the new entry */
     ut.ut_type = dead ? DEAD_PROCESS : USER_PROCESS;
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(__FreeBSD__) && !defined(__NetBSD__)
     ut.ut_exit.e_exit = 2;
 #endif
     strncpy (ut.ut_user, (pwent && pwent->pw_name) ? pwent->pw_name : "?",
@@ -1429,7 +1429,7 @@ static void cterminal_makeutent_ (struct wtmp_command 
 # endif
 #endif
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 /* ut_name is normally the same as ut_user, but .... */
     strncpy (ut.ut_name, (pwent && pwent->pw_name) ? pwent->pw_name : "?",
 	     sizeof (ut.ut_name));
@@ -1438,7 +1438,7 @@ static void cterminal_makeutent_ (struct wtmp_command 
     ut.ut_pid = tc->pid;
 
 #ifdef RXVT_UTMP_AS_UTMPX
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     ut.ut_session = tc->sid;
 #endif
     ut.ut_tv.tv_sec = tc->now;
