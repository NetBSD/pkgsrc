# $NetBSD: Makefile,v 1.8 2018/05/12 03:18:20 markd Exp $

DISTNAME=	l3packages
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	46712

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/l3packages
COMMENT=	High-level LaTeX3 concepts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
