$NetBSD: patch-api_scheduler__api.c,v 1.1 2024/02/29 20:57:37 vins Exp $

Use seteuid(2) on systems where setresuid() is unsupported

--- api/scheduler_api.c.orig	2020-04-06 18:36:29.000000000 +0000
+++ api/scheduler_api.c
@@ -440,8 +440,18 @@ scheduler_api_dispatch(void)
 
 	if (pw &&
 	   (setgroups(1, &pw->pw_gid) ||
-	    setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) ||
-	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid))) {
+#if HAVE_SETRESGID 
+           setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid)    
+#else 
+           setegid(pw->pw_gid) 
+#endif 
+           || 
+#if HAVE_SETRESUID 
+           setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid))) 
+#else 
+           seteuid(pw->pw_gid))) 
+#endif
+	{
 		log_warn("queue-api: cannot drop privileges");
 		fatalx("queue-api: exiting");
 	}
