$NetBSD: patch-egg_egg-unix-credentials.c,v 1.1 2020/11/22 21:26:51 nia Exp $

LOCAL_CREDS path appears broken on NetBSD...

--- egg/egg-unix-credentials.c.orig	2018-06-25 04:15:03.000000000 +0000
+++ egg/egg-unix-credentials.c
@@ -48,6 +48,10 @@
 #include <ucred.h>
 #endif
 
+#if defined(__NetBSD__)
+#undef LOCAL_CREDS
+#endif
+
 int
 egg_unix_credentials_read (int sock, pid_t *pid, uid_t *uid)
 {
@@ -243,14 +247,14 @@ egg_unix_credentials_executable (pid_t p
 	char *result = NULL;
 
 	/* Try and figure out the path from the pid */
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 	char path[1024];
 	char buffer[64];
 	int count;
 
 #if defined(__linux__)
 	snprintf (buffer, sizeof (buffer), "/proc/%d/exe", (int)pid);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 	snprintf (buffer, sizeof (buffer), "/proc/%d/file", (int)pid);
 #endif
 
