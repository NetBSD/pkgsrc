$NetBSD: patch-jade_HtmlFOTBuilder.cxx,v 1.1 2020/03/26 21:47:54 rillig Exp $

HtmlFOTBuilder.cxx: In member function 'void OpenJade_DSSSL::HtmlFOTBuilder::CharStyle::output(OpenSP::OutputCharStream&) const':
HtmlFOTBuilder.cxx:493:59: error: array subscript has type 'char' [-Werror=char-subscripts]
     os << indent << "font-style: " << styleNames[fontStyle] << ';' << RE;
                                                           ^
HtmlFOTBuilder.cxx: In member function 'void OpenJade_DSSSL::HtmlFOTBuilder::ParaStyle::output(OpenSP::OutputCharStream&) const':
HtmlFOTBuilder.cxx:537:55: error: array subscript has type 'char' [-Werror=char-subscripts]
     os << indent << "text-align: " << alignNames[align] << ';' << RE;
                                                       ^

These char variables correspond to the enums that are declared just above of them.

--- jade/HtmlFOTBuilder.cxx.orig	1999-05-02 15:47:07.000000000 +0000
+++ jade/HtmlFOTBuilder.cxx
@@ -55,7 +55,7 @@ public:
     bool operator!=(const CharProps &cp) const { return !(*this == cp); }
     char fontWeight;
     enum { styleNormal, styleItalic, styleOblique };
-    char fontStyle;
+    unsigned char fontStyle;
     unsigned color;
     Length fontSize;
     StringC fontFamily;
@@ -72,7 +72,7 @@ public:
     Length rightMargin;
     Length lineHeight;
     Length textIndent;
-    char align;
+    unsigned char align;
   };
   struct ParaProps : public InheritParaProps {
     ParaProps(const InheritParaProps &props)
