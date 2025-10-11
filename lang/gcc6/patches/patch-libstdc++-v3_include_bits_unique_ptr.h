$NetBSD: patch-libstdc++-v3_include_bits_unique_ptr.h,v 1.1 2025/10/11 16:14:19 js Exp $

_UP is already defined on QNX, so use __UP.

--- libstdc++-v3/include/bits/unique_ptr.h.orig	2018-10-25 16:41:54.000000000 +0000
+++ libstdc++-v3/include/bits/unique_ptr.h
@@ -767,8 +767,8 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
       size_t
       operator()(const unique_ptr<_Tp, _Dp>& __u) const noexcept
       {
-	typedef unique_ptr<_Tp, _Dp> _UP;
-	return std::hash<typename _UP::pointer>()(__u.get());
+	typedef unique_ptr<_Tp, _Dp> __UP;
+	return std::hash<typename __UP::pointer>()(__u.get());
       }
     };
 
