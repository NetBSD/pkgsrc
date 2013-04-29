$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__inline.h,v 1.1 2013/04/29 21:34:48 joerg Exp $

--- libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h.orig	2013-04-28 19:47:14.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h
@@ -48,7 +48,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
   is(const char* __low, const char* __high, mask* __vec) const
   {
     while (__low < __high)
-      *__vec++ = _M_table[*__low++];
+      *__vec++ = _M_table[(unsigned char)*__low++];
     return __high;
   }
 
