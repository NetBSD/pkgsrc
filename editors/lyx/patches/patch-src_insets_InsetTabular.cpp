$NetBSD: patch-src_insets_InsetTabular.cpp,v 1.1 2012/11/23 12:32:00 joerg Exp $

--- src/insets/InsetTabular.cpp.orig	2012-11-22 22:03:25.000000000 +0000
+++ src/insets/InsetTabular.cpp
@@ -176,6 +176,56 @@ private:
 };
 
 
+string const tostr(LyXAlignment const & num)
+{
+	switch (num) {
+	case LYX_ALIGN_NONE:
+		return "none";
+	case LYX_ALIGN_BLOCK:
+		return "block";
+	case LYX_ALIGN_LEFT:
+		return "left";
+	case LYX_ALIGN_CENTER:
+		return "center";
+	case LYX_ALIGN_RIGHT:
+		return "right";
+	case LYX_ALIGN_LAYOUT:
+		return "layout";
+	case LYX_ALIGN_SPECIAL:
+		return "special";
+	}
+	return string();
+}
+
+
+string const tostr(Tabular::VAlignment const & num)
+{
+	switch (num) {
+	case Tabular::LYX_VALIGN_TOP:
+		return "top";
+	case Tabular::LYX_VALIGN_MIDDLE:
+		return "middle";
+	case Tabular::LYX_VALIGN_BOTTOM:
+		return "bottom";
+	}
+	return string();
+}
+
+
+string const tostr(Tabular::BoxType const & num)
+{
+	switch (num) {
+	case Tabular::BOX_NONE:
+		return "none";
+	case Tabular::BOX_PARBOX:
+		return "parbox";
+	case Tabular::BOX_MINIPAGE:
+		return "minipage";
+	}
+	return string();
+}
+
+
 template <class T>
 string const write_attribute(string const & name, T const & t)
 {
@@ -232,56 +282,6 @@ string const write_attribute(string cons
 }
 
 
-string const tostr(LyXAlignment const & num)
-{
-	switch (num) {
-	case LYX_ALIGN_NONE:
-		return "none";
-	case LYX_ALIGN_BLOCK:
-		return "block";
-	case LYX_ALIGN_LEFT:
-		return "left";
-	case LYX_ALIGN_CENTER:
-		return "center";
-	case LYX_ALIGN_RIGHT:
-		return "right";
-	case LYX_ALIGN_LAYOUT:
-		return "layout";
-	case LYX_ALIGN_SPECIAL:
-		return "special";
-	}
-	return string();
-}
-
-
-string const tostr(Tabular::VAlignment const & num)
-{
-	switch (num) {
-	case Tabular::LYX_VALIGN_TOP:
-		return "top";
-	case Tabular::LYX_VALIGN_MIDDLE:
-		return "middle";
-	case Tabular::LYX_VALIGN_BOTTOM:
-		return "bottom";
-	}
-	return string();
-}
-
-
-string const tostr(Tabular::BoxType const & num)
-{
-	switch (num) {
-	case Tabular::BOX_NONE:
-		return "none";
-	case Tabular::BOX_PARBOX:
-		return "parbox";
-	case Tabular::BOX_MINIPAGE:
-		return "minipage";
-	}
-	return string();
-}
-
-
 // I would have liked a fromstr template a lot better. (Lgb)
 bool string2type(string const str, LyXAlignment & num)
 {
