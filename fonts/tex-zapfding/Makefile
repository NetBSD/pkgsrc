# $NetBSD: Makefile,v 1.5 2015/04/25 08:43:35 markd Exp $

DISTNAME=	zapfding
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Dingbat typeface designed by Hermann Zapf

CONFLICTS+=	teTeX-texmf<=3.0nb14

TEX_MAP_FILES+=	uzd.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
