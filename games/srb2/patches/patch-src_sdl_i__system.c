$NetBSD: patch-src_sdl_i__system.c,v 1.1 2019/10/01 12:30:32 nia Exp $

Hunk 1: Support searching PREFIX for data files.

Hunk 2: Support NetBSD's spelling of statfs.

--- src/sdl/i_system.c.orig	2019-08-17 18:07:04.000000000 +0000
+++ src/sdl/i_system.c
@@ -133,7 +133,7 @@ typedef LPVOID (WINAPI *p_MapViewOfFile)
 
 // Locations for searching the srb2.srb
 #if defined (__unix__) || defined(__APPLE__) || defined (UNIXCOMMON)
-#define DEFAULTWADLOCATION1 "/usr/local/share/games/SRB2"
+#define DEFAULTWADLOCATION1 "@PREFIX@/share/srb2"
 #define DEFAULTWADLOCATION2 "/usr/local/games/SRB2"
 #define DEFAULTWADLOCATION3 "/usr/share/games/SRB2"
 #define DEFAULTWADLOCATION4 "/usr/games/SRB2"
@@ -2375,8 +2375,13 @@ void I_GetDiskFreeSpace(INT64 *freespace
 	*freespace = INT32_MAX;
 	return;
 #else // Both Linux and BSD have this, apparently.
+#ifndef __NetBSD__
 	struct statfs stfs;
 	if (statfs(".", &stfs) == -1)
+#else
+	struct statvfs stfs;
+	if (statvfs(".", &stfs) == -1)
+#endif
 	{
 		*freespace = INT32_MAX;
 		return;
