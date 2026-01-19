$NetBSD: patch-CMake_Modules_FindUsb.cmake,v 1.1 2026/01/19 13:40:53 mef Exp $

From FreeBSD ports 2.5.4

--- wsjtx/CMake/Modules/FindUsb.cmake.orig	2021-11-03 19:53:01.000000000 -0400
+++ CMake/Modules/FindUsb.cmake	2021-12-31 07:48:03.412537000 -0500
@@ -13,25 +13,35 @@
 #  Usb::Usb	- The libusb library
 #
 
+if ( CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" )
+   message ( Status "FreeBSD libusb is built in")
+   set (Usb_FOUND True)
+   set(Usb_LIBRARY "usb")
+   set(Usb_INCLUDE_DIR "/usr/include")
+   set(Usb_LIBRARIES "")
+   add_library (Usb "usb")
+else()
 include (LibFindMacros)
 
-if (WIN32)
-  # Use path suffixes on MS Windows as we probably shouldn't
-  # trust the PATH envvar. PATH will still be searched to find the
-  # library as last resort.
-  if (CMAKE_SIZEOF_VOID_P MATCHES "8")
-    set (_library_options PATH_SUFFIXES MinGW64/dll MinGW64/static)
-  else ()
-    set (_library_options PATH_SUFFIXES MinGW32/dll MinGW32/static)
-  endif ()
-endif ()
-libfind_pkg_detect (Usb usb-1.0
-  FIND_PATH libusb.h PATH_SUFFIXES libusb-1.0
-  FIND_LIBRARY usb-1.0 ${_library_options}
-  )
+   if (WIN32)
+      # Use path suffixes on MS Windows as we probably shouldn't
+      # trust the PATH envvar. PATH will still be searched to find the
+      # library as last resort.
+      if (CMAKE_SIZEOF_VOID_P MATCHES "8")
+       set (_library_options PATH_SUFFIXES MinGW64/dll MinGW64/static)
+      else ()
+        set (_library_options PATH_SUFFIXES MinGW32/dll MinGW32/static)
+      endif ()
+   endif ()
 
-libfind_process (Usb)
+   libfind_pkg_detect (Usb usb-1.0
+     FIND_PATH libusb.h PATH_SUFFIXES libusb-1.0
+     FIND_LIBRARY usb-1.0 ${_library_options}
+     )
 
+   libfind_process (Usb)
+endif()
+
 if (Usb_FOUND AND NOT TARGET Usb::Usb)
   add_library (Usb::Usb UNKNOWN IMPORTED)
   set_target_properties (Usb::Usb PROPERTIES
@@ -40,10 +50,12 @@
     INTERFACE_INCLUDE_DIRECTORIES "${Usb_INCLUDE_DIRS}"
     INTERFACE_LINK_LIBRARIES "${Usb_LIBRARIES}"
     )
-endif ()
+endif()
 
+if ( NOT CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" )
 mark_as_advanced (
   Usb_INCLUDE_DIR
   Usb_LIBRARY
   Usb_LIBRARIES
   )
+endif()
