# $NetBSD: Makefile,v 1.4 2015/04/25 07:48:18 markd Exp $

DISTNAME=	bookman
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bookman font

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	ubk.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
