$NetBSD: patch-librecad_src_lib_engine_rs__system.cpp,v 1.2 2019/10/26 12:23:01 kamil Exp $

Fix pkgsrc PREFIX.

--- librecad/src/lib/engine/rs_system.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/lib/engine/rs_system.cpp
@@ -573,11 +573,8 @@ QStringList RS_System::getDirectoryList(
             }
         }
 
-        // Ubuntu
-        dirList.append("/usr/share/doc/" + appDirName + "/" + subDirectory);
-
-        // Redhat style:
-        dirList.append("/usr/share/" + appDirName + "/" + subDirectory);
+	dirList.append("@PREFIX@/share/" + appDirName + "/" + subDirectory);
+	dirList.append("@PREFIX@/lib/" + appDirName + "/" + subDirectory);
 
         // Others, RVT April 25, 2011 removed, doesn anybody use that still?
         // dirList.append("/usr/X11R6/share/" + appDirName + "/" + subDirectory);
