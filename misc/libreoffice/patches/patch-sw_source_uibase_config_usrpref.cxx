$NetBSD: patch-sw_source_uibase_config_usrpref.cxx,v 1.2 2025/02/05 03:50:02 ryoon Exp $

Disable unnecessary code to resolve "std::strcmp not found" problem on
NetBSD 9.x

--- sw/source/uibase/config/usrpref.cxx.orig	2025-01-30 14:19:43.944837340 +0000
+++ sw/source/uibase/config/usrpref.cxx
@@ -130,13 +130,6 @@ Sequence<OUString> SwContentViewConfig::
         "Display/TableBoundaries",              // 32
         "Display/ShowBoundaries"                // 33
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
