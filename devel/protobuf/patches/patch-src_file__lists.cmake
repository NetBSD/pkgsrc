$NetBSD: patch-src_file__lists.cmake,v 1.1 2026/04/16 09:56:13 adam Exp $

Install additional headers (required by py-grpctio-tools).

--- src/file_lists.cmake.orig	2026-04-16 08:24:30.749155340 +0000
+++ src/file_lists.cmake
@@ -348,6 +348,8 @@ set(libprotoc_public_hdrs
   ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/objectivec/names.h
   ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/objectivec/nsobject_methods.h
   ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/php/names.h
+  ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/python/generator.h
+  ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/python/pyi_generator.h
   ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/plugin.h
   ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/plugin.pb.h
   ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/retention.h
