$NetBSD: patch-include_builtin-ggl_ggl_geometries_adapted_tuple.hpp,v 1.1 2013/02/26 11:15:19 joerg Exp $

--- include/builtin-ggl/ggl/geometries/adapted/tuple.hpp.orig	2011-02-10 12:00:35.000000000 +0000
+++ include/builtin-ggl/ggl/geometries/adapted/tuple.hpp
@@ -39,13 +39,13 @@ struct access<boost::tuple<T, T> >
     template <int I>
     static inline T get(const boost::tuple<T, T>& p)
     {
-        return p.get<I>();
+        return get<I>(p);
     }
 
     template <int I>
     static inline void set(boost::tuple<T, T>& p, const T& value)
     {
-        p.get<I>() = value;
+        get<I>(p) = value;
     }
 };
 
@@ -71,13 +71,13 @@ struct access<boost::tuple<T, T, T> >
     template <int I>
     static inline T get(const boost::tuple<T, T, T>& p)
     {
-        return p.get<I>();
+        return get<I>(p);
     }
 
     template <int I>
     static inline void set(boost::tuple<T, T, T>& p, const T& value)
     {
-        p.get<I>() = value;
+        get<I>(p) = value;
     }
 };
 
