# $NetBSD: Makefile,v 1.3 2016/01/30 04:56:44 markd Exp $

DISTNAME=	pxfonts
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Palatino-like fonts in support of mathematics
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	pxfonts.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
