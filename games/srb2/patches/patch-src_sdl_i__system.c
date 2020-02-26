$NetBSD: patch-src_sdl_i__system.c,v 1.2 2020/02/26 17:55:51 nia Exp $

Hunk 1: Support searching PREFIX for data files.

Hunk 2: Support NetBSD's spelling of statfs.

--- src/sdl/i_system.c.orig	2020-02-22 22:27:19.000000000 +0000
+++ src/sdl/i_system.c
@@ -139,7 +139,7 @@ typedef LPVOID (WINAPI *p_MapViewOfFile)
 
 // Locations for searching the srb2.pk3
 #if defined (__unix__) || defined(__APPLE__) || defined (UNIXCOMMON)
-#define DEFAULTWADLOCATION1 "/usr/local/share/games/SRB2"
+#define DEFAULTWADLOCATION1 "@PREFIX@/share/srb2"
 #define DEFAULTWADLOCATION2 "/usr/local/games/SRB2"
 #define DEFAULTWADLOCATION3 "/usr/share/games/SRB2"
 #define DEFAULTWADLOCATION4 "/usr/games/SRB2"
@@ -2565,8 +2565,13 @@ void I_GetDiskFreeSpace(INT64 *freespace
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
