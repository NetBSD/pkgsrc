$NetBSD: patch-source_darkplaces_vid__glx.c,v 1.1 2020/10/05 18:53:37 nia Exp $

Load an unversioned libGL so this works with NetBSD native X.

--- source/darkplaces/vid_glx.c.orig	2017-04-01 12:26:58.000000000 +0000
+++ source/darkplaces/vid_glx.c
@@ -1353,10 +1353,10 @@ static qboolean VID_InitModeGL(viddef_mo
 #if defined(__APPLE__) && defined(__MACH__)
 	drivername = "/usr/X11R6/lib/libGL.1.dylib";
 #else
-	drivername = "libGL.so.1";
+	drivername = "libGL.so";
 #endif
-// COMMANDLINEOPTION: Linux GLX: -gl_driver <drivername> selects a GL driver library, default is libGL.so.1, useful only for using fxmesa or similar, if you don't know what this is for, you don't need it
-// COMMANDLINEOPTION: BSD GLX: -gl_driver <drivername> selects a GL driver library, default is libGL.so.1, useful only for using fxmesa or similar, if you don't know what this is for, you don't need it
+// COMMANDLINEOPTION: Linux GLX: -gl_driver <drivername> selects a GL driver library, default is libGL.so, useful only for using fxmesa or similar, if you don't know what this is for, you don't need it
+// COMMANDLINEOPTION: BSD GLX: -gl_driver <drivername> selects a GL driver library, default is libGL.so, useful only for using fxmesa or similar, if you don't know what this is for, you don't need it
 // LordHavoc: although this works on MacOSX, it's useless there (as there is only one system libGL)
 	i = COM_CheckParm("-gl_driver");
 	if (i && i < com_argc - 1)
