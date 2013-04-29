$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__noninline.h,v 1.1 2013/04/29 21:34:49 joerg Exp $

--- libstdc++-v3/config/os/bsd/netbsd/ctype_noninline.h.orig	2013-04-28 21:00:32.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_noninline.h
@@ -33,11 +33,17 @@
   
 // Information as gleaned from /usr/include/ctype.h
 
+#ifndef _CTYPE_BL
   extern "C" const u_int8_t _C_ctype_[];
+#endif
 
   const ctype_base::mask*
   ctype<char>::classic_table() throw()
-  { return _C_ctype_ + 1; }
+#ifdef _CTYPE_BL
+  { return _C_ctype_tab_ + 1; }
+#else
+   { return _C_ctype_ + 1; }
+#endif
 
   ctype<char>::ctype(__c_locale, const mask* __table, bool __del, 
 		     size_t __refs) 
@@ -64,14 +70,14 @@
 
   char
   ctype<char>::do_toupper(char __c) const
-  { return ::toupper((int) __c); }
+  { return ::toupper((int)(unsigned char) __c); }
 
   const char*
   ctype<char>::do_toupper(char* __low, const char* __high) const
   {
     while (__low < __high)
       {
-	*__low = ::toupper((int) *__low);
+	*__low = ::toupper((int)(unsigned char) *__low);
 	++__low;
       }
     return __high;
@@ -79,14 +85,14 @@
 
   char
   ctype<char>::do_tolower(char __c) const
-  { return ::tolower((int) __c); }
+  { return ::tolower((int)(unsigned char) __c); }
 
   const char* 
   ctype<char>::do_tolower(char* __low, const char* __high) const
   {
     while (__low < __high)
       {
-	*__low = ::tolower((int) *__low);
+	*__low = ::tolower((int)(unsigned char) *__low);
 	++__low;
       }
     return __high;
