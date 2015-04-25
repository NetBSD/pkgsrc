# $NetBSD: Makefile,v 1.4 2015/04/25 08:22:13 markd Exp $

DISTNAME=	palatino
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Palatino font family for TeX

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	upl.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
