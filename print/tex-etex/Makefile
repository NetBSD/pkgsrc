# $NetBSD: Makefile,v 1.8 2017/09/06 16:49:34 wiz Exp $

DISTNAME=	etex
PKGNAME=	tex-${DISTNAME}-2.1.31600
TEXLIVE_REV=	31600

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etex
COMMENT=	TeX implementation filling the gap between TeX3 and NTS
#LICENSE=	knuth

DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
