$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__configure__char.cc,v 1.1 2014/09/04 18:43:11 jperkin Exp $

Support _CTYPE_BL

--- libstdc++-v3/config/os/bsd/netbsd/ctype_configure_char.cc.orig	2014-01-02 22:30:10.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_configure_char.cc
@@ -38,11 +38,17 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 
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
@@ -69,14 +75,14 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 
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
@@ -84,14 +90,14 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 
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
