# $NetBSD: Makefile,v 1.5 2016/06/16 04:05:59 markd Exp $

DISTNAME=	algorithms
PKGNAME=	tex-${DISTNAME}-0.1
TEXLIVE_REV=	38085

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Suite of tools for typesetting algorithms in pseudo-code
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
