# $NetBSD: Makefile,v 1.2 2013/11/17 17:07:05 minskim Exp $

DISTNAME=	ttfutils
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	31355

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Data files for TeX Live TTF utilities

DEPENDS+=	ttf2pk>=1.5nb5:../../fonts/ttf2pk
DEPENDS+=	ttfdump>=0.5.5:../../fonts/ttfdump
DEPENDS+=	web2c>=2013:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
