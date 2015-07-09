$NetBSD: patch-mozilla_js_xpconnect_src_XPCConvert.cpp,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/js/xpconnect/src/XPCConvert.cpp.orig	2015-06-08 17:49:29.000000000 +0000
+++ mozilla/js/xpconnect/src/XPCConvert.cpp
@@ -134,7 +134,7 @@ XPCConvert::NativeData2JS(MutableHandleV
         d.setNumber(*static_cast<const float*>(s));
         return true;
     case nsXPTType::T_DOUBLE:
-        d.setNumber(*static_cast<const double*>(s));
+        d.setNumber(CanonicalizeNaN(*static_cast<const double*>(s)));
         return true;
     case nsXPTType::T_BOOL  :
         d.setBoolean(*static_cast<const bool*>(s));
