$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__inline.h,v 1.1 2014/09/10 12:18:54 joerg Exp $

--- libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h.orig	2002-06-24 05:50:58.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_inline.h
@@ -44,7 +44,7 @@
   is(const char* __low, const char* __high, mask* __vec) const
   {
     while (__low < __high)
-      *__vec++ = _M_table[*__low++];
+      *__vec++ = _M_table[(unsigned char)*__low++];
     return __high;
   }
 
