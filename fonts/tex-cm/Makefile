# $NetBSD: Makefile,v 1.8 2015/05/05 16:44:41 wiz Exp $

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2014
CATEGORIES=	fonts
TEXLIVE_REV=	32865

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cm
COMMENT=	Computer Modern fonts
#LICENSE=	knuth

CONFLICTS+=	teTeX-texmf<=3.0nb11

TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
