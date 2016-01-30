# $NetBSD: Makefile,v 1.8 2016/01/30 04:56:42 markd Exp $

DISTNAME=	helvetic
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Adobe Helvetica fonts
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb19

TEX_MAP_FILES+=	uhv.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
