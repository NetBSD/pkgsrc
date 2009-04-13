# $NetBSD: Makefile,v 1.1.1.1 2009/04/13 07:05:41 minskim Exp $
# TeX Live Revision 7621

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2008.7621
CATEGORIES=	fonts

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Computer Modern fonts

CONFLICTS+=	teTeX-texmf<=3.0nb11

TEX_MIXEDMAP_FILES+=	cmother-bsr.map
TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map
TEX_MIXEDMAP_FILES+=	cmtext-bsr.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
