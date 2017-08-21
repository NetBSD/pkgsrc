$NetBSD: patch-rsh-client.c,v 1.1 2017/08/21 22:57:45 tez Exp $

Fix for CVE-2017-12836 from https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=871810


--- src/rsh-client.c.orig	2017-08-21 22:38:03.283783300 +0000
+++ src/rsh-client.c
@@ -53,9 +53,9 @@ start_rsh_server (cvsroot_t *root, struc
     char *cvs_server = (root->cvs_server != NULL
 			? root->cvs_server : getenv ("CVS_SERVER"));
     int i = 0;
-    /* This needs to fit "rsh", "-b", "-l", "USER", "host",
+    /* This needs to fit "rsh", "-b", "-l", "USER", "--", "host",
        "cmd (w/ args)", and NULL.  We leave some room to grow. */
-    char *rsh_argv[10];
+    char *rsh_argv[16];
 
     if (!cvs_rsh)
 	/* People sometimes suggest or assume that this should default
@@ -96,6 +96,9 @@ start_rsh_server (cvsroot_t *root, struc
 	rsh_argv[i++] = "-l";
 	rsh_argv[i++] = root->username;
     }
+    
+    /* Only non-option arguments from here. (CVE-2017-12836) */
+    rsh_argv[i++] = "--";
 
     rsh_argv[i++] = root->hostname;
     rsh_argv[i++] = cvs_server;
@@ -171,6 +174,9 @@ start_rsh_server (cvsroot_t *root, struc
 	    *p++ = root->username;
 	}
 
+        /* Only non-option arguments from here. (CVE-2017-12836) */
+        *p++ = "--";
+
 	*p++ = root->hostname;
 	*p++ = command;
 	*p++ = NULL;
