$NetBSD: patch-svx_source_dialog_charmap.cxx,v 1.1 2016/12/06 15:21:00 ryoon Exp $

--- svx/source/dialog/charmap.cxx.orig	2016-10-28 14:50:26.000000000 +0000
+++ svx/source/dialog/charmap.cxx
@@ -1587,6 +1587,41 @@ void SubsetMap::InitList()
                     aAllSubsets.push_back( Subset( 0x1D800, 0x1DAAF, RID_SUBSETSTR_SUTTON_SIGNWRITING ) );
                     break;
 #endif
+#if (U_ICU_VERSION_MAJOR_NUM >= 58)
+                case UBLOCK_ADLAM:
+                    aAllSubsets.push_back( Subset( 0x1E900, 0x1E95F, RID_SUBSETSTR_ADLAM ) );
+                    break;
+                case UBLOCK_BHAIKSUKI:
+                    aAllSubsets.push_back( Subset( 0x11C00, 0x11C6F, RID_SUBSETSTR_BHAIKSUKI ) );
+                    break;
+                case UBLOCK_CYRILLIC_EXTENDED_C:
+                    aAllSubsets.push_back( Subset( 0x1C80, 0x1C8F, RID_SUBSETSTR_CYRILLIC_EXTENDED_C ) );
+                    break;
+                case UBLOCK_GLAGOLITIC_SUPPLEMENT:
+                    aAllSubsets.push_back( Subset( 0x1E000, 0x1E02F, RID_SUBSETSTR_GLAGOLITIC_SUPPLEMENT ) );
+                    break;
+                case UBLOCK_IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION:
+                    aAllSubsets.push_back( Subset( 0x16FE0, 0x16FFF, RID_SUBSETSTR_IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION ) );
+                    break;
+                case UBLOCK_MARCHEN:
+                    aAllSubsets.push_back( Subset( 0x11C70, 0x11CBF, RID_SUBSETSTR_MARCHEN ) );
+                    break;
+                case UBLOCK_MONGOLIAN_SUPPLEMENT:
+                    aAllSubsets.push_back( Subset( 0x11660, 0x1167F, RID_SUBSETSTR_MONGOLIAN_SUPPLEMENT ) );
+                    break;
+                case UBLOCK_NEWA:
+                    aAllSubsets.push_back( Subset( 0x11400, 0x1147F, RID_SUBSETSTR_NEWA ) );
+                    break;
+                case UBLOCK_OSAGE:
+                    aAllSubsets.push_back( Subset( 0x104B0, 0x104FF, RID_SUBSETSTR_OSAGE ) );
+                    break;
+                case UBLOCK_TANGUT:
+                    aAllSubsets.push_back( Subset( 0x17000, 0x187FF, RID_SUBSETSTR_TANGUT ) );
+                    break;
+                case UBLOCK_TANGUT_COMPONENTS:
+                    aAllSubsets.push_back( Subset( 0x18800, 0x18AFF, RID_SUBSETSTR_TANGUT_COMPONENTS ) );
+                    break;
+#endif
 
             }
 
