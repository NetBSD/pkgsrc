# $NetBSD: Makefile,v 1.6 2016/01/30 04:56:45 markd Exp $

DISTNAME=	zapfding
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Dingbat typeface designed by Hermann Zapf
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb14

TEX_MAP_FILES+=	uzd.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
