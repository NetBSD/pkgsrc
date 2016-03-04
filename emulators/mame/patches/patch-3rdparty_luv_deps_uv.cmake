$NetBSD: patch-3rdparty_luv_deps_uv.cmake,v 1.1 2016/03/04 12:47:13 wiz Exp $

--- 3rdparty/luv/deps/uv.cmake.orig	2016-02-24 07:02:17.000000000 +0000
+++ 3rdparty/luv/deps/uv.cmake
@@ -138,6 +138,14 @@ if("${CMAKE_SYSTEM_NAME}" MATCHES "FreeB
   )
 endif()
 
+## NetBSD
+if("${CMAKE_SYSTEM_NAME}" MATCHES "NetBSD")
+  set(SOURCES ${SOURCES}
+    ${LIBUVDIR}/src/unix/kqueue.c
+    ${LIBUVDIR}/src/unix/freebsd.c
+  )
+endif()
+
 ## Linux
 if("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
   add_definitions(
@@ -187,6 +195,13 @@ if("${CMAKE_SYSTEM_NAME}" MATCHES "FreeB
   )
 endif()
 
+if("${CMAKE_SYSTEM_NAME}" MATCHES "NetBSD")
+  target_link_libraries(uv
+    pthread
+    kvm
+  )
+endif()
+
 if("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
   target_link_libraries(uv
     pthread
