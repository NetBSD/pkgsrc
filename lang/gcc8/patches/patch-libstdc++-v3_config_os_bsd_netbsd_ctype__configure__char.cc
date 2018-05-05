$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__configure__char.cc,v 1.1 2018/05/05 04:08:36 maya Exp $

Sync with netbsd ctype_configure_char.cc

--- libstdc++-v3/config/os/bsd/netbsd/ctype_configure_char.cc.orig	2018-01-03 10:03:58.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_configure_char.cc
@@ -38,29 +38,27 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 
 // Information as gleaned from /usr/include/ctype.h
 
-  extern "C" const u_int8_t _C_ctype_[];
-
   const ctype_base::mask*
   ctype<char>::classic_table() throw()
-  { return _C_ctype_ + 1; }
+  { return _C_ctype_tab_ + 1; }
 
-  ctype<char>::ctype(__c_locale, const mask* __table, bool __del,
-		     size_t __refs)
-  : facet(__refs), _M_del(__table != 0 && __del),
-  _M_toupper(NULL), _M_tolower(NULL),
+  ctype<char>::ctype(__c_locale, const mask* __table, bool __del, 
+		     size_t __refs) 
+  : facet(__refs), _M_del(__table != 0 && __del), 
+  _M_toupper(NULL), _M_tolower(NULL), 
   _M_table(__table ? __table : classic_table())
-  {
+  { 
     memset(_M_widen, 0, sizeof(_M_widen));
     _M_widen_ok = 0;
     memset(_M_narrow, 0, sizeof(_M_narrow));
     _M_narrow_ok = 0;
   }
 
-  ctype<char>::ctype(const mask* __table, bool __del, size_t __refs)
-  : facet(__refs), _M_del(__table != 0 && __del),
-  _M_toupper(NULL), _M_tolower(NULL),
+  ctype<char>::ctype(const mask* __table, bool __del, size_t __refs) 
+  : facet(__refs), _M_del(__table != 0 && __del), 
+  _M_toupper(NULL), _M_tolower(NULL), 
   _M_table(__table ? __table : classic_table())
-  {
+  { 
     memset(_M_widen, 0, sizeof(_M_widen));
     _M_widen_ok = 0;
     memset(_M_narrow, 0, sizeof(_M_narrow));
@@ -69,14 +67,14 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 
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
@@ -84,14 +82,14 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 
   char
   ctype<char>::do_tolower(char __c) const
-  { return ::tolower((int) __c); }
+  { return ::tolower((int)(unsigned char) __c); }
 
-  const char*
+  const char* 
   ctype<char>::do_tolower(char* __low, const char* __high) const
   {
     while (__low < __high)
       {
-	*__low = ::tolower((int) *__low);
+	*__low = ::tolower((int)(unsigned char) *__low);
 	++__low;
       }
     return __high;
