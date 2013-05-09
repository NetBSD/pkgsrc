$NetBSD: patch-src_insets_InsetTabular.cpp,v 1.2 2013/05/09 13:56:58 joerg Exp $

--- src/insets/InsetTabular.cpp.orig	2011-01-05 14:02:35.000000000 +0000
+++ src/insets/InsetTabular.cpp
@@ -68,7 +68,6 @@
 using namespace std;
 using namespace lyx::support;
 
-using boost::shared_ptr;
 using boost::dynamic_pointer_cast;
 
 
@@ -176,6 +175,56 @@ private:
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
@@ -232,56 +281,6 @@ string const write_attribute(string cons
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
@@ -2203,7 +2202,7 @@ int Tabular::TeXRow(odocstream & os, row
 		       OutputParams const & runparams) const
 {
 	idx_type cell = cellIndex(i, 0);
-	shared_ptr<InsetTableCell> inset = cellInset(cell);
+	boost::shared_ptr<InsetTableCell> inset = cellInset(cell);
 	Paragraph const & par = inset->paragraphs().front();
 	string const lang = par.getParLanguage(buffer().params())->lang();
 
@@ -2233,7 +2232,7 @@ int Tabular::TeXRow(odocstream & os, row
 		if (isPartOfMultiColumn(i, j))
 			continue;
 		ret += TeXCellPreamble(os, cell, ismulticol);
-		shared_ptr<InsetTableCell> inset = cellInset(cell);
+		boost::shared_ptr<InsetTableCell> inset = cellInset(cell);
 
 		Paragraph const & par = inset->paragraphs().front();
 		bool rtl = par.isRTL(buffer().params())
@@ -2769,13 +2768,13 @@ void Tabular::plaintext(odocstream & os,
 }
 
 
-shared_ptr<InsetTableCell> Tabular::cellInset(idx_type cell) const
+boost::shared_ptr<InsetTableCell> Tabular::cellInset(idx_type cell) const
 {
 	return cell_info[cellRow(cell)][cellColumn(cell)].inset;
 }
 
 
-shared_ptr<InsetTableCell> Tabular::cellInset(row_type row,
+boost::shared_ptr<InsetTableCell> Tabular::cellInset(row_type row,
 					       col_type column) const
 {
 	return cell_info[row][column].inset;
@@ -2783,7 +2782,7 @@ shared_ptr<InsetTableCell> Tabular::cell
 
 
 void Tabular::setCellInset(row_type row, col_type column,
-			      shared_ptr<InsetTableCell> ins) const
+			      boost::shared_ptr<InsetTableCell> ins) const
 {
 	CellData & cd = cell_info[row][column];
 	cd.inset = ins;
@@ -4154,13 +4153,13 @@ void InsetTabular::validate(LaTeXFeature
 }
 
 
-shared_ptr<InsetTableCell const> InsetTabular::cell(idx_type idx) const
+boost::shared_ptr<InsetTableCell const> InsetTabular::cell(idx_type idx) const
 {
 	return tabular.cellInset(idx);
 }
 
 
-shared_ptr<InsetTableCell> InsetTabular::cell(idx_type idx)
+boost::shared_ptr<InsetTableCell> InsetTabular::cell(idx_type idx)
 {
 	return tabular.cellInset(idx);
 }
@@ -4960,7 +4959,7 @@ bool InsetTabular::pasteClipboard(Cursor
 				--c1;
 				continue;
 			}
-			shared_ptr<InsetTableCell> inset(
+			boost::shared_ptr<InsetTableCell> inset(
 				new InsetTableCell(*paste_tabular->cellInset(r1, c1)));
 			tabular.setCellInset(r2, c2, inset);
 			// FIXME: change tracking (MG)
@@ -4983,7 +4982,7 @@ void InsetTabular::cutSelection(Cursor &
 	getSelection(cur, rs, re, cs, ce);
 	for (row_type i = rs; i <= re; ++i) {
 		for (col_type j = cs; j <= ce; ++j) {
-			shared_ptr<InsetTableCell> t
+			boost::shared_ptr<InsetTableCell> t
 				= cell(tabular.cellIndex(i, j));
 			if (cur.buffer().params().trackChanges)
 				// FIXME: Change tracking (MG)
@@ -5153,7 +5152,7 @@ bool InsetTabular::insertPlaintextString
 		case '\t':
 			// we can only set this if we are not too far right
 			if (cols < columns) {
-				shared_ptr<InsetTableCell> inset = loctab->cellInset(cell);
+				boost::shared_ptr<InsetTableCell> inset = loctab->cellInset(cell);
 				Font const font = bv.textMetrics(&inset->text()).
 					displayFont(0, 0);
 				inset->setText(buf.substr(op, p - op), font,
@@ -5165,7 +5164,7 @@ bool InsetTabular::insertPlaintextString
 		case '\n':
 			// we can only set this if we are not too far right
 			if (cols < columns) {
-				shared_ptr<InsetTableCell> inset = tabular.cellInset(cell);
+				boost::shared_ptr<InsetTableCell> inset = tabular.cellInset(cell);
 				Font const font = bv.textMetrics(&inset->text()).
 					displayFont(0, 0);
 				inset->setText(buf.substr(op, p - op), font,
@@ -5182,7 +5181,7 @@ bool InsetTabular::insertPlaintextString
 	}
 	// check for the last cell if there is no trailing '\n'
 	if (cell < cells && op < len) {
-		shared_ptr<InsetTableCell> inset = loctab->cellInset(cell);
+		boost::shared_ptr<InsetTableCell> inset = loctab->cellInset(cell);
 		Font const font = bv.textMetrics(&inset->text()).displayFont(0, 0);
 		inset->setText(buf.substr(op, len - op), font,
 			buffer().params().trackChanges);
