$NetBSD: patch-include_unixconf.h,v 1.1 2019/10/24 11:51:23 pho Exp $

Make configurable.
Fix for BSD.

--- include/unixconf.h.orig	2019-05-08 07:00:15.000000000 +0000
+++ include/unixconf.h
@@ -20,19 +20,20 @@
  */
 
 /* define exactly one of the following four choices */
+#define @NETHACK_OS@ 1
 /* #define BSD 1 */  /* define for 4.n/Free/Open/Net BSD  */
                      /* also for relatives like SunOS 4.x, DG/UX, and */
                      /* older versions of Linux */
 /* #define ULTRIX */ /* define for Ultrix v3.0 or higher (but not lower) */
                      /* Use BSD for < v3.0 */
                      /* "ULTRIX" not to be confused with "ultrix" */
-#define SYSV         /* define for System V, Solaris 2.x, newer versions */
+/* #define SYSV */   /* define for System V, Solaris 2.x, newer versions */
                      /* of Linux */
 /* #define HPUX */   /* Hewlett-Packard's Unix, version 6.5 or higher */
                      /* use SYSV for < v6.5 */
 
 /* define any of the following that are appropriate */
-#define SVR4           /* use in addition to SYSV for System V Release 4 */
+/* #define SVR4 */     /* use in addition to SYSV for System V Release 4 */
                        /* including Solaris 2+ */
 #define NETWORK        /* if running on a networked system */
                        /* e.g. Suns sharing a playground through NFS */
@@ -49,7 +50,7 @@
                         * job control (note that AIX is SYSV otherwise)
                         * Also define this for AIX 3.2 */
 
-#define TERMINFO       /* uses terminfo rather than termcap */
+/* #define TERMINFO */ /* uses terminfo rather than termcap */
                        /* Should be defined for most SYSV, SVR4 (including
                         * Solaris 2+), HPUX, and Linux systems.  In
                         * particular, it should NOT be defined for the UNIXPC
@@ -106,7 +107,7 @@
  * If you want the static parts of your playground on a read-only file
  * system, define VAR_PLAYGROUND to be where the variable parts are kept.
  */
-/* #define VAR_PLAYGROUND "/var/lib/games/nethack" */
+#define VAR_PLAYGROUND "@VARDIR@"
 
 /*
  * Define DEF_PAGER as your default pager, e.g. "/bin/cat" or "/usr/ucb/more"
@@ -176,7 +177,7 @@
 #ifdef AMS
 #define AMS_MAILBOX "/Mailbox"
 #else
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #define DEF_MAILREADER "/usr/bin/mail"
 #else
 #define DEF_MAILREADER "/usr/ucb/Mail"
@@ -330,7 +331,7 @@
 #endif
 
 #if defined(BSD) || defined(ULTRIX)
-#if !defined(DGUX) && !defined(SUNOS4)
+#if !defined(DGUX) && !defined(SUNOS4) && !defined(BSD)
 #define memcpy(d, s, n) bcopy(s, d, n)
 #define memcmp(s1, s2, n) bcmp(s2, s1, n)
 #endif
