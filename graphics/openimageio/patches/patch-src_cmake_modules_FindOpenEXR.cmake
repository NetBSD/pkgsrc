$NetBSD: patch-src_cmake_modules_FindOpenEXR.cmake,v 1.1 2019/12/29 10:15:04 markd Exp $

pkgsrc doesn't install OpenEXR with version embedded in name, so don't
look for them as might pick up some non pkgsrc version.

--- src/cmake/modules/FindOpenEXR.cmake.orig	2018-10-01 21:26:14.000000000 +0000
+++ src/cmake/modules/FindOpenEXR.cmake
@@ -128,11 +128,11 @@ set (_openexr_components IlmThread IlmIm
 foreach (COMPONENT ${_openexr_components})
     string (TOUPPER ${COMPONENT} UPPERCOMPONENT)
     # First try with the version embedded
-    set (FULL_COMPONENT_NAME ${OPENEXR_CUSTOM_LIB_PREFIX}${COMPONENT}-${OPENEXR_VERSION_MAJOR}_${OPENEXR_VERSION_MINOR}${OPENEXR_CUSTOM_LIB_SUFFIX})
-    find_library (OPENEXR_${UPPERCOMPONENT}_LIBRARY ${FULL_COMPONENT_NAME}
-                  PATHS ${GENERIC_LIBRARY_PATHS} NO_DEFAULT_PATH)
-    # Again, with no directory restrictions
-    find_library (OPENEXR_${UPPERCOMPONENT}_LIBRARY ${FULL_COMPONENT_NAME})
+#    set (FULL_COMPONENT_NAME ${OPENEXR_CUSTOM_LIB_PREFIX}${COMPONENT}-${OPENEXR_VERSION_MAJOR}_${OPENEXR_VERSION_MINOR}${OPENEXR_CUSTOM_LIB_SUFFIX})
+#    find_library (OPENEXR_${UPPERCOMPONENT}_LIBRARY ${FULL_COMPONENT_NAME}
+#                  PATHS ${GENERIC_LIBRARY_PATHS} NO_DEFAULT_PATH)
+#    # Again, with no directory restrictions
+#    find_library (OPENEXR_${UPPERCOMPONENT}_LIBRARY ${FULL_COMPONENT_NAME})
     # Try again without the version
     set (FULL_COMPONENT_NAME ${OPENEXR_CUSTOM_LIB_PREFIX}${COMPONENT}${OPENEXR_CUSTOM_LIB_SUFFIX})
     find_library (OPENEXR_${UPPERCOMPONENT}_LIBRARY ${FULL_COMPONENT_NAME}
