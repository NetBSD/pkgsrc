# $NetBSD: Makefile,v 1.11 2026/03/29 10:36:34 markd Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-6.0
TEXLIVE_REV=	78315

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/geometry
COMMENT=	Flexible and complete interface to document dimensions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
