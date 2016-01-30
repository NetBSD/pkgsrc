# $NetBSD: Makefile,v 1.6 2016/01/30 04:56:44 markd Exp $

DISTNAME=	symbol
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Symbol fonts for TeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb14

TEX_MAP_FILES+=	usy.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
