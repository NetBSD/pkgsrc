# $NetBSD: Makefile,v 1.5 2011/12/11 19:52:31 minskim Exp $

DISTNAME=	etex
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	22198

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX implementation filling the gap between TeX3 and NTS

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
