$NetBSD: patch-inc_preferencesdialog.hpp,v 1.1 2013/04/30 22:18:21 joerg Exp $

--- inc/preferencesdialog.hpp.orig	2013-04-30 21:24:56.000000000 +0000
+++ inc/preferencesdialog.hpp
@@ -198,7 +198,7 @@ public:
 	protected:
 		struct LangCompare
 		{
-			bool operator()(GtkSourceLanguage* first, GtkSourceLanguage* second)
+			bool operator()(const GtkSourceLanguage* first, const GtkSourceLanguage* second) const
 			{
 				return first < second;
 			}
