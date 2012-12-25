$NetBSD: patch-src_kmplayershared.h,v 1.1 2012/12/25 21:06:31 joerg Exp $

--- src/kmplayershared.h.orig	2012-12-25 18:26:14.000000000 +0000
+++ src/kmplayershared.h
@@ -186,8 +186,8 @@ struct WeakPtr {
     // operator bool () const { return data && !!data->ptr; }
     bool operator == (const WeakPtr<T> & w) const { return data == w.data; }
     bool operator == (const SharedPtr<T> & s) const { return data == s.data; }
-    bool operator == (const T * t) const { return (!t && !data) || (data && data.ptr == t); }
-    bool operator == (T * t) const { return (!t && !data) || (data && data.ptr == t); }
+    bool operator == (const T * t) const { return (!t && !data) || (data && data->ptr == t); }
+    bool operator == (T * t) const { return (!t && !data) || (data && data->ptr == t); }
     bool operator != (const WeakPtr<T> & w) const { return data != w.data; }
     bool operator != (const SharedPtr<T> & s) const { return data != s.data; }
     operator T * () { return data ? data->ptr : 0L; }
