$NetBSD: patch-adm_cmake_occt_csf.cmake,v 1.1 2024/02/27 16:33:20 bouyer Exp $

Don't unconditionally set dl in INTERFACE_LINK_LIBRARIES. PR pkg/57938

--- adm/cmake/occt_csf.cmake.orig	2024-02-27 16:31:30.622735481 +0100
+++ adm/cmake/occt_csf.cmake	2024-02-27 16:31:52.950225741 +0100
@@ -142,7 +142,7 @@
       set (CSF_OpenGlLibs "GL EGL")
     endif()
     set (CSF_OpenGlesLibs "EGL GLESv2")
-    set (CSF_dl          "dl")
+    set (CSF_dl          "${CMAKE_DL_LIBS}")
     if (USE_FREETYPE)
       set (CSF_fontconfig "fontconfig")
     endif()
