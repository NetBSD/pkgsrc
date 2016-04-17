$NetBSD: patch-mozilla_js_xpconnect_src_XPCConvert.cpp,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/js/xpconnect/src/XPCConvert.cpp.orig	2016-04-07 21:33:28.000000000 +0000
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
