# $NetBSD: Makefile,v 1.5 2016/01/30 04:56:43 markd Exp $

DISTNAME=	ncntrsbk
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	New Century Schoolbook fonts
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MAP_FILES+=	unc.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
