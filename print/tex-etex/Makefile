# $NetBSD: Makefile,v 1.7 2015/05/05 17:05:03 wiz Exp $

DISTNAME=	etex
PKGNAME=	tex-${DISTNAME}-2.1.31600
TEXLIVE_REV=	31600

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etex
COMMENT=	TeX implementation filling the gap between TeX3 and NTS
#LICENSE=	knuth

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
