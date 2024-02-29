$NetBSD: patch-api_filter__api.c,v 1.1 2024/02/29 20:57:37 vins Exp $

Use seteuid(2) on systems where setresuid() is unsupported 

--- api/filter_api.c.orig	2024-02-29 15:13:00.034082660 +0000
+++ api/filter_api.c
@@ -1062,8 +1062,18 @@ filter_api_loop(void)
 	}
 
 	if (setgroups(1, &fi.gid) ||
-	    setresgid(fi.gid, fi.gid, fi.gid) ||
-	    setresuid(fi.uid, fi.uid, fi.uid)) {
+#if HAVE_SETRESGID 
+           setresgid(fi.gid, fi.gid, fi.gid)    
+#else 
+           setegid(fi.gid) 
+#endif 
+           || 
+#if HAVE_SETRESUID 
+           setresuid(fi.uid, fi.uid, fi.uid)) 
+#else 
+           seteuid(fi.uid)) 
+#endif
+	{
 		log_warn("warn: filter-api:%s cannot drop privileges", filter_name);
 		fatalx("filter-api: exiting");
 	}
