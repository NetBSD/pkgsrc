$NetBSD: patch-config_DOC__Make.SH,v 1.2 2022/10/30 10:00:15 nros Exp $

Rules for dvi/ps are broken, just generate PDFs to work around this.

--- config/DOC_Make.SH.orig	2022-09-16 17:16:27.000000000 +0000
+++ config/DOC_Make.SH
@@ -42,7 +42,7 @@ MACROS= paricfg.tex parimacro.tex
 USERS_TEX=\$(MACROS) users.tex usersch1.tex usersch2.tex usersch3.tex
 PARI_TEX=\$(MACROS) libpari.tex appb.tex appd.tex usersch4.tex usersch5.tex usersch6.tex usersch7.tex usersch8.tex
 
-doc all: $outdvi
+doc all: docpdf
 docpdf: $outpdf
 
 .SUFFIXES: .tex .ipf .pod .inf .dumbpod .3 .html
