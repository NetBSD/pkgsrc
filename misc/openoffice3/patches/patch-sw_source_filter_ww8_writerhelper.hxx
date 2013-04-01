$NetBSD: patch-sw_source_filter_ww8_writerhelper.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sw/source/filter/ww8/writerhelper.hxx.orig	2013-03-30 19:42:21.000000000 +0000
+++ sw/source/filter/ww8/writerhelper.hxx
@@ -248,8 +248,10 @@ namespace sw
         template<class T> const T & item_cast(const SfxPoolItem &rItem)
             throw(std::bad_cast)
         {
+#if !defined(__GNUC__) || defined(__EXCEPTIONS__)
             if (!rItem.IsA(STATICTYPE(T)))
                 throw std::bad_cast();
+#endif
             return static_cast<const T &>(rItem);
         }
 
