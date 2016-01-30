# $NetBSD: Makefile,v 1.4 2016/01/30 04:56:45 markd Exp $

DISTNAME=	zapfchan
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Zapf Chancery fonts
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	uzc.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
