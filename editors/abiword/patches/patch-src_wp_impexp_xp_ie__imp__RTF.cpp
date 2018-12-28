$NetBSD: patch-src_wp_impexp_xp_ie__imp__RTF.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13826, SVN revisions 35377 & 35378: Fix RTF out-of-bounds accesses.

--- src/wp/impexp/xp/ie_imp_RTF.cpp.orig	2014-07-14 04:07:47.000000000 +0000
+++ src/wp/impexp/xp/ie_imp_RTF.cpp
@@ -12068,7 +12068,13 @@ bool IE_Imp_RTF::HandleStyleDefinition(v
 					// must not mix static and dynamically allocated strings in the same
 					// array, otherwise there is no way we can g_free it !!!
 					//attribs[attribsCount++] = g_strdup(static_cast<const char *>(m_styleTable[istyle]));
-					attribs[attribsCount++] = m_styleTable[istyle].c_str();
+					if (istyle >= 0 && static_cast<UT_uint32>(istyle) < m_styleTable.size()) {
+						attribs[attribsCount++] = m_styleTable[istyle].c_str();
+					} else {
+						UT_WARNINGMSG(("RTF: basedon by style index out of bounds: %d. max %lu.\n",
+									   istyle, m_styleTable.size()));
+						attribs[attribsCount++] = NULL;
+					}
 					UT_return_val_if_fail( attribsCount < PT_MAX_ATTRIBUTES * 2,false );
 				}
 				else
@@ -12086,7 +12092,13 @@ bool IE_Imp_RTF::HandleStyleDefinition(v
 					// must not mix static and dynamically allocated strings in the same
 					// array, otherwise there is no way we can g_free it !!!
 					// attribs[attribsCount++] = g_strdup(static_cast<const char *>(m_styleTable[istyle]));
-					attribs[attribsCount++] = m_styleTable[istyle].c_str();
+					if (istyle >= 0 && static_cast<UT_uint32>(istyle) < m_styleTable.size()) {
+						attribs[attribsCount++] = m_styleTable[istyle].c_str();
+					} else {
+						UT_WARNINGMSG(("RTF: followed by style index out of bounds: %d. max %lu.\n",
+									   istyle, m_styleTable.size()));
+						attribs[attribsCount++] = NULL;
+					}
 					UT_return_val_if_fail( attribsCount < PT_MAX_ATTRIBUTES * 2,false );
 				}
 				else
