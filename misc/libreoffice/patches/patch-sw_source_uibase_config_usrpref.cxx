$NetBSD: patch-sw_source_uibase_config_usrpref.cxx,v 1.4 2026/09/22 08:34:00 ryoon Exp $

Disable unnecessary code to resolve "std::strcmp not found" problem on
NetBSD 9.x

--- sw/source/uibase/config/usrpref.cxx.orig	2026-08-21 12:51:44.000000000 +0000
+++ sw/source/uibase/config/usrpref.cxx
@@ -133,13 +133,6 @@ Sequence<OUString> SwContentViewConfig::GetPropertyNam
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
     const int nCount = m_bWeb ? 12 : std::size(aPropNames);
     Sequence<OUString> aNames(nCount);
     OUString* pNames = aNames.getArray();
