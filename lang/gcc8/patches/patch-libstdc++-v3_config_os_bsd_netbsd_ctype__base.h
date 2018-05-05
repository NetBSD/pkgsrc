$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__base.h,v 1.1 2018/05/05 04:08:36 maya Exp $

Sync with netbsd ctype_base.h

--- libstdc++-v3/config/os/bsd/netbsd/ctype_base.h.orig	2018-01-03 10:03:58.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_base.h
@@ -38,14 +38,16 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
   /// @brief  Base class for ctype.
   struct ctype_base
   {
-    // Non-standard typedefs.
-    typedef const unsigned char*	__to_type;
 
     // NB: Offsets into ctype<char>::_M_table force a particular size
     // on the mask type. Because of this, we don't use an enum.
-    typedef unsigned char      	mask;
 
 #ifndef _CTYPE_U
+    // Non-standard typedefs.
+    typedef const unsigned char*	__to_type;
+
+    typedef unsigned char      	mask;
+
     static const mask upper    	= _U;
     static const mask lower 	= _L;
     static const mask alpha 	= _U | _L;
@@ -58,17 +60,21 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
     static const mask punct 	= _P;
     static const mask alnum 	= _U | _L | _N;
 #else
+    typedef const unsigned short*	__to_type;
+
+    typedef unsigned short     	mask;
+
     static const mask upper    	= _CTYPE_U;
     static const mask lower 	= _CTYPE_L;
-    static const mask alpha 	= _CTYPE_U | _CTYPE_L;
-    static const mask digit 	= _CTYPE_N;
-    static const mask xdigit 	= _CTYPE_N | _CTYPE_X;
+    static const mask alpha 	= _CTYPE_A;
+    static const mask digit 	= _CTYPE_D;
+    static const mask xdigit 	= _CTYPE_X;
     static const mask space 	= _CTYPE_S;
-    static const mask print 	= _CTYPE_P | _CTYPE_U | _CTYPE_L | _CTYPE_N | _CTYPE_B;
-    static const mask graph 	= _CTYPE_P | _CTYPE_U | _CTYPE_L | _CTYPE_N;
+    static const mask print 	= _CTYPE_R;
+    static const mask graph 	= _CTYPE_G;
     static const mask cntrl 	= _CTYPE_C;
     static const mask punct 	= _CTYPE_P;
-    static const mask alnum 	= _CTYPE_U | _CTYPE_L | _CTYPE_N;
+    static const mask alnum 	= _CTYPE_A | _CTYPE_D;
 #endif
 #if __cplusplus >= 201103L
     static const mask blank 	= space;
