$NetBSD: patch-slideshow_source_inc_tools.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- slideshow/source/inc/tools.hxx.orig	2013-03-30 17:16:12.000000000 +0000
+++ slideshow/source/inc/tools.hxx
@@ -77,6 +77,16 @@ namespace slideshow
         class ShapeAttributeLayer;
 
         typedef ::boost::shared_ptr< GDIMetaFile > GDIMetaFileSharedPtr;
+        template <typename T>
+        inline ::std::size_t hash_value( T * const& p )
+        {
+            ::std::size_t d = static_cast< ::std::size_t >(
+                reinterpret_cast< ::std::ptrdiff_t >(p) );
+            return d + (d >> 3);
+        }
+
+        template <typename T>
+        inline ::std::size_t hash_value(::com::sun::star::uno::Reference<T> const& x );
 
         // xxx todo: remove with boost::hash when 1.33 is available
         template <typename T>
@@ -86,14 +96,7 @@ namespace slideshow
                 return hash_value(val);
             }
         };
-        template <typename T>
-        inline ::std::size_t hash_value( T * const& p )
-        {
-            ::std::size_t d = static_cast< ::std::size_t >(
-                reinterpret_cast< ::std::ptrdiff_t >(p) );
-            return d + (d >> 3);
-        }
-    
+
         // xxx todo: shift to namespace com::sun::star::uno when
         //           1.33 is available
         template <typename T>
