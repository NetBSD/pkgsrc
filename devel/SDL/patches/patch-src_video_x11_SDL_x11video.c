$NetBSD: patch-src_video_x11_SDL_x11video.c,v 1.1 2012/02/20 14:55:59 jdc Exp $

We need to call XChangeProperty(..., 32, ...) with an object aligned as long.

--- src/video/x11/SDL_x11video.c.orig	2012-02-14 22:26:01.000000000 +0000
+++ src/video/x11/SDL_x11video.c	2012-02-14 22:53:45.000000000 +0000
@@ -418,16 +418,21 @@
     }
 
 	{
-		pid_t pid = getpid();
+		union align_pid {
+			pid_t pid;
+			long dummy;
+		} a_pid;
+		
+		a_pid.pid = getpid();
 		char hostname[256];
 
-		if (pid > 0 && gethostname(hostname, sizeof(hostname)) > -1) {
+		if (a_pid.pid > 0 && gethostname(hostname, sizeof(hostname)) > -1) {
 			Atom _NET_WM_PID = XInternAtom(SDL_Display, "_NET_WM_PID", False);
 			Atom WM_CLIENT_MACHINE = XInternAtom(SDL_Display, "WM_CLIENT_MACHINE", False);
 			
 			hostname[sizeof(hostname)-1] = '\0';
 			XChangeProperty(SDL_Display, WMwindow, _NET_WM_PID, XA_CARDINAL, 32,
-					PropModeReplace, (unsigned char *)&pid, 1);
+					PropModeReplace, (unsigned char *)&(a_pid.pid), 1);
 			XChangeProperty(SDL_Display, WMwindow, WM_CLIENT_MACHINE, XA_STRING, 8,
 					PropModeReplace, (unsigned char *)hostname, SDL_strlen(hostname));
 		}
