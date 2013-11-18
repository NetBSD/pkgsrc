# $NetBSD: Makefile,v 1.6 2013/11/18 18:05:13 minskim Exp $

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2013
CATEGORIES=	fonts
TEXLIVE_REV=	29581

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Computer Modern fonts

CONFLICTS+=	teTeX-texmf<=3.0nb11

TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
