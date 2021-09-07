$NetBSD: patch-sw_source_uibase_config_usrpref.cxx,v 1.1 2021/09/07 09:49:05 nia Exp $

Disable unnecessary code to resolve "std::strcmp not found" problem on
NetBSD 9.x

--- sw/source/uibase/config/usrpref.cxx.orig	2021-09-07 09:44:19.193281013 +0000
+++ sw/source/uibase/config/usrpref.cxx
@@ -109,11 +109,6 @@ Sequence<OUString> SwContentViewConfig::
         "Display/ShowChangesInMargin",          // 24
         "Display/DefaultAnchor"                 // 25
     };
-#if defined(__GNUC__) && !defined(__clang__)
-    // clang 8.0.0 says strcmp isn't constexpr
-    static_assert(std::strcmp("Update/Link", aPropNames[g_UpdateLinkIndex]) == 0);
-    static_assert(std::strcmp("Display/DefaultAnchor", aPropNames[g_DefaultAnchor]) == 0);
-#endif
     const int nCount = m_bWeb ? 12 : SAL_N_ELEMENTS(aPropNames);
     Sequence<OUString> aNames(nCount);
     OUString* pNames = aNames.getArray();
