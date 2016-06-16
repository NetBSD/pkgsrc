# $NetBSD: Makefile,v 1.6 2016/06/16 04:03:14 markd Exp $

DISTNAME=	collection-langgerman
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	40098

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	German TeX packages

DEPENDS+=	texlive-collection-basic>=2014:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-german-[0-9]*:../../print/tex-babel-german
DEPENDS+=	tex-bibleref-german-[0-9]*:../../print/tex-bibleref-german
# booktabs-de is documentation only
# csquotes-de is documentation only
DEPENDS+=	tex-dehyph-exptl-[0-9]*:../../print/tex-dehyph-exptl
DEPENDS+=	tex-dhua-[0-9]*:../../print/tex-dhua
# einfuehrung is documentation only
# einfuehrung2 is documentation only
# etdipa is documentation only
# etoolbox-de is documentation only
# fifinddo-info is documentation only
# geometry-de is documentation only
DEPENDS+=	tex-german-[0-9]*:../../print/tex-german
DEPENDS+=	tex-germbib-[0-9]*:../../print/tex-germbib
DEPENDS+=	tex-germkorr-[0-9]*:../../print/tex-germkorr
DEPENDS+=	tex-hausarbeit-jura-[0-9]*:../../print/tex-hausarbeit-jura
DEPENDS+=	tex-hyphen-german-[0-9]*:../../print/tex-hyphen-german
# koma-script-examples is documentation only
# l2picfaq is documentation only
# l2tabu is documentation only
# latex-bib-ex is documentation only
# latex-bib2-ex is documentation only
# latex-referenz is documentation only
# latex-tabellen is documentation only
# latexcheat-de is documentation only
# lshort-german is documentation only
# lualatex-doc-de is documentation only
# microtype-de is documentation only
# presentations is documentation only
# pstricks-examples is documentation only
DEPENDS+=	tex-r_und_s-[0-9]*:../../print/tex-r_und_s
# templates-fenn is documentation only
# templates-sommer is documentation only
# texlive-de is documentation only
# tipa-de is documentation only
# translation-arsclassica-de is documentation only
# translation-biblatex-de is documentation only
# translation-chemsym-de is documentation only
# translation-ecv-de is documentation only
# translation-enumitem-de is documentation only
# translation-europecv-de is documentation only
# translation-filecontents-de is documentation only
# translation-moreverb-de is documentation only
DEPENDS+=	tex-udesoftec-[0-9]*:../../print/tex-udesoftec
# depend uhrzeit
DEPENDS+=	tex-umlaute-[0-9]*:../../print/tex-umlaute
# voss-mathcol is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
