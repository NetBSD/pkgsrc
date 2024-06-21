$NetBSD: patch-cmake_protobuf.cmake,v 1.1 2024/06/21 10:18:19 jperkin Exp $

Fix path to protobuf includes.

--- cmake/protobuf.cmake.orig	2024-06-21 09:51:22.590836989 +0000
+++ cmake/protobuf.cmake
@@ -66,7 +66,7 @@ elseif(gRPC_PROTOBUF_PROVIDER STREQUAL "
     if(TARGET protobuf::libprotoc)
       set(_gRPC_PROTOBUF_PROTOC_LIBRARIES protobuf::libprotoc)
       # extract the include dir from target's properties
-      get_target_property(_gRPC_PROTOBUF_WELLKNOWN_INCLUDE_DIR protobuf::libprotoc INTERFACE_INCLUDE_DIRECTORIES)
+      set(_gRPC_PROTOBUF_WELLKNOWN_INCLUDE_DIR "@BUILDLINK_PREFIX.protobuf@/include")
     else()
       set(_gRPC_PROTOBUF_PROTOC_LIBRARIES ${PROTOBUF_PROTOC_LIBRARIES})
       set(_gRPC_PROTOBUF_WELLKNOWN_INCLUDE_DIR ${PROTOBUF_INCLUDE_DIRS})
