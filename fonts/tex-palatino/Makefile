# $NetBSD: Makefile,v 1.5 2016/01/30 04:56:43 markd Exp $

DISTNAME=	palatino
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Palatino font family for TeX
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	upl.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
