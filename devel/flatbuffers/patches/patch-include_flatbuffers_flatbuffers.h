$NetBSD: patch-include_flatbuffers_flatbuffers.h,v 1.1 2020/05/01 00:02:27 joerg Exp $

Implicit copy constructor is deprecated when a user-defined assignment
operator is defined.

--- include/flatbuffers/flatbuffers.h.orig	2020-04-29 23:22:29.846831379 +0000
+++ include/flatbuffers/flatbuffers.h
@@ -1371,6 +1371,8 @@ class FlatBufferBuilder {
 
   /// @cond FLATBUFFERS_INTERNAL
   template<typename T> struct StructKeyComparator {
+    StructKeyComparator () = default;
+    StructKeyComparator (const StructKeyComparator &) = default;
     bool operator()(const T &a, const T &b) const {
       return a.KeyCompareLessThan(&b);
     }
@@ -1442,6 +1444,7 @@ class FlatBufferBuilder {
   /// @cond FLATBUFFERS_INTERNAL
   template<typename T> struct TableKeyComparator {
     TableKeyComparator(vector_downward &buf) : buf_(buf) {}
+    TableKeyComparator (const TableKeyComparator &) = default;
     bool operator()(const Offset<T> &a, const Offset<T> &b) const {
       auto table_a = reinterpret_cast<T *>(buf_.data_at(a.o));
       auto table_b = reinterpret_cast<T *>(buf_.data_at(b.o));
