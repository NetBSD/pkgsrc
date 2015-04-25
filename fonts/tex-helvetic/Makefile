# $NetBSD: Makefile,v 1.7 2015/04/25 07:56:24 markd Exp $

DISTNAME=	helvetic
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Adobe Helvetica fonts

CONFLICTS+=	teTeX-texmf<=3.0nb19

TEX_MAP_FILES+=	uhv.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
