$NetBSD: patch-clientloop.c,v 1.1 2015/03/19 20:23:55 tron Exp $

Fix X11 forwarding under Mac OS X Yosemite. Patch taken from MacPorts.

https://trac.macports.org/browser/trunk/dports/net/openssh/files/launchd.patch?rev=121205

--- clientloop.c.orig	2014-02-04 00:20:15.000000000 +0000
+++ clientloop.c	2015-03-19 20:16:04.000000000 +0000
@@ -313,6 +313,10 @@
 	struct stat st;
 	u_int now;
 
+#if __APPLE__
+	int is_path_to_socket = 0;
+#endif /* __APPLE__ */
+
 	xauthdir = xauthfile = NULL;
 	*_proto = proto;
 	*_data = data;
@@ -328,6 +332,33 @@
 			debug("x11_get_proto: DISPLAY not set");
 			return;
 		}
+#if __APPLE__
+		{
+			/*
+			 * If using launchd socket, remove the screen number from the end
+			 * of $DISPLAY. is_path_to_socket is used later in this function
+			 * to determine if an error should be displayed.
+			 */
+			char path[PATH_MAX];
+			struct stat sbuf;
+
+			strlcpy(path, display, sizeof(path));
+			if (0 == stat(path, &sbuf)) {
+				is_path_to_socket = 1;
+			} else {
+				char *dot = strrchr(path, '.');
+				if (dot) {
+					*dot = '\0';
+					/* screen = atoi(dot + 1); */
+					if (0 == stat(path, &sbuf)) {
+						is_path_to_socket = 1;
+						debug("x11_get_proto: $DISPLAY is launchd, removing screennum");
+						setenv("DISPLAY", path, 1);
+					}
+				}
+			}
+		}
+#endif /* __APPLE__ */
 		/*
 		 * Handle FamilyLocal case where $DISPLAY does
 		 * not match an authorization entry.  For this we
@@ -407,6 +438,9 @@
 	if (!got_data) {
 		u_int32_t rnd = 0;
 
+#if __APPLE__
+		if (!is_path_to_socket)
+#endif /* __APPLE__ */
 		logit("Warning: No xauth data; "
 		    "using fake authentication data for X11 forwarding.");
 		strlcpy(proto, SSH_X11_PROTO, sizeof proto);
