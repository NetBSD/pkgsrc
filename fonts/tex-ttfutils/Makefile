# $NetBSD: Makefile,v 1.3 2019/12/06 19:32:29 markd Exp $

DISTNAME=	ttfutils
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	31355

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Data files for TeX Live TTF utilities

DEPENDS+=	ttf2pk>=1.5nb5:../../fonts/ttf2pk
DEPENDS+=	ttfdump>=0.5.5:../../fonts/ttfdump
DEPENDS+=	web2c>=2013:../../print/web2c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
