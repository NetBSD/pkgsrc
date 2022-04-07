# $NetBSD: Makefile,v 1.18 2022/04/07 05:19:27 markd Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.66
TEXLIVE_REV=	61954

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/beamer
COMMENT=	LaTeX class for producing presentations and slides
LICENSE=	lppl-1.3c AND gnu-gpl-v2 AND gnu-fdl-v1.3

DEPENDS+=	tex-amscls-[0-9]*:../../print/tex-amscls
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-translator-[0-9]*:../../print/tex-translator
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
