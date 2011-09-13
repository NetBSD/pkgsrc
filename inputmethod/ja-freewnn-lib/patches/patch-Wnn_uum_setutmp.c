$NetBSD: patch-Wnn_uum_setutmp.c,v 1.1 2011/09/13 07:23:18 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/setutmp.c.orig	2002-06-22 13:26:21.000000000 +0000
+++ Wnn/uum/setutmp.c
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2006, 2009
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -35,7 +35,6 @@
 #include <stdio.h>
 #if STDC_HEADERS
 #  include <string.h>
-#  include <time.h>
 #else
 #  if HAVE_STRINGS_H
 #    include <strings.h>
@@ -45,14 +44,40 @@
 #  endif
 #endif /* STDC_HEADERS */
 #include <sys/types.h>
+#include <pwd.h>
 #if HAVE_FCNTL_H
 #  include <fcntl.h>
 #endif
-#include <pwd.h>
+#if TIME_WITH_SYS_TIME
+#  include <sys/time.h>
+#  include <time.h>
+#else
+#  if HAVE_SYS_TIME_H
+#    include <sys/time.h>
+#  else
+#    include <time.h>
+#  endif /* HAVE_SYS_TIME_H */
+#endif /* TIME_WITH_SYS_TIME */
 #if HAVE_UNISTD_H
 #  include <unistd.h>
 #endif
-#include <utmp.h>
+#if HAVE_UTMPX_H
+#  include <utmpx.h>
+#endif
+#if HAVE_UTMP_H
+#  include <utmp.h>
+#endif
+#if !HAVE_UTMPX_H && !HAVE_UTMP_H
+#  error "No utmp/utmpx header."
+#endif
+
+#if HAVE_STRUCT_UTMP_UT_NAME
+#  define UT_USER ut_name
+#elif HAVE_STRUCT_UTMP_UT_USER
+#  define UT_USER ut_user
+#else
+#  error "No member that indicates user in struct utmp."
+#endif
 
 #include "commonhd.h"
 #include "sdefine.h"
@@ -60,16 +85,17 @@
 
 #define public
 
-#if defined(SVR4) && !defined(DGUX)
-#include <utmpx.h>
-static struct utmpx saveut;
-static struct utmpx nullut;
-#else /* SVR4 */
+#if USE_UTMP && !HAVE_LIBSPT
+
+/* Set alias macro UTMP_TRADITIONAL */
+#if !HAVE_PUTUTXLINE && !HAVE_PUTUTLINE /* && !(defined(BSD) && (BSD >= 199306)) */
+#  define UTMP_TRADITIONAL 1
+#endif
+
+#ifdef UTMP_TRADITIONAL
 static struct utmp saveut;
 static struct utmp nullut;
-#endif /* SVR4 */
 
-#ifdef BSD42
 static int savslotnum = 0;
 static char savttynm[8];
 static int suf = 0;
@@ -82,8 +108,8 @@ static int suf = 0;
 # endif
 #endif
 
-public int
-saveutmp ()
+static int
+saveutmp_traditional (void)
 {
   register int utmpFd;
   register char *p;
@@ -103,16 +129,15 @@ saveutmp ()
   lseek (utmpFd, savslotnum * (sizeof saveut), 0);
   read (utmpFd, &saveut, sizeof saveut);
   close (utmpFd);
-  strncpy (nullut.ut_line, saveut.ut_line, 8);
-  strncpy (nullut.ut_host, saveut.ut_host, 16);
+  strncpy (nullut.ut_line, saveut.ut_line, sizeof(nullut.ut_line));
+  strncpy (nullut.ut_host, saveut.ut_host, sizeof(nullut.ut_host));
   nullut.ut_time = saveut.ut_time;
   suf = 1;
   return 0;
 }
 
-public int
-setutmp (ttyFd)
-     int ttyFd;
+static int
+setutmp_traditional (int ttyFd)
 {
   int utmpFd;
   struct utmp ut;
@@ -124,8 +149,11 @@ setutmp (ttyFd)
   bzero (&ut, sizeof ut);
   if ((p = ttyname (ttyFd)) == NULL)
     return -1;
-  strncpy (ut.ut_line, strrchr (p, '/') + 1, 8);
-  strncpy (ut.ut_name, getpwuid (getuid ())->pw_name, 8);
+
+  if (!strncmp(p, "/dev/", 5))
+    p += 5;
+  strncpy (ut.ut_line, p, sizeof (ut.ut_line));
+  strncpy (ut.UT_USER, getpwuid (getuid ())->pw_name, sizeof(ut.UT_USER));
   ut.ut_time = time (0);
   strncpy (ut.ut_host, savttynm, 8);
   if (!(i = ttyfdslot (ttyFd)))
@@ -139,94 +167,230 @@ setutmp (ttyFd)
   close (utmpFd);
   return 0;
 }
-#endif /* BSD42 */
 
-#ifdef SYSVR2
-public int
-setutmp (ttyFd)
-     int ttyFd;
+static int
+resetutmp_traditional (int ttyFd)
 {
+  int utmpFd;
   struct utmp ut;
   char *p;
-  struct passwd *getpwuid ();
+  int i;
 
-  memset (&ut, 0, sizeof ut);
+  bzero (&ut, sizeof ut);
   if ((p = ttyname (ttyFd)) == NULL)
     return -1;
-  strncpy (ut.ut_line, strrchr (p, '/') + 1, 12);
-  strncpy (ut.ut_user, getpwuid (getuid ())->pw_name, 8);
+  if (!strncmp(p, "/dev/", 5))
+    p += 5;
+  strncpy (ut.ut_line, p, sizeof(ut.ut_line));
+  /* strncpy (ut.ut_line, strrchr (p, '/') + 1, 8); */
   ut.ut_time = time (0);
+  if (!(i = ttyfdslot (ttyFd)))
+    return -1;
+  if ((utmpFd = open (_PATH_UTMP, O_RDWR, 0)) < 0)
+    return -1;
+  lseek (utmpFd, savslotnum * (sizeof saveut), 0);
+  write (utmpFd, &saveut, sizeof saveut);
+  lseek (utmpFd, i * (sizeof ut), 0);
+  write (utmpFd, &ut, sizeof ut);
+  close (utmpFd);
+  return 0;
+}
+#endif /* UTMP_TRADITIONAL */
+
+static void
+build_utid (char *ut_id, char *ut_line, int size)
+{
 #ifdef DGUX
-  strncpy (ut.ut_id, &ut.ut_line[3], 4);
+  strncpy (ut_id, &ut_line[3], size);
 #else
-  strncpy (ut.ut_id, &ut.ut_line[2], 4);
-  ut.ut_id[0] = 't';
+  /* FIXME: この辺りの命名法則がよく分からない */
+  strncpy (ut_id, &ut_line[2], size);
+  ut_id[0] = 't';
 #endif /* DGUX */
-  ut.ut_pid = getpid ();
-  ut.ut_type = USER_PROCESS;
-  setutent ();                  /* is it necessary? */
-  getutid (&ut);
-  pututline (&ut);
-  endutent ();
+}
+
+public int
+saveutmp (void)
+{
+#if UTMP_TRADITIONAL && !defined(DGUX)
+  return saveutmp_traditional();
+#else
   return 0;
+#endif
 }
-#endif /* SYSVR2 */
 
-#ifdef BSD42
 public int
-resetutmp (ttyFd)
-     int ttyFd;
+setutmp (int ttyFd)
 {
-  int utmpFd;
+#if UTMP_TRADITIONAL
+  return setutmp_traditional (ttyFd);
+#else  /* !UTMP_TRADITIONAL */
+
+#if HAVE_PUTUTXLINE
+  struct utmpx utx;
+  intfnptr saved_handler = NULL;
+#endif
   struct utmp ut;
+  int ut_err = -1;
   char *p;
-  int i;
+  /* struct passwd *getpwuid (); */
 
-  bzero (&ut, sizeof ut);
+  memset (&ut, 0, sizeof ut);
   if ((p = ttyname (ttyFd)) == NULL)
     return -1;
-  strncpy (ut.ut_line, strrchr (p, '/') + 1, 8);
+
+  if (!strncmp(p, "/dev/", 5))
+    p += 5;
+  strncpy (ut.ut_line, p, sizeof (ut.ut_line));
+  strncpy (ut.UT_USER, getpwuid (getuid ())->pw_name, sizeof(ut.UT_USER));
   ut.ut_time = time (0);
-  if (!(i = ttyfdslot (ttyFd)))
-    return -1;
-  if ((utmpFd = open (_PATH_UTMP, O_RDWR, 0)) < 0)
+#if HAVE_STRUCT_UTMP_UT_ID
+  build_utid(ut.ut_id, ut.ut_line, 4);
+  /*
+   * Maybe systems that does not have struct utmp.ut_id
+   * does not have utmp.ut_pid / ut_type ...
+   */
+  ut.ut_pid = getpid ();
+  ut.ut_type = USER_PROCESS;
+#endif
+
+#if HAVE_PUTUTXLINE
+  getutmpx (&ut, &utx);
+# if ! HAVE_STRUCT_UTMP_UT_ID
+  /* Assume all struct utmpx has this parameters ... */
+  build_utid(utx.ut_id, utx.ut_line, 4);
+  utx.ut_pid = getpid ();
+  utx.ut_type = USER_PROCESS;
+# endif
+  setutxent ();                  /* is it necessary? */
+  getutxid (&utx);
+  /*
+   * For systems that have utmp-update helper (ex. Solaris, NetBSD-4),
+   * we temporally stop using chld_handler to correctly wait()
+   * for helper on its implementation if user is normal user and
+   * uum isn't either setuid or setgid process.
+   * (You may get problem if uum catch SIGCHLD at that time ...)
+   */
+  if (getuid() != 0 && getuid() == geteuid() && getgid() == getegid()) {
+    saved_handler = signal(SIGCHLD, SIG_DFL);
+  }
+  if (pututxline (&utx) == NULL) {
+    /* perror("pututxline() failed:"); */	/* for DEBUG */
+    ut_err = 1;
+  } else {
+    ut_err = 0;
+  }
+  if (saved_handler != NULL) {
+    signal(SIGCHLD, saved_handler);	/* restore handler */
+  }
+  endutxent();
+#endif		/* HAVE_PUTUTXLINE */
+#if HAVE_PUTUTLINE
+  /* Set utmp if setting utmpx fails (or non-utmpx system) */
+  if (ut_err != 0) {
+    setutent ();			/* is it necessary? */
+    getutid (&ut);
+    pututline (&ut);			/* We don't check return value */
+    endutent ();
+    ut_err = 0;
+  }
+#endif /* HAVE_PUTUTLINE */
+  if (ut_err == 0) {
+    return 0;
+  } else {
     return -1;
-  lseek (utmpFd, savslotnum * (sizeof saveut), 0);
-  write (utmpFd, &saveut, sizeof saveut);
-  lseek (utmpFd, i * (sizeof ut), 0);
-  write (utmpFd, &ut, sizeof ut);
-  close (utmpFd);
-  return 0;
+  }
+#endif  /* !UTMP_TRADITIONAL */
 }
-#endif /* BSD42 */
 
-#ifdef SYSVR2
 public int
-resetutmp (ttyFd)
-     int ttyFd;
+resetutmp (int ttyFd)
 {
+#if UTMP_TRADITIONAL
+  return resetutmp_traditional (ttyFd);
+#else  /* !UTMP_TRADITIONAL */
+
+#if HAVE_PUTUTXLINE
+  struct utmpx utx;
+#endif
   struct utmp ut;
+  int ut_err = -1;
   char *p;
-  struct passwd *getpwuid ();
+  /* struct passwd *getpwuid (); */
 
   memset (&ut, 0, sizeof ut);
   if ((p = ttyname (ttyFd)) == NULL)
     return -1;
-  strncpy (ut.ut_line, strrchr (p, '/') + 1, 12);
-  strncpy (ut.ut_user, getpwuid (getuid ())->pw_name, 8);
+  if (!strncmp(p, "/dev/", 5))
+    p += 5;
+  strncpy (ut.ut_line, p, sizeof (ut.ut_line));
+/*   strncpy (ut.ut_line, strrchr (p, '/') + 1, 12); */
+  strncpy (ut.UT_USER, getpwuid (getuid ())->pw_name, sizeof(ut.UT_USER));
   ut.ut_time = time (0);
-#ifdef DGUX
-  strncpy (ut.ut_id, &ut.ut_line[3], 4);
-#else
-  strncpy (ut.ut_id, &ut.ut_line[2], 4);
-  ut.ut_id[0] = 't';
-#endif /* DGUX */
+#if HAVE_STRUCT_UTMP_UT_ID
+  build_utid(ut.ut_id, ut.ut_line, 4);
+  /*
+   * Maybe systems that does not have struct utmp.ut_id
+   * does not have utmp.ut_pid / ut_type ...
+   */
   ut.ut_pid = getpid ();
   ut.ut_type = DEAD_PROCESS;    /* not sure */
-  setutent ();                  /* is it necessary? */
-  getutid (&ut);
-  pututline (&ut);
-  endutent ();
+#endif
+
+#if HAVE_PUTUTXLINE
+  getutmpx (&ut, &utx);
+# if ! HAVE_STRUCT_UTMP_UT_ID
+  /* Assume all struct utmpx has this parameters ... */
+  build_utid(utx.ut_id, utx.ut_line, 4);
+  utx.ut_pid = getpid ();
+  utx.ut_type = DEAD_PROCESS;	/* not sure */
+# endif
+  setutxent ();                  /* is it necessary? */
+  getutxid (&utx);
+  /* We don't change SIGCHLD handler for now */
+  if (pututxline (&utx) == NULL) {
+    ut_err = 1;
+  } else {
+    ut_err = 0;
+  }
+  endutxent();
+#endif		/* HAVE_PUTUTXLINE */
+#if HAVE_PUTUTLINE
+  /* Set utmp if setting utmpx fails (or non-utmpx system) */
+  if (ut_err != 0) {
+    setutent ();                  /* is it necessary? */
+    getutid (&ut);
+    pututline (&ut);		  /* We don't check return value */
+    endutent ();
+    ut_err = 0;
+  }
+#endif /* HAVE_PUTUTLINE */
+  if (ut_err == 0) {
+    return 0;
+  } else {
+    return -1;
+  }
   return 0;
+#endif  /* !UTMP_TRADITIONAL */
+}
+
+#else  /* ! USE_UTMP */
+/* We don't use setutmp feature. Set dummy function. */
+public int
+saveutmp (void)
+{
+  return 1;
+}
+
+public int
+setutmp (int ttyFd)
+{
+  return 1;
+}
+
+public int
+resetutmp (int ttyFd)
+{
+  return 1;
 }
-#endif /* SYSVR2 */
+#endif  /* ! USE_UTMP */
