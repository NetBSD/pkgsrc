# $NetBSD: Makefile,v 1.11 2026/03/29 03:08:00 markd Exp $

DISTNAME=	elsarticle
PKGNAME=	tex-${DISTNAME}-3.5
TEXLIVE_REV=	77318

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/elsarticle
COMMENT=	Class for articles for submission to Elsevier journals
LICENSE=	lppl-1.3c

DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-txfonts-[0-9]*:../../fonts/tex-txfonts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
