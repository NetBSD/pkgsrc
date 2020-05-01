$NetBSD: patch-include_flatbuffers_reflection.h,v 1.1 2020/05/01 00:02:27 joerg Exp $

Implicit copy constructor is deprecated when a user-defined assignment
operator is defined.

--- include/flatbuffers/reflection.h.orig	2020-04-29 23:28:21.560920814 +0000
+++ include/flatbuffers/reflection.h
@@ -363,6 +363,7 @@ template<typename T, typename U> class p
         reinterpret_cast<uint8_t *>(flatbuffers::vector_data(vec_)) + offset_);
   }
   T *operator->() const { return operator*(); }
+  pointer_inside_vector (const pointer_inside_vector &) = default;
   void operator=(const pointer_inside_vector &piv);
 
  private:
