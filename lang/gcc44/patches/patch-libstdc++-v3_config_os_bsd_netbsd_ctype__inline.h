$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__inline.h,v 1.1 2013/04/29 21:34:49 joerg Exp $

--- libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h.orig	2009-04-09 23:23:07.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h
@@ -46,7 +46,7 @@ _GLIBCXX_BEGIN_NAMESPACE(std)
   is(const char* __low, const char* __high, mask* __vec) const
   {
     while (__low < __high)
-      *__vec++ = _M_table[*__low++];
+      *__vec++ = _M_table[(unsigned char)*__low++];
     return __high;
   }
 
