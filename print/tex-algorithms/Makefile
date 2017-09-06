# $NetBSD: Makefile,v 1.6 2017/09/06 16:49:30 wiz Exp $

DISTNAME=	algorithms
PKGNAME=	tex-${DISTNAME}-0.1
TEXLIVE_REV=	38085

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Suite of tools for typesetting algorithms in pseudo-code
LICENSE=	gnu-lgpl-v2

DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
