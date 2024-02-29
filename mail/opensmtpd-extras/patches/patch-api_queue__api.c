$NetBSD: patch-api_queue__api.c,v 1.1 2024/02/29 20:57:37 vins Exp $

Use seteuid(2) on systems where setresuid() is unsupported

--- api/queue_api.c.orig	2020-04-06 18:36:29.000000000 +0000
+++ api/queue_api.c
@@ -421,8 +421,18 @@ queue_api_dispatch(void)
 
 	if (pw &&
 	   (setgroups(1, &pw->pw_gid) ||
-	    setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) ||
-	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid))) {
+#if HAVE_SETRESGID
+	    setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid)
+#else
+	    setegid(pw->pw_gid)
+#endif
+	    ||
+#if HAVE_SETRESUID
+	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid)))
+#else
+	    seteuid(pw->pw_gid)))
+#endif
+	{
 		log_warn("queue-api: cannot drop privileges");
 		fatalx("queue-api: exiting");
 	}
