$NetBSD: patch-librecad_src_lib_engine_rs__system.cpp,v 1.1 2016/09/05 21:13:21 plunky Exp $

Help LibreCAD find the installed files

--- librecad/src/lib/engine/rs_system.cpp.orig	2016-09-04 20:35:17.219964268 +0000
+++ librecad/src/lib/engine/rs_system.cpp
@@ -600,11 +600,8 @@ QStringList RS_System::getDirectoryList(
             }
         }
 
-        // Ubuntu
-        dirList.append("/usr/share/doc/" + appDirName + "/" + subDirectory);
-
-        // Redhat style:
-        dirList.append("/usr/share/" + appDirName + "/" + subDirectory);
+        dirList.append("@PREFIX@/share/" + appDirName + "/" + subDirectory);
+        dirList.append("@PREFIX@/lib/" + appDirName + "/" + subDirectory);
 
         // Others, RVT April 25, 2011 removed, doesn anybody use that still?
         // dirList.append("/usr/X11R6/share/" + appDirName + "/" + subDirectory);
