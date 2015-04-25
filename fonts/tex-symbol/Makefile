# $NetBSD: Makefile,v 1.5 2015/04/25 08:27:13 markd Exp $

DISTNAME=	symbol
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Symbol fonts for TeX

CONFLICTS+=	teTeX-texmf<=3.0nb14

TEX_MAP_FILES+=	usy.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
