# $NetBSD: Makefile,v 1.2 2015/05/09 23:31:53 markd Exp $

DISTNAME=	collection-langgerman
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	36284

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	German TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-german-[0-9]*:../../print/tex-babel-german
# depend bibleref-german
# depend booktabs-de
# depend csquotes-de
DEPENDS+=	tex-dehyph-exptl-[0-9]*:../../print/tex-dehyph-exptl
# depend dhua
# depend einfuehrung
# depend etdipa
# depend etoolbox-de
# depend fifinddo-info
# depend geometry-de
DEPENDS+=	tex-german-[0-9]*:../../print/tex-german
DEPENDS+=	tex-germbib-[0-9]*:../../print/tex-germbib
# depend germkorr
# depend hausarbeit-jura
DEPENDS+=	tex-hyphen-german-[0-9]*:../../print/tex-hyphen-german
# depend koma-script-examples
# depend l2picfaq
# depend l2tabu
# depend latex-bib-ex
# depend latex-referenz
# depend latex-tabellen
# depend latexcheat-de
# lshort-german is documentation only
# depend lualatex-doc-de
# depend microtype-de
# depend presentations
# depend pstricks-examples
# depend r_und_s
# depend templates-fenn
# depend templates-sommer
# depend texlive-de
# depend tipa-de
# depend translation-arsclassica-de
# depend translation-biblatex-de
# depend translation-chemsym-de
# depend translation-ecv-de
# depend translation-enumitem-de
# depend translation-europecv-de
# depend translation-filecontents-de
# depend translation-moreverb-de
# depend udesoftec
DEPENDS+=	tex-umlaute-[0-9]*:../../print/tex-umlaute
# depend voss-mathcol

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
