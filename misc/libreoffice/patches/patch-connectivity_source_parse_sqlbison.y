$NetBSD: patch-connectivity_source_parse_sqlbison.y,v 1.1 2021/10/01 11:32:50 wiz Exp $

Compatibility with bison-3.8.
https://gerrit.libreoffice.org/c/core/+/122082

--- connectivity/source/parse/sqlbison.y.orig	2021-08-16 19:56:28.000000000 +0000
+++ connectivity/source/parse/sqlbison.y
@@ -74,9 +74,15 @@ inline connectivity::OSQLInternalNode* n
 
 // yyi is the internal number of the rule that is currently being reduced
 // This can be mapped to external rule number via the yyrmap.
+#if defined YYBISON && YYBISON >= 30800
+#define SQL_NEW_RULE 			newNode("", SQLNodeType::Rule, yyr1[yyrule])
+#define SQL_NEW_LISTRULE 		newNode("", SQLNodeType::ListRule, yyr1[yyrule])
+#define SQL_NEW_COMMALISTRULE   newNode("", SQLNodeType::CommaListRule, yyr1[yyrule])
+#else
 #define SQL_NEW_RULE 			newNode("", SQLNodeType::Rule, yyr1[yyn])
 #define SQL_NEW_LISTRULE 		newNode("", SQLNodeType::ListRule, yyr1[yyn])
 #define SQL_NEW_COMMALISTRULE   newNode("", SQLNodeType::CommaListRule, yyr1[yyn])
+#endif
 
 
 extern connectivity::OSQLParser* xxx_pGLOBAL_SQLPARSER;
