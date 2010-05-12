# $NetBSD: Makefile,v 1.2 2010/05/12 09:30:47 minskim Exp $

DISTNAME=	marvosym
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Martin Vogel's Symbols font

CONFLICTS+=	teTeX-texmf<=3.0nb13

TEX_MAP_FILES+=	marvosym.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
