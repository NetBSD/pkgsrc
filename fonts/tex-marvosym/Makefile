# $NetBSD: Makefile,v 1.4 2015/04/25 08:07:19 markd Exp $

DISTNAME=	marvosym
PKGNAME=	tex-${DISTNAME}-2.2a
TEXLIVE_REV=	29349

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Martin Vogel's Symbols font

CONFLICTS+=	teTeX-texmf<=3.0nb13

TEX_MAP_FILES+=	marvosym.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
