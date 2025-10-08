$NetBSD: patch-Source_cmSystemTools.cxx,v 1.1 2025/10/08 17:20:32 nia Exp $

Handle the 39 suffix to the commands.

--- Source/cmSystemTools.cxx.orig	2017-11-10 12:28:58.000000000 +0000
+++ Source/cmSystemTools.cxx
@@ -2033,7 +2033,7 @@ void cmSystemTools::FindCMakeResources(c
     // Look for ..<CMAKE_BIN_DIR> (install tree) and then fall back to
     // ../../../bin (build tree).
     exe_dir = cmSystemTools::GetFilenamePath(exe_dir);
-    if (cmSystemTools::FileExists(exe_dir + CMAKE_BIN_DIR "/cmake")) {
+    if (cmSystemTools::FileExists(exe_dir + CMAKE_BIN_DIR "/cmake39")) {
       exe_dir += CMAKE_BIN_DIR;
     } else {
       exe_dir = cmSystemTools::GetFilenamePath(exe_dir);
@@ -2053,7 +2053,10 @@ void cmSystemTools::FindCMakeResources(c
 #endif
   exe_dir = cmSystemTools::GetActualCaseForPath(exe_dir);
   cmSystemToolsCMakeCommand = exe_dir;
-  cmSystemToolsCMakeCommand += "/cmake";
+  cmSystemToolsCMakeCommand += "/cmake39";
+  if (!cmSystemTools::FileExists(cmSystemToolsCMakeCommand.c_str())) {
+    cmSystemToolsCMakeCommand = exe_dir + "/cmake";
+  }
   cmSystemToolsCMakeCommand += cmSystemTools::GetExecutableExtension();
 #ifndef CMAKE_BUILD_WITH_CMAKE
   // The bootstrap cmake does not provide the other tools,
@@ -2061,10 +2064,10 @@ void cmSystemTools::FindCMakeResources(c
   exe_dir = CMAKE_BOOTSTRAP_BINARY_DIR "/bin";
 #endif
   cmSystemToolsCTestCommand = exe_dir;
-  cmSystemToolsCTestCommand += "/ctest";
+  cmSystemToolsCTestCommand += "/ctest39";
   cmSystemToolsCTestCommand += cmSystemTools::GetExecutableExtension();
   cmSystemToolsCPackCommand = exe_dir;
-  cmSystemToolsCPackCommand += "/cpack";
+  cmSystemToolsCPackCommand += "/cpack39";
   cmSystemToolsCPackCommand += cmSystemTools::GetExecutableExtension();
   cmSystemToolsCMakeGUICommand = exe_dir;
   cmSystemToolsCMakeGUICommand += "/cmake-gui";
@@ -2073,13 +2076,13 @@ void cmSystemTools::FindCMakeResources(c
     cmSystemToolsCMakeGUICommand = "";
   }
   cmSystemToolsCMakeCursesCommand = exe_dir;
-  cmSystemToolsCMakeCursesCommand += "/ccmake";
+  cmSystemToolsCMakeCursesCommand += "/ccmake39";
   cmSystemToolsCMakeCursesCommand += cmSystemTools::GetExecutableExtension();
   if (!cmSystemTools::FileExists(cmSystemToolsCMakeCursesCommand.c_str())) {
     cmSystemToolsCMakeCursesCommand = "";
   }
   cmSystemToolsCMClDepsCommand = exe_dir;
-  cmSystemToolsCMClDepsCommand += "/cmcldeps";
+  cmSystemToolsCMClDepsCommand += "/cmcldeps39";
   cmSystemToolsCMClDepsCommand += cmSystemTools::GetExecutableExtension();
   if (!cmSystemTools::FileExists(cmSystemToolsCMClDepsCommand.c_str())) {
     cmSystemToolsCMClDepsCommand = "";
