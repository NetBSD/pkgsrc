# $NetBSD: Makefile,v 1.3 2016/06/16 12:37:54 wiz Exp $

DISTNAME=	collection-latex-doc
PKGNAME=	texlive-${DISTNAME}-2010
CATEGORIES=	meta-pkgs
TEXLIVE_REV=	18674
MASTER_SITES=	# empty

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Documentation for texlive-collection-latex

DEPENDS+=	texlive-collection-basic-doc>=2010:../../meta-pkgs/texlive-collection-basic-doc

DEPENDS+=	tex-ae-doc>=1.4:../../fonts/tex-ae-doc
DEPENDS+=	tex-amscls-doc>=2010.20248:../../print/tex-amscls-doc
DEPENDS+=	tex-amsmath-doc>=2.13nb1:../../print/tex-amsmath-doc
DEPENDS+=	tex-babel-doc>=3.8l:../../print/tex-babel-doc
DEPENDS+=	tex-babelbib-doc>=1.29:../../print/tex-babelbib-doc
DEPENDS+=	tex-carlisle-doc>=2010:../../print/tex-carlisle-doc
DEPENDS+=	tex-colortbl-doc>=0.1:../../print/tex-colortbl-doc
DEPENDS+=	tex-fancyhdr-doc>=3.1:../../print/tex-fancyhdr-doc
DEPENDS+=	tex-fix2col-doc>=0.04<2000:../../print/tex-fix2col-doc
DEPENDS+=	tex-geometry-doc>=5.6:../../print/tex-geometry-doc
DEPENDS+=	tex-graphics-doc>=1.0onb1:../../print/tex-graphics-doc
DEPENDS+=	tex-hyperref-doc>=6.81p:../../print/tex-hyperref-doc
DEPENDS+=	tex-latex-doc>=2010:../../print/tex-latex-doc
DEPENDS+=	tex-latex-bin-doc>=2010:../../print/tex-latex-bin-doc
# tex-latex-fonts doesn't have a documentation package.
# tex-latexconfig doesn't have a documentation package.
# tex-ltxmisc doesn't have a documentation package.
DEPENDS+=	tex-mfnfss-doc>=2009:../../print/tex-mfnfss-doc
DEPENDS+=	tex-mptopdf-doc>=2010:../../graphics/tex-mptopdf-doc
DEPENDS+=	tex-natbib-doc>=8.31b:../../print/tex-natbib-doc
DEPENDS+=	tex-oberdiek-doc>=2009nb1:../../print/tex-oberdiek-doc
# tex-pdftex-def doesn't have a documentation package.
# tex-pslatex doesn't have a documentation package.
DEPENDS+=	tex-psnfss-doc>=9.2a:../../fonts/tex-psnfss-doc
DEPENDS+=	tex-pspicture-doc>=2009:../../print/tex-pspicture-doc
DEPENDS+=	tex-tools-doc>=2009:../../print/tex-tools-doc

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
