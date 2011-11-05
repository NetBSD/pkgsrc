# $NetBSD: Makefile,v 1.1.1.1 2011/11/05 15:59:30 minskim Exp $

DISTNAME=	l3packages
PKGNAME=	tex-${DISTNAME}-0.2900
TEXLIVE_REV=	24257

MAINTAINER=	minskim@NetBSD.org
COMMENT=	High-level LaTeX3 concepts

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
