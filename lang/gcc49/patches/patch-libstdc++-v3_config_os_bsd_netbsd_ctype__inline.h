$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__inline.h,v 1.1 2014/09/04 18:43:11 jperkin Exp $

Support _CTYPE_BL

--- libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h.orig	2014-01-02 22:30:10.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h
@@ -48,7 +48,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
   is(const char* __low, const char* __high, mask* __vec) const
   {
     while (__low < __high)
-      *__vec++ = _M_table[*__low++];
+      *__vec++ = _M_table[(unsigned char)*__low++];
     return __high;
   }
 
