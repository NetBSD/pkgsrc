# $NetBSD: Makefile,v 1.13 2020/04/27 03:26:39 markd Exp $

DISTNAME=	l3packages
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	54131

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/l3packages
COMMENT=	High-level LaTeX3 concepts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
