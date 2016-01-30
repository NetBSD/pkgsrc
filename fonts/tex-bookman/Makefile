# $NetBSD: Makefile,v 1.5 2016/01/30 04:56:41 markd Exp $

DISTNAME=	bookman
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bookman font
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	ubk.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
