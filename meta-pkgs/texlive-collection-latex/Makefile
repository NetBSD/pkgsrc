# $NetBSD: Makefile,v 1.4 2016/06/16 12:37:54 wiz Exp $

DISTNAME=	collection-latex
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
TEXLIVE_REV=	41011
MASTER_SITES=	# empty

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Basic LaTeX packages

DEPENDS+=	texlive-collection-basic>=2010:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-ae>=1.4:../../fonts/tex-ae
DEPENDS+=	tex-amscls>=2010.20248:../../print/tex-amscls
DEPENDS+=	tex-amsmath>=2.13nb1:../../print/tex-amsmath
DEPENDS+=	tex-babel>=3.8lnb2:../../print/tex-babel
DEPENDS+=	tex-babel-english>=3.3p:../../print/tex-babel-english
DEPENDS+=	tex-babelbib>=1.29:../../print/tex-babelbib
DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-colortbl>=0.1nb1:../../print/tex-colortbl
# depend dvisvgm-def
DEPENDS+=	tex-fancyhdr>=3.1nb1:../../print/tex-fancyhdr
DEPENDS+=	tex-fix2col>=0.04<2000:../../print/tex-fix2col
DEPENDS+=	tex-geometry>=5.6:../../print/tex-geometry
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
# depend graphics-cfg
DEPENDS+=	tex-hyperref>=6.81pnb3:../../print/tex-hyperref
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-latex-fonts>=2009:../../fonts/tex-latex-fonts
DEPENDS+=	tex-latexconfig>=2010.20663:../../print/tex-latexconfig
DEPENDS+=	tex-ltxmisc>=2010:../../print/tex-ltxmisc
DEPENDS+=	tex-mfnfss>=2009:../../print/tex-mfnfss
DEPENDS+=	tex-mptopdf>=2010:../../graphics/tex-mptopdf
DEPENDS+=	tex-natbib>=8.31b:../../print/tex-natbib
DEPENDS+=	tex-oberdiek>=2009nb2:../../print/tex-oberdiek
DEPENDS+=	tex-pdftex-def>=0.04m:../../print/tex-pdftex-def
DEPENDS+=	tex-pslatex>=2009:../../print/tex-pslatex
DEPENDS+=	tex-psnfss>=9.2anb1:../../fonts/tex-psnfss
DEPENDS+=	tex-pspicture>=2009:../../print/tex-pspicture
DEPENDS+=	tex-tools>=2009:../../print/tex-tools
DEPENDS+=	tex-url>=3.4:../../print/tex-url

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
