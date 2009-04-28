# $NetBSD: Makefile,v 1.1.1.1 2009/04/28 01:02:19 minskim Exp $
# TeX Live Revision 7997

DISTNAME=	ams
PKGNAME=	tex-${DISTNAME}-2008.7997

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Essential files for AMS TeX

CONFLICTS+=	teTeX-texmf<=3.0nb13

TEX_MAP_FILES+=		mathpple.map
TEX_MIXEDMAP_FILES+=	ams-bsr-interpolated.map
TEX_MIXEDMAP_FILES+=	ams-bsr.map
TEX_MIXEDMAP_FILES+=	ams-cmcsc-bsr-interpolated.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
