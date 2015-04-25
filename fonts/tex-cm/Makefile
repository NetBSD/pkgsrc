# $NetBSD: Makefile,v 1.7 2015/04/25 07:50:27 markd Exp $

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2014
CATEGORIES=	fonts
TEXLIVE_REV=	32865

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Computer Modern fonts

CONFLICTS+=	teTeX-texmf<=3.0nb11

TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
