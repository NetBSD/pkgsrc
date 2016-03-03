$NetBSD: patch-config_DOC__Make.SH,v 1.1 2016/03/03 13:28:22 wiz Exp $

Rules for dvi/ps are broken, just generate PDFs to work around this.

--- config/DOC_Make.SH.orig	2014-07-30 13:38:47.000000000 +0000
+++ config/DOC_Make.SH
@@ -21,7 +21,7 @@ MACROS= paricfg.tex parimacro.tex
 USERS_TEX=\$(MACROS) appa.tex users.tex usersch1.tex usersch2.tex usersch3.tex
 PARI_TEX=\$(MACROS) libpari.tex appb.tex appd.tex usersch4.tex usersch5.tex usersch6.tex usersch7.tex
 
-doc all: develop.dvi libpari.dvi parallel.dvi users.dvi refcard.ps tutorial.dvi
+doc all: develop.pdf libpari.pdf parallel.pdf users.pdf refcard.pdf tutorial.pdf
 docps: develop.ps libpari.ps parallel.ps refcard.ps tutorial.ps users.ps INSTALL.ps
 docpdf: develop.pdf libpari.pdf parallel.pdf users.pdf tutorial.pdf refcard.pdf INSTALL.pdf
 
