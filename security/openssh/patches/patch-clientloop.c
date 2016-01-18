$NetBSD: patch-clientloop.c,v 1.3 2016/01/18 12:53:26 jperkin Exp $

Fix X11 forwarding under Mac OS X Yosemite. Patch taken from MacPorts.

https://trac.macports.org/browser/trunk/dports/net/openssh/files/launchd.patch?rev=121205

--- clientloop.c.orig	2015-08-21 04:49:03.000000000 +0000
+++ clientloop.c
@@ -315,6 +315,10 @@ client_x11_get_proto(const char *display
 	struct stat st;
 	u_int now, x11_timeout_real;
 
+#if __APPLE__
+	int is_path_to_socket = 0;
+#endif /* __APPLE__ */
+
 	xauthdir = xauthfile = NULL;
 	*_proto = proto;
 	*_data = data;
@@ -330,6 +334,33 @@ client_x11_get_proto(const char *display
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
@@ -421,6 +452,9 @@ client_x11_get_proto(const char *display
 	if (!got_data) {
 		u_int32_t rnd = 0;
 
+#if __APPLE__
+		if (!is_path_to_socket)
+#endif /* __APPLE__ */
 		logit("Warning: No xauth data; "
 		    "using fake authentication data for X11 forwarding.");
 		strlcpy(proto, SSH_X11_PROTO, sizeof proto);
