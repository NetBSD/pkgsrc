# $NetBSD: Makefile,v 1.6 2013/11/18 18:21:14 minskim Exp $

DISTNAME=	etex
PKGNAME=	tex-${DISTNAME}-2.1.31600
TEXLIVE_REV=	31600

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX implementation filling the gap between TeX3 and NTS

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
