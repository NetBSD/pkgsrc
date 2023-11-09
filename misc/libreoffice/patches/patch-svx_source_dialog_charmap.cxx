$NetBSD: patch-svx_source_dialog_charmap.cxx,v 1.3 2023/11/09 07:37:12 wiz Exp $

Fix build with icu 74.1.

--- svx/source/dialog/charmap.cxx.orig	2023-09-22 19:07:01.000000000 +0000
+++ svx/source/dialog/charmap.cxx
@@ -1928,6 +1928,11 @@ void SubsetMap::InitList()
                     aAllSubsets.emplace_back( 0x1E4D0, 0x1E4FF, SvxResId(RID_SUBSETSTR_NAG_MUNDARI) );
                     break;
 #endif
+#if (U_ICU_VERSION_MAJOR_NUM >= 74)
+                case UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_I:
+                    aAllSubsets.emplace_back( 0x2EBF0, 0x2EE5F, SvxResId(RID_SUBSETSTR_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_I) );
+                    break;
+#endif
             }
 
 #if OSL_DEBUG_LEVEL > 0 && !defined NDEBUG
