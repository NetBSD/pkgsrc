$NetBSD: patch-src_xfile-xdg.c,v 1.1 2026/11/16 20:15:31 vins Exp $

Avoid using uninitialized variables.

--- src/xfile-xdg.c.orig	2024-12-26 19:42:32.000000000 +0000
+++ src/xfile-xdg.c
@@ -118,8 +118,6 @@ int process_message(const char *action, 
 	int nargs = 0;
 	char **args;
 	char **arg_ptr;
-	char *exec_str;
-	size_t len;
 	char *browser_bin = find_browser();
 
 	dbus_message_iter_init(msg, &it);
@@ -187,7 +185,7 @@ int process_message(const char *action, 
 	dbus_connection_unref(g_dbus);	
 
 	for(arg_ptr = args; *arg_ptr; arg_ptr++) {
-		int rv;
+		int rv = 0;
 		pid_t pid;
 		struct stat st;
 		char *exec_bin = XFILE_BIN;
@@ -227,12 +225,13 @@ int process_message(const char *action, 
 			_exit(0);
 		}
 		if(rv) stderr_msg("Error executing '%s' (%s).\n",
-			exec_str, strerror(rv));
+			exec_bin, strerror(rv));
 
 		free(*arg_ptr);
 	}
 	
 	free(args);
+	return 0;
 }
 
 int decode_url(char *url)
