$NetBSD: patch-sw_source_uibase_config_usrpref.cxx,v 1.3 2025/08/30 06:44:05 ryoon Exp $

Disable unnecessary code to resolve "std::strcmp not found" problem on
NetBSD 9.x

--- sw/source/uibase/config/usrpref.cxx.orig	2025-08-12 11:36:36.000000000 +0000
+++ sw/source/uibase/config/usrpref.cxx
@@ -132,13 +132,6 @@ Sequence<OUString> SwContentViewConfig::
         "Display/ShowBoundaries",               // 33
         "Draw/ClickChangeRotation"              // 34
     };
-#if defined(__GNUC__) && !defined(__clang__)
-    // clang 8.0.0 says strcmp isn't constexpr
-    static_assert(std::strcmp("Update/Link", aPropNames[g_UpdateLinkIndex]) == 0);
-    static_assert(std::strcmp("Display/DefaultAnchor", aPropNames[g_DefaultAnchor]) == 0);
-    static_assert(std::strcmp("Zoom/ZoomType", aPropNames[g_ZoomType]) == 0);
-    static_assert(std::strcmp("Zoom/ZoomValue", aPropNames[g_ZoomValue]) == 0);
-#endif
     const int nCount = m_bWeb ? 12 : SAL_N_ELEMENTS(aPropNames);
     Sequence<OUString> aNames(nCount);
     OUString* pNames = aNames.getArray();
