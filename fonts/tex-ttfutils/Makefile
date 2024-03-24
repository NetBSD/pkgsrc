# $NetBSD: Makefile,v 1.4 2024/03/24 10:59:42 markd Exp $

DISTNAME=	ttfutils
PKGNAME=	tex-${DISTNAME}-2024
TEXLIVE_REV=	70015

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Data files for TeX Live TTF utilities

DEPENDS+=	ttf2pk>=1.5nb5:../../fonts/ttf2pk
DEPENDS+=	ttfdump>=0.5.5:../../fonts/ttfdump
DEPENDS+=	web2c>=2013:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
