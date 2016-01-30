# $NetBSD: Makefile,v 1.5 2016/01/30 04:56:43 markd Exp $

DISTNAME=	marvosym
PKGNAME=	tex-${DISTNAME}-2.2a
TEXLIVE_REV=	29349

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Martin Vogel's Symbols font
LICENSE=	ofl-v1.1

CONFLICTS+=	teTeX-texmf<=3.0nb13

TEX_MAP_FILES+=	marvosym.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
