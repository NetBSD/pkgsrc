$NetBSD: patch-Source_d__iwad.c,v 1.1 2020/05/11 10:46:12 micha Exp $

Add pkgsrc ${PREFIX}/share/doom to WAD file search path.

--- Source/d_iwad.c.orig	2020-04-14 06:39:44.000000000 +0000
+++ Source/d_iwad.c
@@ -442,6 +442,9 @@ static void AddXdgDirs(void)
         env = "/usr/local/share:/usr/share";
     }
 
+    // Add pkgsrc location for WADs
+    AddIWADPath(PKGSRC_PREFIX, PKGSRC_DOOMWADDIR);
+
     // The "standard" location for IWADs on Unix that is supported by most
     // source ports is /usr/share/games/doom - we support this through the
     // XDG_DATA_DIRS mechanism, through which it can be overridden.
