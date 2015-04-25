# $NetBSD: Makefile,v 1.3 2015/04/25 08:39:42 markd Exp $

DISTNAME=	zapfchan
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Zapf Chancery fonts

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	uzc.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
