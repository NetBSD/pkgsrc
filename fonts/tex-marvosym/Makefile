# $NetBSD: Makefile,v 1.3 2011/11/06 08:43:30 minskim Exp $

DISTNAME=	marvosym
PKGNAME=	tex-${DISTNAME}-2.1
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Martin Vogel's Symbols font

CONFLICTS+=	teTeX-texmf<=3.0nb13

TEX_MAP_FILES+=	marvosym.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
