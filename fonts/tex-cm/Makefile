# $NetBSD: Makefile,v 1.5 2012/10/10 19:31:58 minskim Exp $

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2012
CATEGORIES=	fonts
TEXLIVE_REV=	24956

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Computer Modern fonts

CONFLICTS+=	teTeX-texmf<=3.0nb11

TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
