$NetBSD: patch-src_polkit_polkitunixprocess.c,v 1.2 2016/06/18 12:16:23 youri Exp $

* NetBSD support
* SunOS support

--- src/polkit/polkitunixprocess.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ src/polkit/polkitunixprocess.c
@@ -29,10 +29,19 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <stdio.h>
+#include <fcntl.h>
+
+#ifdef HAVE_SOLARIS
+#include <procfs.h>
+#endif
 
 #include "polkitunixprocess.h"
 #include "polkitsubject.h"
@@ -80,7 +89,7 @@ enum
 
 static void subject_iface_init (PolkitSubjectIface *subject_iface);
 
-static guint64 get_start_time_for_pid (gint    pid,
+static guint64 get_start_time_for_pid (pid_t    pid,
                                        GError **error);
 
 static gint _polkit_unix_process_get_owner (PolkitUnixProcess  *process,
@@ -89,6 +98,9 @@ static gint _polkit_unix_process_get_own
 #ifdef HAVE_FREEBSD
 static gboolean get_kinfo_proc (gint pid, struct kinfo_proc *p);
 #endif
+#if defined(__NetBSD__)
+static gboolean get_kinfo_proc (gint pid, struct kinfo_proc2 *p);
+#endif
 
 G_DEFINE_TYPE_WITH_CODE (PolkitUnixProcess, polkit_unix_process, G_TYPE_OBJECT,
                          G_IMPLEMENT_INTERFACE (POLKIT_TYPE_SUBJECT, subject_iface_init)
@@ -514,17 +526,17 @@ subject_iface_init (PolkitSubjectIface *
 
 #ifdef HAVE_SOLARIS
 static int
-get_pid_psinfo (pid_t pid, struct psinfo *ps)
+get_pid_psinfo (pid_t pid, psinfo_t *ps)
 {
   char pname[32];
   int  procfd;
 
-  (void) snprintf(pname, sizeof(pname), "/proc/%d/psinfo", pid);
+  (void) snprintf(pname, sizeof(pname), "/proc/%lu/psinfo", pid);
   if ((procfd = open(pname, O_RDONLY)) == -1)
     {
       return -1;
     }
-  if (read(procfd, ps, sizeof(struct psinfo)) < 0)
+  if (read(procfd, ps, sizeof(psinfo_t)) < 0)
     {
       (void) close(procfd);
       return -1;
@@ -554,12 +566,38 @@ get_kinfo_proc (pid_t pid, struct kinfo_
 }
 #endif
 
+#ifdef __NetBSD__
+static gboolean
+get_kinfo_proc (pid_t pid, struct kinfo_proc2 *p)
+{
+  int name[6];
+  u_int namelen;
+  size_t sz;
+
+  sz = sizeof(*p);
+  namelen = 0;
+  name[namelen++] = CTL_KERN;
+  name[namelen++] = KERN_PROC2;
+  name[namelen++] = KERN_PROC_PID;
+  name[namelen++] = pid;
+  name[namelen++] = sz;
+  name[namelen++] = 1;
+
+  if (sysctl (name, namelen, p, &sz, NULL, 0) == -1) {
+    perror("sysctl kern.proc2.pid");
+    return FALSE;
+  }
+
+  return TRUE;
+}
+#endif
+
 static guint64
 get_start_time_for_pid (pid_t    pid,
                         GError **error)
 {
   guint64 start_time;
-#ifndef HAVE_FREEBSD
+#if !defined(HAVE_FREEBSD) || !defined(__NetBSD__)
   gchar *filename;
   gchar *contents;
   size_t length;
@@ -571,7 +609,7 @@ get_start_time_for_pid (pid_t    pid,
   start_time = 0;
   contents = NULL;
 
-  filename = g_strdup_printf ("/proc/%d/stat", pid);
+  filename = g_strdup_printf ("/proc/%lu/stat", pid);
 
   if (!g_file_get_contents (filename, &contents, &length, error))
     goto out;
@@ -631,8 +669,8 @@ get_start_time_for_pid (pid_t    pid,
  out:
   g_free (filename);
   g_free (contents);
-#else
-  struct kinfo_proc p;
+#elif defined(__NetBSD__)
+  struct kinfo_proc2 p;
 
   start_time = 0;
 
@@ -647,9 +685,43 @@ get_start_time_for_pid (pid_t    pid,
       goto out;
     }
 
+  start_time = (guint64) p.p_ustart_sec;
+
+out:
+
+#elif HAVE_FREEBSD
+  struct kinfo_proc p;
+
+  if (! get_kinfo_proc (pid, &p))
+    {
+      g_set_error (error,
+                   POLKIT_ERROR,
+                   POLKIT_ERROR_FAILED,
+                   "Error obtaining start time for %d (%s)",
+                   (gint) pid,
+                   g_strerror (errno));
+      goto out;
+    }
+
   start_time = (guint64) p.ki_start.tv_sec;
 
 out:
+#elif HAVE_SOLARIS
+  psinfo_t p;
+  if (!get_pid_psinfo (pid, &p))
+    {
+      g_set_error (error,
+                   POLKIT_ERROR,
+                   POLKIT_ERROR_FAILED,
+                   "Error obtaining start time for %d (%s)",
+                   (gint) pid,
+                   g_strerror (errno));
+      goto out;
+    }
+  start_time = (guint64) p.pr_start.tv_sec;
+out:
+#else
+#warning Your system is not supported
 #endif
 
   return start_time;
@@ -664,6 +736,10 @@ _polkit_unix_process_get_owner (PolkitUn
   gchar **lines;
 #ifdef HAVE_FREEBSD
   struct kinfo_proc p;
+#elif defined(__NetBSD__)
+  struct kinfo_proc2 p;
+#elif HAVE_SOLARIS
+       psinfo_t p;
 #else
   gchar filename[64];
   guint n;
@@ -676,7 +752,7 @@ _polkit_unix_process_get_owner (PolkitUn
   lines = NULL;
   contents = NULL;
 
-#ifdef HAVE_FREEBSD
+#if defined(HAVE_FREEBSD) || defined(__NetBSD__)
   if (get_kinfo_proc (process->pid, &p) == 0)
     {
       g_set_error (error,
@@ -688,7 +764,23 @@ _polkit_unix_process_get_owner (PolkitUn
       goto out;
     }
 
+#ifdef __NetBSD__
+  result = p.p_uid;
+#else
   result = p.ki_uid;
+#endif
+#elif HAVE_SOLARIS
+  if (!get_pid_psinfo (process->pid, &p))
+    {
+      g_set_error (error,
+                   POLKIT_ERROR,
+                   POLKIT_ERROR_FAILED,
+                   "get_pid_psinfo() failed for pid %d: %s",
+                   process->pid,
+                   g_strerror (errno));
+      goto out;
+    }
+  result = p.pr_uid;
 #else
 
   /* see 'man proc' for layout of the status file
