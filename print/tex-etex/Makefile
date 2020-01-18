# $NetBSD: Makefile,v 1.10 2020/01/18 23:34:05 rillig Exp $

DISTNAME=	etex
PKGNAME=	tex-${DISTNAME}-2.1.31600
TEXLIVE_REV=	31600

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/etex
COMMENT=	TeX implementation filling the gap between TeX3 and NTS
#LICENSE=	knuth

DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
