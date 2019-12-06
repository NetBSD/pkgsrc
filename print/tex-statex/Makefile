# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:20 markd Exp $

DISTNAME=	statex
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	20306

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Statistics style
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
